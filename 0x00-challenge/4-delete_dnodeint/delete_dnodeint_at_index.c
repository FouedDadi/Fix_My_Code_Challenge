#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

    if (*head == NULL)
    return (-1);
    tmp = *head;
    if (index == 0)
    {
    *head = tmp->next;
    free(tmp);
    return (1);
    }
    for (p = 0; p < (index - 1) && tmp != NULL; p++)
    tmp = tmp->next;
    if (tmp == NULL)
    return (-1);
    if (tmp->next == NULL)
    return (-1);
    saved_head = tmp->next->next;
    free(tmp->next);
    tmp->next = saved_head;
    return (1);
}