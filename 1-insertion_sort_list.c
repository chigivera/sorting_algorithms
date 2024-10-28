#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev_node, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        temp = current;
        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            prev_node = temp->prev;
            
            /* Adjust the next pointers */
            if (temp->next != NULL)
                temp->next->prev = prev_node;
            prev_node->next = temp->next;
            temp->next = prev_node;
            
            /* Adjust the prev pointers */
            temp->prev = prev_node->prev;
            prev_node->prev = temp;
            if (temp->prev != NULL)
                temp->prev->next = temp;
            else
                *list = temp;

            print_list(*list);
        }
        current = current->next;
    }
}
