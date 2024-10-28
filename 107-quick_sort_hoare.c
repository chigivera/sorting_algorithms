#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @array: The array containing the elements
 * @i: Index of first element
 * @j: Index of second element
 * @size: Size of the array
 */
void swap(int *array, size_t i, size_t j, size_t size)
{
    int temp;

    if (array[i] != array[j])
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        print_array(array, size);
    }
}

/**
 * hoare_partition - Partitions the array using Hoare's scheme
 * @array: Array to sort
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Final position of the pivot
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

        swap(array, i, j, size);
    }
}

/**
 * quicksort - Recursive function to implement quicksort
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high, size);
        quicksort(array, low, pivot, size);
        quicksort(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array using the quicksort algorithm
 * with Hoare partition scheme
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}