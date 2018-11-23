
#include "list.h"
#include "config.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    fprintf(stdout, "Smurfs Version %d.%d\n", Smurfs_VERSION_MAJOR, Smurfs_VERSION_MINOR);

    int arr[] = {0, 5};
    int size = sizeof(arr) / sizeof(int);

    PListNode head = list_create(arr, size);

    list_print(head);
    list_add(&head, 2);
    list_print(head);
    list_add(&head, 2);
    list_print(head);
    list_add(&head, 3);
    list_print(head);
    list_add(&head, 4);
    list_print(head);
    list_remove(&head);
    list_print(head);
    list_remove(&head);
    list_print(head);
    list_remove(&head);
    list_print(head);
    list_add(&head, 2);
    list_print(head);
    list_remove(&head);
    list_print(head);
    list_insert(&head, 0, 9);
    list_print(head);
    list_insert(&head, 0, 5);
    list_print(head);
    list_delete(&head, 0);
    list_print(head);
    list_reverse(&head);
    list_print(head);

    list_free(head);

    return 0;
}