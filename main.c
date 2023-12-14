#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

void print_err(char *argv);
void print_e(void);
int status = 0;
/**
 * main - entry point
 * @argv: list of arguments passed to our program
 * @argc: amount of args
 *
 * Return: nothing
 */
int main(int argc, char **argv)
{
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (initialise(&var) != 0)
		return (EXIT_FAILURE);

	var.file = fopen(argv[1], "r");
	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_data();
		return (EXIT_FAILURE);
	}

	while (getline(&var.buffer, &var.temp, var.file) != EOF)
	{
		opcode = strtok(var.buffer, " \r\t\n");
		if (opcode != NULL)
			if (call_function(&var, opcode) == EXIT_FAILURE)
			{
				free_data();
				return (EXIT_FAILURE);
			}
		var.line_cnt++;
	}

	free_data();

	return (EXIT_SUCCESS);
}

