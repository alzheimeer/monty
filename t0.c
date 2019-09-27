#include "monty.h"

/**
 * pushc - nodo mode cola
 * @stack: **pointer to head of the stack
 * @line_number: number of line
 * Return: void
 */
void pushc(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	stack_t *aux = *stack;
	char *n;
	int i;

	n = strtok(NULL, LIM);
	if (n == NULL || (!isdigit(*n) && *n != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; n[i] != '\0'; i++)
	{
		if (!isdigit(n[i]) && n[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = atoi(n);
	newnode->next = NULL;
	if (aux == NULL)
	{
		*stack = newnode;
		newnode->prev = NULL;
	}
	else
	{
		while (aux->next != NULL)
			aux = aux->next;
		newnode->prev = aux;
		aux->next = newnode;
	}
}
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
 * push - push new node to the begin of the stack
 * @stack: **pointer to head of the stack
 * @line_number: number of line
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	char *n;
	int i;

	n = strtok(NULL, LIM);
	if (n == NULL || (!isdigit(*n) && *n != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; n[i] != '\0'; i++)
	{
		if (!isdigit(n[i]) && n[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = atoi(n);
	newnode->prev = NULL;
	newnode->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = newnode;

	*stack = newnode;
}
