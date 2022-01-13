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
		return (NULL);

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
		return (NULL);
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
