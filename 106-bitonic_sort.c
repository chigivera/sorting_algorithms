#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Gets the maximum value in an array
 * @array: Array to get maximum from
 * @size: Size of the array
 * Return: Maximum value
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

/**
 * counting_sort_radix - Performs counting sort on a specific digit
 * @array: Array to sort
 * @size: Size of the array
 * @exp: Current digit position
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output, *count;
    size_t i;

    output = malloc(sizeof(int) * size);
    if (!output)
        return;
    count = calloc(10, sizeof(int));
    if (!count)
    {
        free(output);
        return;
    }

    /* Count occurrences */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Calculate cumulative count */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build output array */
    for (i = size - 1; i < size; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy back to original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
    free(count);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (!array || size < 2)
        return;

    max = get_max(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_radix(array, size, exp);
        print_array(array, size);
    }
}