#include <iostream>
#include "stack.h"

using namespace std;

void create_stack(mystack *stack, stype type, int size)
{
    stack->elements = new selement[size];
    stack->pos = -1;
    stack->size = size;
    stack->type = type;
}

void push(mystack *stack, selement element)
{
    if (full(stack))
    {
        cout << "Error: stack is full" << endl;
        return;
    }
    stack->pos++;
    stack->elements[stack->pos] = element;
}

void push(mystack *stack, int x)
{
    if (full(stack))
    {
        cout << "Error: stack is full" << endl;
        return;
    }
    if (stack->type != INT)
    {
        cout << "Wrong data type" << endl;
        exit(1);
    }
    selement sx;
    sx.i = x;
    stack->pos++;
    stack->elements[stack->pos] = sx;
};

void push(mystack *stack, float x)
{
    if (full(stack))
    {
        cout << "Error: stack is full" << endl;
        return;
    }
    if (stack->type != FLOAT)
    {
        cout << "Wrong data type" << endl;
        exit(1);
    }
    selement sx;
    sx.f = x;
    stack->pos++;
    stack->elements[stack->pos] = sx;
};

void push(mystack *stack, char x)
{
    if (full(stack))
    {
        cout << "Error: stack is full" << endl;
        return;
    }
    if (stack->type != CHAR)
    {
        cout << "Wrong data type" << endl;
        exit(1);
    }
    selement sx;
    sx.c = x;
    stack->pos++;
    stack->elements[stack->pos] = sx;
};
void push(mystack *stack, int *x)
{
    if (full(stack))
    {
        cout << "Error: stack is full" << endl;
        return;
    }
    if (stack->type != PTR)
    {
        cout << "Wrong data type" << endl;
        exit(1);
    }
    selement sx;
    sx.p = x;
    stack->pos++;
    stack->elements[stack->pos] = sx;
};

selement pop(mystack *stack)
{
    if (empty(stack))
    {
        cout << "Error: stack is empty" << endl;
        exit(1);
    }
    stack->pos--;
    return stack->elements[stack->pos + 1];
}

bool empty(mystack *stack)
{
    if (stack->pos == -1)
        return true;
    else
        return false;
}

bool full(mystack *stack)
{
    if (stack->pos == stack->size - 1)
        return true;
    else
        return false;
}
