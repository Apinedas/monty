#include "monty.h"

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_nodo;

	new_nodo = malloc(sizeof(stack_t));
	if (!new_nodo)
		return (NULL);
	new_nodo->n = n;
	new_nodo->next = NULL;
	new_nodo->prev = NULL;
	if (!*head)
	{
		*head = new_nodo;
	}
	else
	{
		new_nodo->next = *head;
		(*head)->prev = new_nodo;
		*head = new_nodo;
	}
	return (new_nodo);
}
void op_pall(stack_t **stack, unsigned int line_number)
{
	if (h)
	{
		int elmets = 0;

		while (h)
		{
			printf("%d\n", h->n);
			elmets++;
			h = h->next;
		}
		return (elmets);
	}
	return (0);
}

