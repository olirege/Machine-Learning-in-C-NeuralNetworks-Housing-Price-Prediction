#include "../include/utils.h"

// Prints snapshot of array
void print_snapshot(const char *func, const char *name, int *array, int size)
{
    _log(func, "Snapshot of %s:", name);
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}