#include "monty.h"

/**
 * pall - prints all values from the stack
 * @stack: **pointer to head of the stack
 * @line_number: number of line
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void) line_number;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
/**
 * push - pushes new node to the begin of the stack
 * @stack: **pointer to head of the stack
 * @line_number: number of line
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	char *n;

	n = strtok(NULL, DELIMS);
	if (n == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = atoi(n);
	newnode->prev = NULL;
	newnode->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = newnode;

	*stack = newnode;
}
