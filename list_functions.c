#include "monty.h"

/**
 * print_dlistint - prints all the elements of a stack_t list.
 * @h: Pointer to head node of list to print
 * Return: number of nodes on list
 */

size_t print_dlistint(stack_t *h)
{
	size_t lenght = 0;

	while (h)
	{
		printf("%d\n", h->n);
		lenght++;
		h = h->next;
	}
	return (lenght);
}

/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list.
 * @head: Pointer to pointer of head node of the list
 * @n: Intiger to add
 * Return: The address of the new node, or NULL on fail
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		MALLOC_ERROR;
	new->prev = NULL;
	new->n = n;
	if (head && *head)
	{
		(*head)->prev = new;
		new->next = (*head);
	}
	else
		new->next = NULL;
	(*head) = new;
	return (new);
}

/**
 * add_dnodeint_end - adds a new node at the end of a stack_t list.
 * @head: Pointer to pointer to head of the list
 * @n: Intiger to add
 * Return: Address of new element or NULL if fail
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *curr, *new;

	curr = NULL;
	if (*head)
		curr = (*head);
	while (curr && curr->next)
		curr = curr->next;
	new = malloc(sizeof(*new));
	if (new == NULL)
		MALLOC_ERROR;
	new->n = n;
	new->next = NULL;
	if (curr)
	{
		new->prev = curr;
		curr->next = new;
	}
	else
		(*head) = new;
	return (new);
}

/**
 * free_dlistint - frees a stack_t list.
 * @head: pointer to list's head
 */

void free_dlistint(stack_t *head)
{
	stack_t *curr;

	while (head)
	{
		curr = head->next;
		free(head);
		head = curr;
	}
}

/**
 * delete_dnodeint_at_index - deletes the node at
 * index of a stack_t linked list.
 * @head: Pointer to pointer to list's head
 * @index: Index to node to delete
 * Return: 1 on succeed, -1 on fail
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *curr;
	unsigned int actual_idx = 0;

	curr = *head;
	while (curr)
	{
		if (index == actual_idx && index > 0)
		{
			if (curr->next)
				(curr->next)->prev = curr->prev;
			(curr->prev)->next = curr->next;
			free(curr);
			return (1);
		}
		if (index == 0)
		{
			if (curr && curr->next)
			{
				*head = curr->next;
				(curr->next)->prev = NULL;
				free(curr);
			}
			else
			{
				*head = NULL;
				free(curr);
			}
			return (1);
		}
		curr = curr->next;
		actual_idx++;
	}
	return (-1);
}
