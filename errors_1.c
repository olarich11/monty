#include "monty.h"

int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/**
 * usage_error - Prints usage error messages.
 *
 * function is responsible for printing usage error messages.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints error messages related to memory allocation (malloc).
 *
 * Function responsible for printing error messages during memory
 * allocation using malloc.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Prints error messages related to
 * file opening, along with the file name.
 * @filename: Name of the file that failed to open
 *
 * This is Function responsible for displaying
 * error messages that occur when attempting to open a file.
 * Return: Always returns (EXIT_FAILURE).
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints error messages for unknown
 * instructions (opcodes).
 * @opcode: The opcode where the error occurred.
 * @line_number: The line number in the Monty bytecodes
 * file where the error occurred.
 *
 * This function prints error messages when encountering
 * unknown instructions (opcodes) during execution.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Prints error messages for invalid arguments of monty_push.
 * @line_number: The line number in the Monty bytecodes
 * file where the error occurred.
 *
 * This function prints error messages when encountering
 * invalid arguments for the monty_push instruction.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
