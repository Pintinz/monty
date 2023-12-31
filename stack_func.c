#include "monty.h"

/**
 * push - a function that add new item to top of stack
 * @stack: a pointer to stack
 * @line_number: line number
 * @n: the value of a new item on stack
 * Return: it returns void, exit with -1 on failure
 */
void push(stack_t **stack, unsigned int line_number, char *n)
{
	stack_t *new = NULL;
	int i;

	if (n == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; n[i] != '\0'; i++)
	{
		if (n[0] == '-' && i == 0)
			continue;
		if (isdigit(n[i]) == 0)
		{
			printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(n);
	new->prev = NULL;
	new->next = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}

	*stack = new;
}

/**
 * pop - a function that remove item at the top of stack
 * @stack: a pointer to stack
 * @line_number: line number
 * Return: it returns void, exit with -1 on failure
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	next = (*stack)->next; /* save next node's address */
	free(*stack);
	*stack = next; /* reassign next node to head */
}

/**
 * swap - a function swaps the value of the top two elements on the stack
 * @stack: a pointer to stack
 * @line_number: line number
 * Return: it returns void, exit with -1 on failure
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp_a;
	int temp_b;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_a = (*stack)->n;
	temp_b = (*stack)->next->n;

	(*stack)->n = temp_b;
	(*stack)->next->n = temp_a;
}

/**
 * nop - a function that does nothing
 * @stack: a pointer to stack
 * @line_number: line number
 * Return: it returns void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
