#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    mystack *s = new mystack();
    create_stack(s, INT, 100);
    push(s, 80085);
    selement x;
    x = pop(s);
    cout << x.i << endl;

    s->type = CHAR;
    push(s, 'a');
    push(s, 'b');
    x = pop(s);
    cout << x.c << endl;
    x = pop(s);
    cout << x.c << endl;
    push(s, 's');
    cout << pop(s).c << endl;

    push(s, 1); // this will give a wrong data type error
    return 0;
}