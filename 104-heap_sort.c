#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array
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
 * sift_down - Maintains the heap property
 * @array: Array to be sorted
 * @size: Size of the array
 * @root: Root index of the heap
 * @max: Maximum size for printing
 */
void sift_down(int *array, size_t size, size_t root, size_t max)
{
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        swap(&array[root], &array[largest]);
        print_array(array, max);
        sift_down(array, size, largest, max);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (!array || size < 2)
        return;

    /* Build max heap */
    for (i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, i, size);

    /* Extract elements from the heap */
    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, i, 0, size);
    }
}
