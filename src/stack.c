#include "stack.h"

#include "type.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @brief 
 * 
 * @param size 
 * @return struct Stack* 
 */
struct Stack *constructor(int size)
{
    if (size <= 0 || size > MAX_STACK_SIZE)
    {
        return NULL;
    }

    struct Stack *stack = NULL;
    stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (stack == NULL)
    {
        return NULL;
    }

    Object *object = NULL;
    object = (Object *)malloc(sizeof(Object) * size);
    if (object == NULL)
    {
        return NULL;
    }

    stack->_this = stack;
    stack->bottom = object;
    stack->top = object;
    stack->size = size;

    stack->push = push;
    stack->pop = pop;
    stack->is_empty = is_empty;
    stack->is_full = is_full;
    stack->print = print;
    stack->destructor = destructor;

    return stack;
}

/**
 * @brief
 * 
 * @param stack 
 * @return int 
 */
int destructor(struct Stack *stack)
{
    //printf("%p, %p\n", stack, stack->_this);

    assert(stack != NULL);

    if (stack->_this != NULL)
    {
        if (stack->_this->bottom != NULL)
        {
            free(stack->_this->bottom);
            stack->_this->bottom = NULL;
        }

        free(stack->_this);
        stack->_this = NULL;
    }

    return 0;
}

/**
 * @brief 
 * 
 * @param stack 
 * @param val 
 * @return int 
 */
int push(struct Stack *stack, Object val)
{
    assert(stack != NULL);

    struct Stack *this = stack->_this;
    if (is_full(stack))
    {
        printf("realloc size %d.\n", EXTERN_SIZE);
        this->bottom = (Object *)realloc(this->bottom, sizeof(Object) * (this->size + EXTERN_SIZE));
        if (this->bottom == NULL)
        {
            return -1;
        }

        // reasgin
        this->top = this->bottom + this->size;
        this->size += EXTERN_SIZE;
    }

    (*this->top) = val; // not this->top = &val;
    this->top++;        // next

    //printf("%p, %p\n", this->bottom, this->top);

    return 0;
}

/**
 * @brief 
 * 
 * @param stack 
 * @return int 
 */
int pop(struct Stack *stack)
{
    assert(stack != NULL);

    if (is_empty(stack))
    {
        return -1;
    }

    struct Stack *this = stack->_this;

    this->top--;
    Object res = *(this->top);

    //printf("%p, %p\n", this->bottom, this->top);

    return 0;
}

/**
 * @brief 
 * 
 * @param stack 
 * @return int 
 */
int is_empty(struct Stack *stack)
{
    assert(stack != NULL);

    struct Stack *this = stack->_this;

    if (this->top == this->bottom)
    {
        printf("stack is empty.\n");
        return true;
    }

    return false;
}

/**
 * @brief 
 * 
 * @param stack 
 * @return int 
 */
int is_full(struct Stack *stack)
{
    assert(stack != NULL);

    struct Stack *this = stack->_this;
    if (this->top == this->bottom + this->size)
    {
        printf("stack is full.\n");
        return true;
    }

    return false;
}

/**
 * @brief 
 * 
 * @param stack 
 * @return int 
 */
int print(struct Stack *stack)
{
    assert(stack != NULL);

    struct Stack *this = stack->_this;
    printf("Stack:[");
    Object *object;
    for (object = this->bottom; object != this->top; object++)
    {
        if (object == this->top - 1)
        {
            printf("%d", *object);
            break;
        }
        printf("%d ", *object);
    }

    printf("]\n");

    return 0;
}