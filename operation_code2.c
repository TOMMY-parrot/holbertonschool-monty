#include "monty.h"
/**
 * push - push the elements to a linked list
 * @stack: the pointer to stack's first element
 * @line_number: line of the file being processed.
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (input != NULL)
	{
		stack_t *msr = malloc(sizeof(stack_t));

		msr->n = atoi(input);
		msr->next = (*stack);
		msr->prev = NULL;

		if ((*stack) != NULL)
		{
			(*stack)->prev = msr;
		}
		(*stack) = msr;
	}
}
/**
 * pall - prints the elements of a linked list
 * @stack: the pointer to stack's first element
 * @line_number: line of the file being processed.
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *vdr;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
		return;
	vdr = *stack;
	while (vdr)
	{
		printf("%d\n", vdr->n);
		vdr = vdr->next;
	}
}
/**
 * pint - prints item of the stack
 * @stack: the pointer to the stack
 * @line_number: line of the file being treated
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}
/**
 * pop - removes the last element of a stack
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: cannot pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = NULL;
	free(ptr);
}
/**
 * swap - swap 2 first nodes
 * @stack: stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *m = (*stack);
	int len = 0;

	while (m != NULL)
	{
		len++;
		m = m->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack very short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *node1 = (*stack);
		stack_t *node2 = (*stack)->next;

		node1->next = node2->next;
		node1->prev = node2;

		node2->prev = NULL;
		node2->next = node1;

		(*stack) = node2;
	}
}