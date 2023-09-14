#include "my_monty.h"
/**
 * main - monty program entry point
 * @argc: number of command-line argument
 * @argv: argument value
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	FILE *file_pointer;
	size_t buffer_size;
	char *line_buffer;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: failure\n");
		exit(EXIT_FAILURE);
	}

	line_buffer = NULL;
	buffer_size = 0;
	file_pointer = fopen(argv[1], "r");
	if (file_pointer == NULL)
	{
		fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line_buffer, &buffer_size, file_pointer) != -1)
	{
		intereprate_line(line_buffer, line_number, &stack);
		line_number++;
	}
	free_stack(&stack);
	free(line_buffer);
	line_buffer = NULL;
	fclose(file_pointer);
	return (0);
}