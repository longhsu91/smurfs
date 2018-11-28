/**
 * @file stack.h
 * @author longhsu91
 * @brief 
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 10
#define EXTERN_SIZE 5

typedef int Object;

struct Stack;

typedef int (*PPush_t)(struct Stack *stack, Object val);
typedef int (*PPop_t)(struct Stack *stack);
typedef int (*PIsEmpty_t)(struct Stack *stack);
typedef int (*PIsFull_t)(struct Stack *stack);
typedef int (*PPrint_t)(struct Stack *stack);
typedef int (*PDestructor_t)(struct Stack *stack);

struct Stack
{
    struct Stack *_this; /* formal arg can not change val of real arg, here we use this */

    // field
    Object *bottom; /* point to bottom of stack val*/
    Object *top;    /* point to top of stack val */
    int size;       /* stack size*/

    // method
    PPush_t push;
    PPop_t pop;
    PIsEmpty_t is_empty;
    PIsFull_t is_full;
    PPrint_t print;
    PDestructor_t destructor;
};

/**
 * @brief 
 * 
 * @param size 
 * @return struct Stack* 
 */
extern struct Stack *constructor(int size);

/**
 * @brief 
 * 
 * @param stack 
 * @return int 
 */
extern int destructor(struct Stack *stack);

/**
 * @brief 
 * 
 * @param stack 
 * @param val 
 * @return int 
 */
extern int push(struct Stack *stack, Object val);

/**
 * @brief 
 * 
 * @param stack 
 * @return int 
 */
extern int pop(struct Stack *stack);

/**
 * @brief 
 * 
 * @param stack 
 * @return int 
 */
extern int is_empty(struct Stack *stack);

/**
 * @brief 
 * 
 * @param stack 
 * @return int 
 */
extern int is_full(struct Stack *stack);

/**
 * @brief 
 * 
 * @param stack 
 * @return int 
 */
extern int print(struct Stack *stack);

#endif