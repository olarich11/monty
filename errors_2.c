#include "monty.h"

int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/**
 * pop_error - Prints error messages for attempting
 * to pop from an empty stack.
 * @line_number: The line number in the script
 * where the error occurred.
 *
 * This function prints error messages when an
 * attempt is made to pop from an empty stack.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Prints error messages for attempting to pint an empty stack.
 * @line_number: The line number in the Monty bytecodes file
 * where the error occurred.
 *
 * This function prints error messages when attempting to
 * execute the "pint" instruction on an empty stack.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Prints error messages for Monty math functions
 * when stacks/queues have fewer than two nodes.
 * @line_number: The line number in the Monty
 * bytecodes file where the error occurred.
 * @op: The operation where the error occurred.
 *
 * This function prints error messages when attempting Monty math
 * functions with stacks/queues that have fewer than two nodes.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Prints error messages for division by zero.
 * @line_number: The line number in the Monty bytecodes
 * file where the error occurred.
 *
 * This function prints error messages when
 * attempting division by zero in Monty bytecodes.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints error messages for pchar instruction
 * with empty stacks and non-character values.
 * @line_number: The line number in the Monty bytecodes file
 * where the error occurred.
 * @message: The specific error message to print.
 *
 * This function prints error messages when attempting to
 * use the "pchar" instruction
 * with empty stacks or non-character values.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
