#include "list.h"

#include <stdio.h>
#include <stdlib.h>

typedef void (*PPush_t)(struct TopK *this, int num);
typedef void (*PPrint_t)(struct TopK *this);
typedef void (*PMfree_t)(struct TopK **this);

struct TopK
{
    int index; //index in arr
    int size;  //number size
    int min;   //min in arr
    int *arr;

    PPush_t push;
    PPrint_t print;
    PMfree_t mfree;
};

int exist(int *num, int n, int k)
{
    int begin = 0;
    int end = n;
    int mid = 0;

    for (int i = 0; i <= n; i++)
    {
        if (num[i] == k)
        {
            return 1;
        }
    }

    return 0;
}

void push(struct TopK *this, int num)
{
    // not full
    if (this->index < this->size - 1)
    {
        // not exist
        if (!exist(this->arr, this->index, num))
        {
            // add num
            this->arr[++(this->index)] = num;
            if (this->min > num)
            {
                this->min = num;
            }
        }

        return;
    }

    if (num <= this->min || exist(this->arr, this->index, num))
    {
        return;
    }

    // big one and not exist
    // get min
    int min = 0x7FFF;
    for (int i = 0; i <= this->index; i++)
    {
        if (this->arr[i] == this->min)
        {
            this->arr[i] = num;
        }

        if (min > this->arr[i])
        {
            min = this->arr[i];
        }
    }

    this->min = min;
}

void print(struct TopK *this)
{
    printf("[");
    for (int i = 0; i <= this->index; i++)
    {
        if (i == this->index)
        {
            printf("%d", this->arr[i]);
            break;
        }
        printf("%d, ", this->arr[i]);
    }
    printf("]\n");
}

void mfree(struct TopK **this)
{
    free((*this)->arr);
    free(*this);
}

void init(struct TopK **this, int k)
{
    struct TopK *topk = NULL;
    topk = (struct TopK *)malloc(sizeof(struct TopK));

    topk->arr = (int *)malloc(sizeof(int) * k);
    topk->index = -1;
    topk->min = 0x7FFF;
    topk->size = k;

    topk->push = push;
    topk->print = print;
    topk->mfree = mfree;

    *this = topk;
}

int main()
{
    int num[] = {10, 9, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(num) / sizeof(int);
    int k = 6;

    struct TopK *topk = NULL;
    init(&topk, k);

    for (int i = 0; i < size; i++)
    {
        topk->push(topk, num[i]);
    }

    topk->print(topk);
    topk->mfree(&topk);

    return 0;
}
