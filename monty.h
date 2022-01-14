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

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int string_is_int(char *s);
void lines_to_array(char *line, char **copy);
void replace_emptylines(char *buff, char **copy);
void initialize_buffer(char *s, int size);
void initialize_array(char **s, int size);
size_t print_dlistint(stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void free_dlistint(stack_t *head);
void (*getopcode_fun(char *opcode))(stack_t **, unsigned int);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);


/** macros **/

#define USAGE_ERROR \
do {\
	write(STDERR_FILENO, "USAGE: monty file\n", _strlen("USAGE: monty file\n"));\
	exit(EXIT_FAILURE);\
} while (0)

#define OPEN_ERROR(FILE) \
do {\
	fprintf(stderr, "Error: Can't open file %s\n", FILE);\
	exit(EXIT_FAILURE);\
} while (0)

#define MALLOC_ERROR \
do {\
	fprintf(stderr, "Error: malloc failed");\
	exit(EXIT_FAILURE);\
} while (0)

#define MALLOC_ERROR1(BUFF) \
do {\
	fprintf(stderr, "Error: malloc failed");\
	exit(EXIT_FAILURE);\
} while (0)

#define  INSTRUCTION_ERROR(LINE, INSTRUCTION, STACK) \
do {\
	fprintf(stderr, "L%d: unknown instruction %s\n", LINE, INSTRUCTION);\
	free_dlistint(STACK);\
	exit(EXIT_FAILURE);\
} while (0)

#endif
