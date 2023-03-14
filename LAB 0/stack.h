#ifndef STACK_H
#define STACK_H

typedef union
{
    int i;
    float f;
    char c;
    int *p;
} selement;

typedef enum
{
    INT,
    FLOAT,
    CHAR,
    PTR,
} stype;

typedef struct
{
    selement *elements;
    stype type;
    int pos;
    int size;
} mystack;

void create_stack(mystack *stack, stype type, int size);
void push(mystack *stack, selement element);
void push(mystack *stack, int x);
void push(mystack *stack, float x);
void push(mystack *stack, char x);
void push(mystack *stack, int *x);
selement pop(mystack *stack);
bool empty(mystack *stack);
bool full(mystack *stack);

#endif
