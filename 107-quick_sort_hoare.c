#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Partitions array using Hoare scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of array
 * Return: Partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * quick_sort_recursive - Recursively sorts array using quicksort
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high, size);
        quick_sort_recursive(array, low, pivot, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort