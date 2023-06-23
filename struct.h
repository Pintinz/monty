#ifndef STRUCTS_H
#define STRUCTS_H

/**
 * struct stack_s - a function that doubly linked list representation of a stack (or queue)
 * @n: an integer number
 * @prev: it points to the previous element of the stack (or queue)
 * @next: it points to the next element of the stack (or queue)
 *
 * Description: a doubly linked list node structure
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - a function that opcoode and its function
 * @opcode: the opcode
 * @f: the function to handle the opcode
 *
 * Description: opcode and its functions
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#endif /* STRUCTS_H */
