#include "monty.h"
/**
 * add - adds 2 numbers
 * @stack:stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *s = (*stack);
	int len = 0;
	int sum = 0;

	while (s != NULL)
	{
		len++;
		s = s->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
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
 * @line_number: line of the file that being trated
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}