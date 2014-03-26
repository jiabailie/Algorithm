#ifndef __GC_H
#define __GC_H

/* The maximum stack size. */
const int STACK_MAX = 1024;

/* The maximum test times. */
const int TEST_MAX = 10;

/* The initial threshold to do gc. */
const int INITIAL_GC_THRESHOLD = 200;

typedef enum
{
    OBJ_INT,
    OBJ_PAIR
} ObjectType;

struct Object
{
    Object *next;

    unsigned char marked;

    ObjectType type;

    union
    {
        int value;

        struct
        {
            Object *head;
            Object *tail;
        };
    };
};

/* This struct will simulate a virtual machine. */
struct VM
{
    int stackSize;

    // The total number of currently allocated objects.
    int numObjects;

    // The number of objects required to trigger a gc.
    int maxObjects;

    Object *firstObject;

    Object *stack[STACK_MAX];
};

/* Initialize a mini-size virtual machine. */
VM* newVM();

/* Push a variable into vm's stack. */
void push(int, VM*, Object*);

/* Pop out a variable from vm's stack. */
Object* pop(VM*);

/* Create some objects which will be save in the vm's stack. */
Object* newObject(VM*, ObjectType);

void pushInt(VM*, int);

Object* pushPair(VM*);

/* Mark an object which is used or referenced by an existing variable. */
void mark(Object*);

/* Mark all variables in the vm's stack one by one. */
void markAll(VM*);

void sweep(VM*);

void gc(VM*);

#endif
