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
void push(VM *vm, Object *value)
{
    assert(vm->stackSize < STACK_MAX, "Stack overflow!");

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

    push(vm, object);
}

Object* pushPair(VM *vm)
{
    Object *object = newObject(vm, OBJ_PAIR);
    object->tail = pop(vm);
    object->head = pop(vm);

    push(vm, object);
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

    /* Sweep from the linklist head. */
    while(!(*object)->marked)
    {
        // This object wasn't reached, so remove it from the list and free it
        unreached = *object;
        *object = unreached->next;
        free(unreached);

        vm->numObjects -= 1;

        unreached = 0;
    }

    while(*object)
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
    int numberObjects = vm->numObjects;

    markAll(vm);
    sweep(vm);

    vm->maxObjects = numberObjects << 1;
}

int main()
{
    std::cout << sizeof(ObjectType) << std::endl;
    std::cout << sizeof(Object) << std::endl;
    return 0;
}