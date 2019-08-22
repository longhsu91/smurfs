#include <stdio.h>

int size = 0;

void print(int *num, int begin, int end)
{
    printf("[");
    for (int i = begin; i <= end; i++)
    {
        if (i == end)
        {
            printf("%d]\n", num[i]);
            return;
        }
        printf("%d, ", num[i]);
    }
}

int partation(int *num, int begin, int end);

void quick_sort(int *num, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }

    int mid = partation(num, begin, end);

    quick_sort(num, begin, mid - 1);
    quick_sort(num, mid + 1, end);
}

int partation(int *num, int begin, int end)
{
    int seed = num[begin];

    while (begin < end)
    {
        while (begin < end && num[end] >= seed)
        {
            end--;
        }

        num[begin] = num[end];

        while (begin < end && num[begin] <= seed)
        {
            begin++;
        }

        num[end] = num[begin];
    }

    // begin == end
    num[begin] = seed;

    return begin;
}

int main()
{
    int num[] = {3, 2, 3, 1, 3, 3, 3, 3};
    size = sizeof(num) / sizeof(int);
    quick_sort(num, 0, size - 1);

    print(num, 0, size - 1);

    return 0;
}
