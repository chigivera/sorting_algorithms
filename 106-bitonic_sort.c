#include "sort.h"
#include <stdio.h>

/**
 * bitonic_compare - Compares and swaps elements based on direction
 * @array: Array to sort
 * @i: First index
 * @j: Second index
 * @dir: Direction (1 for UP, 0 for DOWN)
 */
void bitonic_compare(int *array, size_t i, size_t j, int dir)
{
    int temp;

    if (dir == (array[i] > array[j]))
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

/**
 * bitonic_merge - Recursively merges bitonic sequences
 * @array: Array to sort
 * @low: Starting index
 * @size: Size of the sequence
 * @dir: Direction (1 for UP, 0 for DOWN)
 * @total_size: Total size of the original array
 */
void bitonic_merge(int *array, size_t low, size_t size, int dir, size_t total_size)
{
    size_t k, i;

    if (size > 1)
    {
        k = size / 2;
        for (i = low; i < low + k; i++)
            bitonic_compare(array, i, i + k, dir);
        bitonic_merge(array, low, k, dir, total_size);
        bitonic_merge(array, low + k, k, dir, total_size);
    }
}

/**
 * bitonic_sequence - Creates and sorts bitonic sequences recursively
 * @array: Array to sort
 * @low: Starting index
 * @size: Size of the sequence
 * @dir: Direction (1 for UP, 0 for DOWN)
 * @total_size: Total size of the original array
 */
void bitonic_sequence(int *array, size_t low, size_t size, int dir, size_t total_size)
{
    size_t k;

    if (size > 1)
    {
        k = size / 2;
        printf("Merging [%lu/%lu] (%s):\n", size, total_size, dir ? "UP" : "DOWN");
        print_array(array + low, size);

        bitonic_sequence(array, low, k, 1, total_size);
        bitonic_sequence(array, low + k, k, 0, total_size);
        bitonic_merge(array, low, size, dir, total_size);

        printf("Result [%lu/%lu] (%s):\n", size, total_size, dir ? "UP" : "DOWN");
        print_array(array + low, size);
    }
}

/**
 * bitonic_sort - Sorts an array using the bitonic sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2 || (size & (size - 1)) != 0)
        return;

    bitonic_sequence(array, 0, size, 1, size);
}