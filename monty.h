#ifndef MONTY_H
#define MONTY_H

/** structures **/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/** headers **/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

/** functions **/

void *_calloc(unsigned int nmemb, unsigned int size);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int string_is_int(char *s);
size_t print_dlistint(stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
void (*getopcode_fun(char *opcode))(stack_t **, unsigned int);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);

/** macros **/

#define USAGE_ERROR \
do {\
	write(STDERR_FILENO, "USAGE: monty file\n", _strlen("USAGE: monty file\n"));\
	exit(EXIT_FAILURE);\
} while (0)

#define OPEN_ERROR(FILE) \
do {\
	write(STDERR_FILENO, "Error: Can't open file ", _strlen("Error: Can't open file "));\
		write(STDERR_FILENO, FILE, _strlen(FILE));\
		write(STDERR_FILENO, "\n", 1);\
		exit(EXIT_FAILURE);\
} while (0)

#define MALLOC_ERROR \
do {\
	write(STDERR_FILENO, "Error: malloc failed\n", _strlen("Error: malloc failed\n"));\
	exit(EXIT_FAILURE);\
} while (0)

#define FREEANDCLOSE(BUFF, COPY, FD) \
do {\
	free(COPY);\
	free(BUFF);\
	close(FD);\
} while (0)

#endif
