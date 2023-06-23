#include "monty.h"

/**
 * stack_length - a function that returns length of stack
 * @stack:a pointer to head of stack
 * Return: it returns length of stack
 */
size_t stack_length(stack_t **stack)
{
	stack_t *current;
	unsigned int n; /* counter for number of elements */

	current = *stack;
	n = 0;
	while (current != NULL)
	{
		current = current->next;
		n++;
	}

	return (n);
}

/**
 * free_stack - a function that frees a stack_t stack
 * @stack: stack to be freed
 * Return: it returns void
 */
void free_stack(stack_t **stack)
{
	stack_t *current;

	while (*stack != NULL)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}

/**
 * free_all - a function that frees line and fp
 * @stack: stack to free
 * @line: line to free from getline
 * @fp: file pointer
 * Return: it returns void
 */
void free_all(stack_t *stack, char *line, FILE *fp)
{
	if (stack != NULL)
		free_stack(&stack);

	free(line);
	fclose(fp);
}
