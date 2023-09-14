#include "my_monty.h"
/**
 * execute_instruction - execute the fuction
 * @opcode: name of the function
 * @line_num: line number of the instruction
 * @stack: pointer to point to the stack head
 * Return: void
 */
void execute_instruction(char *opcode, unsigned int line_num, stack_t **stack)
{
	instruction_t instruction[] = {{"pall", pall},
							{"pop", pop},
							{"pint", pint},
							{"nop", nop},
							{"push", push},
							{"swap", swap},
							{"add", add},
							{NULL, NULL}};
	unsigned int f;

	for (f = 0; instruction[f].opcode != NULL; f++)
	{
		if (strcmp(instruction[f].opcode, opcode) == 0)
		{
			instruction[f].f(stack, line_num);
		}
	}
}