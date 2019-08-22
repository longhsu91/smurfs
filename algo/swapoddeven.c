#include "list.h"

#include <stdio.h>
#include <stdlib.h>

void print(int *num, int begin, int end)
{
    printf("[---");
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

void swapNum(int *num, int first, int last, int flag)
{
    // odd <-> even
    int n1 = 1;
    int n2 = 0;

    // even <-> odd
    if (flag)
    {
        n1 = 0;
        n2 = 1;
    }

    while (first < last)
    {
        while (first < last)
        {
            if ((first + 1) % 2 == n1)
            {
                if (num[first] % 2 == n2)
                {
                    break;
                }
            }

            first++;
        }

        while (first < last)
        {
            if ((last + 1) % 2 == n2)
            {
                if (num[last] % 2 == n1)
                {
                    break;
                }
            }

            last--;
        }

        int tmp = num[first];
        num[first] = num[last];
        num[last] = tmp;

        first++;
        last--;
    }
}

int main()
{
    int num[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(num) / sizeof(int);

    print(num, 0, size - 1);
    swapNum(num, 0, size - 1, 0);
    swapNum(num, 0, size - 1, 1);
    print(num, 0, size - 1);

    return 0;
}