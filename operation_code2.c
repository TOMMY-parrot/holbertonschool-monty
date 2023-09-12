#include "my_monty.h"

/**
 * push - push elements onto a linked list stack
 * @stack: pointer to the stack's first element
 * @line_number: line number in the file
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (input != NULL)
    {
        stack_t *new_node = malloc(sizeof(stack_t));

        new_node->n = atoi(input);
        new_node->next = (*stack);
        new_node->prev = NULL;

        if ((*stack) != NULL)
        {
            (*stack)->prev = new_node;
        }
        (*stack) = new_node;
    }
}

/**
 * pall - print the elements of a linked list stack
 * @stack: pointer to the stack's first element
 * @line_number: line number in the file being processed
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    (void)line_number;
    if (stack == NULL || *stack == NULL)
        return;
    current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - print the top item of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file being treated
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !stack)
    {
        dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    else
        dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}

/**
 * pop - remove the last element from the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file being processed
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    (void)line_number;

    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    current = *stack;
    *stack = current->next;
    if (current->next != NULL)
        current->next->prev = NULL;
    free(current);
}

/**
 * swap - swap the first two nodes in the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *current = (*stack);
    int length = 0;

    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    if (length < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
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
