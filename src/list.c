/**
 * @file list.c
 * @author longhsu91
 * @brief 
 * @version 0.1
 * @date 2018-11-22
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static PListNode list_create_mode(int val);

/**
 * @brief 
 * 
 * @param arr 
 * @param size 
 * @return PListNode 
 */
PListNode list_create(int *arr, int size)
{
    assert(arr != NULL);
    assert(size > 0);

    PListNode head = NULL;
    PListNode curr = NULL;
    PListNode new_node = NULL;

    for (int i = 0; i < size; i++)
    {
        new_node = list_create_mode(arr[i]);
        if (new_node == NULL)
        {
            goto ERROR;
        }

        if (i == 0)
        {
            head = new_node;
            curr = head;
        }
        else
        {
            curr->next = new_node;
            curr = new_node;
        }
    }

    return head;

ERROR:

    list_free(head);

    return NULL;
}

/**
 * @brief 
 * 
 * @param head 
 */
void list_free(PListNode head)
{
    while (head != NULL)
    {
        free(head);
        head = head->next;
    }
}

/**
 * @brief 
 * 
 * @param ppHead 
 * @param val 
 */
void list_add(PPListNode ppHead, int val)
{
    int size = list_size(*ppHead);
    list_insert(ppHead, size, val);
}

/**
 * @brief 
 * 
 * @param ppHead 
 */
void list_remove(PPListNode ppHead)
{
    int size = list_size(*ppHead);
    list_delete(ppHead, size - 1);
}

/**
 * @brief 
 * 
 * @param ppHead 
 * @param k 
 * @param val 
 */
void list_insert(PPListNode ppHead, int k, int val)
{
    assert(ppHead != NULL);
    PListNode head = *ppHead;

    int size = list_size(head);
    assert(k >= 0);
    assert(k <= size);

    PListNode new_node = list_create_mode(val);
    if (new_node == NULL)
    {
        return;
    }

    // fisrt node
    if (k == 0)
    {
        new_node->next = head;
        *ppHead = new_node;
        return;
    }

    PListNode pre = NULL;
    PListNode curr = head;

    while (curr != NULL && k-- > 0)
    {
        pre = curr;
        curr = curr->next;
    }

    pre->next = new_node;
    new_node->next = curr;
}

/**
 * @brief 
 * 
 * @param ppHead 
 * @param k 
 */
void list_delete(PPListNode ppHead, int k)
{
    assert(ppHead != NULL);
    PListNode head = *ppHead;

    int size = list_size(head);
    assert(k >= 0);
    assert(k <= size - 1);

    // first node
    if (k == 0)
    {
        *ppHead = head->next;
        free(head);
        return;
    }

    PListNode pre = NULL;
    PListNode curr = head;

    while (curr != NULL && k-- > 0)
    {
        pre = curr;
        curr = curr->next;
    }

    pre->next = curr->next;
    free(curr);
}

/**
 * @brief 
 * 
 * @param ppHead 
 */
void list_reverse(PPListNode ppHead)
{
    assert(ppHead != NULL);

    PListNode head = *ppHead;

    PListNode curr = head;
    PListNode pre = NULL;
    PListNode after = NULL;

    while (curr != NULL)
    {
        after = curr->next;
        curr->next = pre;
        pre = curr;

        curr = after;
    }

    *ppHead = pre;
}

/**
 * @brief 
 * 
 * @param head 
 */
void list_print(PListNode head)
{
    int size = list_size(head);
    printf("[%d]", size);

    printf("[");
    while (head != NULL)
    {
        // last node
        if (head->next == NULL)
        {
            printf("%d", head->val);
        }
        else
        {
            printf("%d ", head->val);
        }

        head = head->next;
    }
    printf("]\n");
}

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 */
int list_size(PListNode head)
{
    int size = 0;
    while (head != NULL)
    {
        head = head->next;
        size++;
    }

    return size;
}

/**
 * @brief 
 * 
 * @param val 
 * @return PListNode 
 */
static PListNode list_create_mode(int val)
{
    PListNode node = (PListNode)malloc(sizeof(struct ListNode));
    if (node == NULL)
    {
        return NULL;
    }
    node->val = val;
    node->next = NULL;

    return node;
}