#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays into one sorted array
 * @array: Original array
 * @temp: Temporary array for merging
 * @left: Start index of left subarray
 * @mid: End index of left subarray
 * @right: End index of right subarray
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid, k = left;

    printf("Merging...\n");
    printf("[left]: ");
    for (size_t l = left; l < mid; l++)
    {
        if (l > left)
            printf(", ");
        printf("%d", array[l]);
    }
    printf("\n[right]: ");
    for (size_t l = mid; l < right; l++)
    {
        if (l > mid)
            printf(", ");
        printf("%d", array[l]);
    }
    printf("\n");

    while (i < mid && j < right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i < mid)
        temp[k++] = array[i++];
    while (j < right)
        temp[k++] = array[j++];

    for (i = left; i < right; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    for (i = left; i < right; i++)
    {
        if (i > left)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}

/**
 * merge_sort_recursive - Recursive function to implement merge sort
 * @array: Array to sort
 * @temp: Temporary array for merging
 * @left: Start index
 * @right: End index
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
    if (right - left > 1)
    {
        size_t mid = left + (right - left) / 2;
        merge_sort_recursive(array, temp, left, mid);
        merge_sort_recursive(array, temp, mid, right);
        merge(array, temp, left, mid, right);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (!array || size < 2)
        return;

    temp = malloc(sizeof(int) * size);
    if (!temp)
        return;

    merge_sort_recursive(array, temp, 0, size);
    free(temp);
}