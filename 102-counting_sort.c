#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers using Counting sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    int *counting_array, *output;
    size_t i;
    int max = 0;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum element */
    for (i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];

    /* Create counting array */
    counting_array = malloc(sizeof(int) * (max + 1));
    if (counting_array == NULL)
        return;

    /* Initialize counting array */
    for (i = 0; i <= (size_t)max; i++)
        counting_array[i] = 0;

    /* Store count of each element */
    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Modify counting array to store actual positions */
    for (i = 1; i <= (size_t)max; i++)
        counting_array[i] += counting_array[i - 1];

    /* Print the counting array */
    print_array(counting_array, max + 1);

    /* Create output array */
    output = malloc(sizeof(int) * size);
    if (output == NULL)
    {
        free(counting_array);
        return;
    }

    /* Build the output array */
    for (i = size - 1; i < size; i--)
    {
        output[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    /* Copy output array to original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(counting_array);
    free(output);
}
