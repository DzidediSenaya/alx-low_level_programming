#include <stdio.h>
#include "main.h"

/**
 * print_buffer - Prints a buffer 10 bytes at a time
 * @b: The buffer to be printed
 * @size: The number of bytes to be printed from the buffer
 * Return : Always 0
 */

void print_buffer(char *b, int size)
{
	int i, j;

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = 0; j < 10; j++)
		{
			if ((i + j) >= size)
				printf("  ");

			else
				printf("%02x", *(b + i + j));

			if ((j % 2) != 0 && j != 0)
				printf(" ");
		}

		for (j = 0; j < 10; j++)
		{
			if ((i + j) >= size)
				break;

			else if (*(b + i + j) >= 31 &&
				 *(b + i + j) <= 126)
				printf("%c", *(b + i + j));

			else
				printf(".");
		}

		if (i >= size)
			continue;

		printf("\n");
	}

	if (size <= 0)
		printf("\n");
}
