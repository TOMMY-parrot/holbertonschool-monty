#include "monty.h"
/**
 * parse_me - execute the fuction
 * @function_name: name of the function
 * @line_number: line number of the instruction
 * @stack: ponter to pinter to the stack head
 * Return: void
 */
void parse_me(char *function_name, unsigned int line_number, stack_t **stack)
{
	instruction_t inst[] = {{"pall", pall},
							{"pop", pop},
							{"pint", pint},
							{"nop", nop},
							{"push", push},
							{"swap", swap},
							{"add", add},
							{NULL, NULL}};
	unsigned int k;

	for (k = 0; inst[k].opcode != NULL; k++)
	{
		if (strcmp(inst[k].opcode, function_name) == 0)
		{
			inst[k].f(stack, line_number);
		}
	}
}