#include "monty.h"
/**
 * add - adds 2 numbers
 * @stack:stack
 * @line_number: lines of numbers
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *r = (*stack);
	int sum = 0;
	int length = 0;

	while (r != NULL)
	{
		length++;
		r = r->next;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: not enough numbers to add\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum = (*stack)->n + (*stack)->next->n;
		(*stack)->next->n = sum;
		pop(stack, line_number);
	}
}

/**
 * nop - doesn’t do nothing
 * @stack: the pointer to the stack
 * @line_number: line of the file 
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}