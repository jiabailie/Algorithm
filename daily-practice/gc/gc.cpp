/**
 * Implement a simple garbage collector.
 * Reference: journal.stuffwithstuff.com/2013/12/08/babys-first-garbage-collector/
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cassert>
#include "gc.h"

/* Initialize a mini-size virtual machine. */
VM* newVM()
{
    VM *vm = (VM*)malloc(sizeof(VM));

    vm->stackSize = 0;
    vm->firstObject = 0;

    vm->numObjects = 0;
    vm->maxObjects = INITIAL_GC_THRESHOLD;

    return vm;
}

/* Push a variable into vm's stack. */
void push(bool test, VM *vm, Object *value)
{
    if(test)
    {
        assert(vm->stackSize < STACK_MAX, "Stack overflow!");
    }

    if(vm->stackSize >= STACK_MAX)
    {
        gc(vm);
        push(!test, vm, value);

        return;
    }    

    vm->stack[vm->stackSize] = value;
    vm->stackSize += 1;
}

/* Pop out a variable from vm's stack. */
Object* pop(VM *vm)
{
    assert(vm->stackSize > 0, "Stack underflow!");

    vm->stackSize -= 1;
    return vm->stack[vm->stackSize];
}

/* Create some objects which will be save in the vm's stack. */
Object* newObject(VM *vm, ObjectType type)
{
    if(vm->numObjects == vm->maxObjects)
    {
        gc(vm);
    }

    Object *object = (Object*)malloc(sizeof(Object));
    object->type = type;
    object->marked = 0;

    object->next = vm->firstObject;
    vm->firstObject = object;
    vm->numObjects += 1;

    return object;
}

void pushInt(VM *vm, int intValue)
{
    Object* object = newObject(vm, OBJ_INT);
    object->value = intValue;

    push(0, vm, object);
}

Object* pushPair(VM *vm)
{
    Object *object = newObject(vm, OBJ_PAIR);
    object->tail = pop(vm);
    object->head = pop(vm);

    push(0, vm, object);
    return object;
}

/* Mark an object which is used or referenced by an existing variable. */
void mark(Object *object)
{
    if(object->marked)
    {
        return;
    }

    object->marked = 1;

    if(object->type == OBJ_PAIR)
    {
        mark(object->head);
        mark(object->tail);
    }
}

/* Mark all variables in the vm's stack one by one. */
void markAll(VM *vm)
{
    for(int i = 0; i < vm->stackSize; ++i)
    {
        mark(vm->stack[i]);
    }
}

void sweep(VM *vm)
{
    Object *unreached = 0;
    Object **object = &vm->firstObject;

    if(!(*object))
    {
        return;
    }

    /* Sweep from the linklist head. */
    while(!(*object)->marked)
    {
        // This object wasn't reached, so remove it from the list and free it
        unreached = *object;
        *object = unreached->next;
        free(unreached);

        vm->numObjects -= 1;

        unreached = 0;
        if(!(*object))
        {
            break;
        }
    }

    while((*object) && (*object)->next)
    {
        if(!(*object)->next->marked)
        {
            unreached = (*object)->next;
            (*object)->next = unreached->next;
            *object = unreached->next;
            free(unreached);

            vm->numObjects -= 1;

            unreached = 0;
        }
        else
        {
            (*object)->marked = 0;
            *object = (*object)->next;
        }
    }
}

void gc(VM *vm)
{
    std::cout << "Do garbage collection..." << std::endl;
    std::cout << "Currently, there are " << vm->numObjects << " objects in the stack."<< std::endl;

    int numberObjects = vm->numObjects;

    markAll(vm);
    sweep(vm);

    vm->maxObjects = numberObjects << 1;

    std::cout << "Garbage collection completed." << std::endl;
    std::cout << "Currently, there are " << vm->numObjects << " objects in the stack."<< std::endl;
}

int main()
{
    VM *vm = newVM();

    for(int i = 0; i < 500; ++i)
    {
        Object *object = newObject(vm, OBJ_INT);
        pushInt(vm, i);
        if(i & 1)
        {
            pop(vm);
        }
    }
    return 0;
}
