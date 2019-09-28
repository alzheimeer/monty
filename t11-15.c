#include "monty.h"
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: **pointer head of the stack
 * @line_number: number line in file
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr,"L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr,"L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);

}
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: **pointer head of the stack
 * @line_number: number of the file
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void) line_number;
	while (aux)
	{
		if (aux->n != 0 && isascii(aux->n))
			putchar(aux->n);
		else
			break;
		aux = aux->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates the stack to the top of the stack.
 * @stack: **pointer head of the stack
 * @line_number: number line in file
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *aux, *top;

	(void) line_number;
	if (!stack || !(*stack) || !(*stack)->next)
		return;
	aux = *stack;
	top = aux->next;
	top->prev = NULL;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = aux;
	*stack = top;
}
/**
 * rotr - rotates the stack to the bottom of the stack.
 * @stack: **pointer head of the stack
 * @line_number: number line in file
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (!stack || !(*stack) || !((*stack)->next))
		return;
	aux = *stack;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = *stack;
	aux->prev->next = NULL;
	aux->prev = NULL;
	(*stack)->prev = aux;
	(*stack) = aux;
	(void) line_number;
}
