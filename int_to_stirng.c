#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);

/**
 * get_int - Converts a number to a string and returns a
 * character pointer to the new string.
 * @num: The number to be converted to a string.
 *
 * Return: A character pointer to the newly created string.
 * Returns NULL if memory allocation fails.
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - Computes the absolute value of an integer.
 * @i: The integer to compute the absolute value of.
 *
 * Return: The unsigned integer absolute value of i.
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - Computes the length of buffer needed
 * for representing an unsigned integer.
 * @num: The number to calculate the length for.
 * @base: The base of the number representation used by the buffer.
 *
 * Return: An integer containing the length of
 * buffer needed (excluding the null byte).
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - Fills a buffer with the correct
 * number representation up to base 36.
 * @num: The number to convert to a string using the specified base.
 * @base: The base of the number used in the conversion (up to base 36).
 * @buff: The buffer to fill with the result of the conversion.
 * @buff_size: The size of the buffer in bytes.
 *
 * Return: This function always returns void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return lowercase ascii val representation */
			buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
