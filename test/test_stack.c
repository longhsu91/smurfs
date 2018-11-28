
#include "stack.h"
#include "config.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    fprintf(stdout, "Smurfs Version %d.%d\n", Smurfs_VERSION_MAJOR, Smurfs_VERSION_MINOR);

    struct Stack *stack = NULL;
    stack = constructor(2);
    stack->is_empty(stack);
    stack->is_full(stack);

    stack->push(stack, 1);
    stack->print(stack);
    stack->push(stack, 2);
    stack->print(stack);
    stack->push(stack, 3);
    stack->print(stack);
    stack->pop(stack);
    stack->print(stack);

    stack->destructor(stack);

    return 0;
}