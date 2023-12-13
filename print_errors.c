#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_err - prints file error message and exits
 * @argv: argv given by main()
 *
 * Desc: print msg if  not possible to open the file
 * Return: nothing
 */
void print_err(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * print_e - prints usage message and exits
 *
 * Desc: if user does not give any file or more than
 * one argument to your program
 *
 * Return: nothing
 */
void print_e(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
