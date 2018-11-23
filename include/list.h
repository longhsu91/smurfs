/**
 * @file list.h
 * @author longhsu91
 * @brief 
 * @version 0.1
 * @date 2018-11-22
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef LIST_H
#define LIST_H

struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode *PListNode;
typedef struct ListNode **PPListNode;

/**
 * @brief 
 * 
 * @param arr 
 * @param size 
 * @return PListNode 
 */
PListNode list_create(int *arr, int size);

/**
 * @brief 
 * 
 * @param head 
 */
void list_free(PListNode head);

/**
 * @brief add val to tail
 * 
 * @param ppHead 
 * @param val 
 */
void list_add(PPListNode ppHead, int val);

/**
 * @brief remove tail val
 * 
 * @param ppHead 
 */
void list_remove(PPListNode ppHead);

/**
 * @brief 
 * 
 * @param ppHead 
 * @param k [0, size]
 * @param val 
 */
void list_insert(PPListNode ppHead, int k, int val);

/**
 * @brief 
 * 
 * @param ppHead [0, size)
 * @param k 
 */
void list_delete(PPListNode ppHead, int k);

/**
 * @brief 
 * 
 * @param ppHead 
 */
void list_reverse(PPListNode ppHead);

/**
 * @brief 
 * 
 * @param head 
 */
void list_print(PListNode head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 */
int list_size(PListNode head);

#endif