#include "monty.h"
/**
 * main - monty execute program
 * @argc: number of arguments
 * @argv: argument value 
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	FILE *file_p;
	size_t size_b;
	char *line_b;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	line_b = NULL;
	size_b = 0;
	file_p = fopen(argv[1], "r");
	if (file_p == NULL)
	{
		fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line_b, &size_b, file_p) != -1)
	{
		read_line(line_b, line_number, &stack);
		line_number++;
	}
	free_stack(&stack);
	free(line_b);
	line_b = NULL;
	fclose(file_p);
	return (0);
}