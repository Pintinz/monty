#include "monty.h"

/**
 * main - main function of monty program
 * @argc: arguments counts
 * @argv: the array of strings of arguments
 * Return: it returns 0 on success, -1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	stack_t *stack = NULL;
	char *line = NULL;
	char *opcode;
	char *n;
	unsigned int line_number;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line_number = 0;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		opcode = strtok(line, DELIMITERS);
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			n = strtok(NULL, DELIMITERS);
			push(&stack, line_number, n);
		}
		else
			opcode_struct(opcode, &stack, line_number);
	}

	free_all(stack, line, fp);
	return (EXIT_SUCCESS);
}
