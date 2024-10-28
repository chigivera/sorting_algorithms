# C - Sorting algorithms & Big O

A collection of sorting algorithms implemented in C with their corresponding Big O notations.

## Description

This project implements various sorting algorithms in C, including:

- Bubble sort
- Insertion sort
- Selection sort
- Quick sort (Lomuto partition)
- Shell sort (Knuth sequence)
- Cocktail shaker sort
- Counting sort
- Merge sort
- Heap sort
- Radix sort
- Bitonic sort
- Quick sort (Hoare partition)
- Card deck sort

Each algorithm is implemented with proper printing of the array/list after each swap operation.

## Requirements

- All files compiled on Ubuntu 20.04 LTS using gcc with flags: -Wall -Werror -Wextra -pedantic -std=gnu89
- Code follows the Betty style
- No global variables
- No more than 5 functions per file
- Unless specified, standard library functions are forbidden
- Prototypes of all functions included in sort.h
- Header files are include guarded

## Data Structures

```c
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

## Helper Functions

The project includes helper functions for printing arrays and lists:

```c
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
```

## Files and Their Big O Notations

| File | Description | Time Complexity |
|------|-------------|-----------------|
| 0-bubble_sort.c | Bubble Sort implementation | O(n), O(n^2), O(n^2) |
| 1-insertion_sort_list.c | Insertion Sort for doubly linked list | O(n), O(n^2), O(n^2) |
| 2-selection_sort.c | Selection Sort implementation | O(n^2), O(n^2), O(n^2) |
| 3-quick_sort.c | Quick Sort with Lomuto partition | O(nlog(n)), O(nlog(n)), O(n^2) |
| 100-shell_sort.c | Shell Sort using Knuth sequence | - |
| 101-cocktail_sort_list.c | Cocktail Shaker Sort | O(n), O(n^2), O(n^2) |
| 102-counting_sort.c | Counting Sort implementation | O(n+k), O(n+k), O(n+k) |
| 103-merge_sort.c | Merge Sort implementation | O(nlog(n)), O(nlog(n)), O(nlog(n)) |
| 104-heap_sort.c | Heap Sort implementation | O(nlog(n)), O(nlog(n)), O(nlog(n)) |
| 105-radix_sort.c | Radix Sort implementation | - |
| 106-bitonic_sort.c | Bitonic Sort implementation | O(log²n), O(log²n), O(log²n) |
| 107-quick_sort_hoare.c | Quick Sort with Hoare partition | O(nlog(n)), O(nlog(n)), O(n^2) |
| 1000-sort_deck.c | Sort a deck of cards | - |

## Usage

To compile any of the sorting algorithms:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 [main_file.c] [sort_file.c] print_array.c print_list.c -o [output_name]
```

Example:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-bubble_sort.c print_array.c -o bubble
```

## Author

[Your Name]