#include "monty.h"
/**
 * pint - prints value top stack and \n
 * @stack: **pointer head of the stack
 * @line_number: number line in file
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr,"L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes top element stack.
 * @stack: **pointer head of the stack
 * @line_number: number line in file
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr,"L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	*stack = (*stack)->next;
	free(aux);
}

/**
 * swap - swaps top two elements stack.
 * @stack: **pointer head of the stack
 * @line_number: number line in file
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr,"L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;

	(*stack)->prev = aux;
	(*stack)->next = aux->next;

	aux->prev = NULL;

	if (aux->next)
		aux->next->prev = *stack;

	aux->next = *stack;

	*stack = aux;
}

/**
 * add - adds top two elements stack.
 * @stack: **pointer head of the stack
 * @line_number: number line in file
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	int sumn;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr,"L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	sumn = aux->n + aux->next->n;
	aux->next->n = sumn;
	*stack = aux->next;
	(*stack)->prev = NULL;
	free(aux);
}

/**
 * nop - doesn’t do anything
 * @stack: **pointer head of the stack
 * @line_number: number line in file
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
