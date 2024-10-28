#include "deck.h"
#include <stdio.h>
#include <string.h>

/**
 * get_card_value - Get numeric value of a card
 * @str: String value of the card
 * Return: Numeric value of the card
 */
static int get_card_value(const char *str)
{
    int i;
    char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
                      "Jack", "Queen", "King"};
    
    for (i = 0; i < 13; i++)
    {
        if (strcmp(str, values[i]) == 0)
            return (i);
    }
    return (0);
}

/**
 * compare_cards - Compare two cards
 * @a: First card
 * @b: Second card
 * Return: Comparison result
 */
static int compare_cards(const void *a, const void *b)
{
    const card_t *card_a = (*(const deck_node_t **)a)->card;
    const card_t *card_b = (*(const deck_node_t **)b)->card;

    /* Compare suits first */
    if (card_a->kind != card_b->kind)
        return (card_a->kind - card_b->kind);

    /* If suits are same, compare values */
    return (get_card_value(card_a->value) - get_card_value(card_b->value));
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *current;
    deck_node_t **card_array;
    size_t count = 0, i;

    if (!deck || !*deck)
        return;

    /* Count nodes and allocate array */
    current = *deck;
    while (current)
    {
        count++;
        current = current->next;
    }

    card_array = malloc(count * sizeof(deck_node_t *));
    if (!card_array)
        return;

    /* Fill array with node pointers */
    current = *deck;
    for (i = 0; i < count; i++)
    {
        card_array[i] = current;
        current = current->next;
    }

    /* Sort array using qsort */
    qsort(card_array, count, sizeof(deck_node_t *), compare_cards);

    /* Rebuild linked list */
    for (i = 0; i < count; i++)
    {
        if (i == 0)
        {
            *deck = card_array[i];
            card_array[i]->prev = NULL;
        }
        if (i < count - 1)
        {
            card_array[i]->next = card_array[i + 1];
            card_array[i + 1]->prev = card_array[i];
        }
        if (i == count - 1)
            card_array[i]->next = NULL;
    }

    free(card_array);
}