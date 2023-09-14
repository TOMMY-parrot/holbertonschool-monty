#include "my_monty.h"
/**
 * intereprate_line - intrepets the line
 * @line: string containnig the line
 * @line_number:number of line
 * @stack: pointer to the stack head
 * Return: void
 */
void intereprate_line(char *line, unsigned int line_number, stack_t **stack)
{
	char *function_name;
	int valid_intruction;
	char *d;
	int flag = 0;

	function_name = strtok(line, " \t\n");
	if (function_name != NULL)
	{
		input = strtok(NULL, " \t\n");
		valid_intruction = is_valid_instruction_name(function_name);
		d = input;
		flag = is_input_number(d);
		if (strcmp(function_name, "push") == 0 && (!input || flag == 1))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			stack = NULL;
			free(line);
			line = NULL;
			exit(EXIT_FAILURE);
		}
		else if (valid_intruction != VALID)
		{
			print_error(line, line_number);
			free_stack(stack);
			stack = NULL;
			free(line);
			line = NULL;
			exit(EXIT_FAILURE);
		}
		else
			intereprate_line(function_name, line_number, stack);
	}
}
/**
 * is_input_number - checks if string is a number
 * @string: string
 * Return: 1 or 0
 */
int is_input_number(char *string)
{
	while (string != NULL && *string != '\0')
	{
		if (*string == '-')
		{
			if (isdigit(*(string + 1)) == 0 && string--)
				return (1);
		}
		else if (*string != '-' && isdigit(*string) == 0)
			return (1);
		string++;
	}
	return (0);
}
/**
 * is_valid_instruction_name - checks if the the instruction name is valid
 * @function_name: name of the function that can be "push"
 *
 * Return: 0 (function is unknown) on failure and 1 on success
 */
int is_valid_instruction_name(char *function_name)
{
	char valid_name[][10] = {"push", "pall", "pint", "pop", "nop", "swap", "add", ""};
	unsigned int s;

	for (s = 0; valid_name[s][0] != '\0'; s++)
	{
		if (strcmp(valid_name[s], function_name) == 0)
			return (1);
	}
	return (0);
}
/**
 * print_error - print error
 * @line:string containing the line
 * @line_number: number of the line
 * Return: void, nothingness
 */
void print_error(char *line, unsigned int line_number)
{
	(void)line;

	fprintf(stderr, "L%d: no valid instruction %s\n", line_number, line);
}
/**
 * free_stack - print error
 * @stack: pointer to stack head
 * Return: void, nothingness
 */
void free_stack(stack_t **stack)
{
	stack_t *current, *tmp;

	current = *stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		tmp = NULL;
	}
}