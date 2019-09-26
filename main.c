#include "monty.h"
stack_t **global_head = NULL;
/**
 * main - main the project monty
 * @argc: how many arguments input
 * @argv: arguments vector
 * Return: success or EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	size_t len;
	ssize_t read_line;
	unsigned int line_num = 0;
	char *line = NULL;
	FILE *fd;
	char *command;

	global_head = &head;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read_line = getline(&line, &len, fd)) != -1)
	{
		command = strtok(line, LIM);
		line_num++;
		if (command)
			choose(&head, command, line_num);
	}
	if (line)
		free(line);
	fclose(fd);
	atexit(freex);
	exit(EXIT_SUCCESS);
}


/**
 * choose - redirect according command
 * @stack: pointer to the head of the stack
 * @op: command
 * @line_num: number of line
 *
 * Return: void
 */
void choose(stack_t **stack, char *op, unsigned int line_num)
{
	int i;
	instruction_t mao[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	for (i = 0; mao[i].opcode; i++)
		if (strcmp(op, mao[i].opcode) == 0)
		{
			mao[i].f(stack, line_num);
			return;
		}
	if (strlen(op) != 0 && op[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, op);
		exit(EXIT_FAILURE);
	}
}

/**
 * freex - global frees memory
 * Return: void
 */
void freex(void)
{
	stack_t *freex = NULL, *aux = NULL;

	freex = *global_head;
	while (freex)
		aux = freex->next, free(freex), freex = aux;
}
