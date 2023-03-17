#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * find_len - Finds the length of a string.
 * @str: The string to be measured.
 * Return: The length of the string.
 */

int find_len(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * create_array - Creates an array of chars and initializes it with
 * the character 'i'. Adds a terminating null byte.
 * @size: The size of the array to be initialized.
 * If there is insufficient space, the function exits
 * with a status of 98
 * Return: A pointer to the array.
 */

char *create_array(int size)
{
	char *array;
	int index;

	array = malloc(sizeof(char) * size);

	if (array == NULL)
		exit(98);

	for (index = 0; index < (size - 1); index++)
		array[index] = 'i';

	array[index] = '\0';

	return (array);
}


/**
 * leading_zeroes - Iterates through a string of numbers containing
 * leading zeroes until it hits a non-zero number.
 * @str: The string of numbers to be iterate through.
 * Return: A pointer to the next non-zero element.
 */

char *leading_zeroes(char *str)
{
	while (*str && *str == '0')
		str++;

	return (str);
}

/**
 * convert_digit - Converts a digit character to a corresponding int.
 * @c: The character to be converted.
 * If c is a non-digit, the function
 * exits with a status of 98.
 * Return: The converted int.
 */

int convert_digit(char c)
{
	int digit = c - '0';

	if (digit < 0 || digit > 9)
	{
		printf("Error\n");
		exit(98);
	}

	return (digit);
}


/**
 * str_mul - Multiplies a string of numbers by a single digit.
 * @prod: The buffer to store the result.
 * @mul: The string of numbers.
 * @digit: The single digit.
 * @zeroes: The necessary number of leading zeroes.
 * If mul contains a non-digit, the function
 * exits with a status value of 98.
 * Return: nothing
 */

void str_mul(char *prod, char *mul, int digit, int zeroes)
{
	int len_mul, num, tens = 0;

	len_mul = find_len(mul) - 1;
	mul += len_mul;

	while (*prod)
	{
		*prod = 'x';
		prod++;
	}

	prod--;

	while (zeroes--)
	{
		*prod = '0';
		prod--;
	}

	for (; len_mul >= 0; len_mul--, mul--, prod--)
	{
		if (*mul < '0' || *mul > '9')
		{
			printf("Error\n");
			exit(98);
		}

		num = (*mul - '0') * digit;
		num += tens;
		*prod = (num % 10) + '0';
		tens = num / 10;
	}

	if (tens)
		*prod = (tens % 10) + '0';
}


/**
 * add_nums - Adds the numbers stored in two strings.
 * @final_prod: The buffer storing the running final product.
 * @next_prod: The next product to be added.
 * @next_len: The length of next_prod.
 */

void add_nums(char *final_prod, char *next_prod, int next_len)
{
	int num, tens = 0;

	while (*(final_prod + 1))
		final_prod++;

	while (*(next_prod + 1))
		next_prod++;

	for (; *final_prod != 'x'; final_prod--)
	{
		num = (*final_prod - '0') + (*next_prod - '0');
		num += tens;
		*final_prod = (num % 10) + '0';
		tens = num / 10;

		next_prod--;
		next_len--;
	}

	for (; next_len >= 0 && *next_prod != 'x'; next_len--)
	{
		num = (*next_prod - '0');
		num += tens;
		*final_prod = (num % 10) + '0';
		tens = num / 10;

		final_prod--;
		next_prod--;
	}

	if (tens)
		*final_prod = (tens % 10) + '0';
}

/**
 * main - Multiplies two positive numbers.
 * @argv: The number of arguments passed to the program.
 * @argc: An array of pointers to the arguments.
 * Description: If the number of arguments is incorrect or one number
 * contains non-digits, the function exits with a status of 98.
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	char *final_prod, *next_prod;
	int size, index, digit, zeroes = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (*(argv[1]) == '0')
		argv[1] = leading_zeroes(argv[1]);
	if (*(argv[2]) == '0')
		argv[2] = leading_zeroes(argv[2]);
	if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
	{
		printf("0\n");
		return (0);
	}

	size = find_len(argv[1]) + find_len(argv[2]);
	final_prod = create_array(size + 1);
	next_prod = create_array(size + 1);

	for (index = find_len(argv[2]) - 1; index >= 0; index--)
	{
		digit = convert_digit(*(argv[2] + index));
		str_mul(next_prod, argv[1], digit, zeroes++);
		add_nums(final_prod, next_prod, size - 1);
	}
	for (index = 0; final_prod[index]; index++)
	{
		if (final_prod[index] != 'x')
			putchar(final_prod[index]);
	}
	putchar('\n');

	free(next_prod);
	free(final_prod);

	return (0);
}
