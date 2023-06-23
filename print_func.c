#include "monty.h"

/**
 * pall - a function that prints the value of all items on the stack
 * @stack: a pointer to stack
 * @line_number: line number
 * Return: it returns void
 */
void pall(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - a function that prints value at the top of the stack, plus new line
 * @stack: a pointer to stack
 * @line_number: line number
 * Return: it returns void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	int value;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n; /* head node's data */
	printf("%d\n", value);
}

/**
 * pchar - a function that prints the char at the top of the stack
 * @stack: a pointer to stack
 * @line_number: line number
 * Return: it returns  void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int c;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	c = (*stack)->n; /* head node's data */
	if (c < 0 || c > 127)
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(c);
	putchar('\n');
}

/**
 * pstr - a function prints the string starting from the top of the stack
 * @stack: a pointer to stack
 * @line_number: line number
 * Return: it returns void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int c;
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		c = current->n; /* current node's data */
		if (c > 0 && c <= 127)
		{
			current = current->next;
			putchar(c);
		}
		else
			break;
	}
	putchar('\n');
}
