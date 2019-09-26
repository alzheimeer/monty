#include "monty.h"
/**
 * sub - subtracts the top element stack
 * @stack: ** pointer head of the stack
 * @line_number: number line in file
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	int sub;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	sub = aux->next->n - aux->n;
	aux->next->n = sub;
	*stack = aux->next;
	(*stack)->prev = NULL;
	free(aux);
}


/**
 * div - divides the second top element stack
 * @stack: **pointer head of the stack
 * @line_number: number line in file
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	int dv;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	dv = aux->next->n / aux->n;
	aux->next->n = dv;
	*stack = aux->next;
	(*stack)->prev = NULL;
	free(aux);

}

/**
 * mul - multiplies the second top element stack
 * @stack: **pointer head of the stack
 * @line_number: number line in file
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	int mult;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	mult = aux->next->n * aux->n;
	aux->next->n = mult;
	*stack = aux->next;
	(*stack)->prev = NULL;
	free(aux);
}

/**
 * mod - module of the second top element stack
 * @stack: **pointer head of the stack
 * @line_number: number line in file
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	int md;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	md = aux->next->n % aux->n;
	aux->next->n = md;
	*stack = aux->next;
	(*stack)->prev = NULL;
	free(aux);
}
