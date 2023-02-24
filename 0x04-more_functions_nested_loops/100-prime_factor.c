#include <stdio.h>
#include <math.h>

/**
 * main - main block
 * Description: Find and print the largest prime factor of the number
 * 612852475143
 * Return: Always 0
 */

int main(void)
{
	int a;
	long number = 612852475143;

	for (a = (int) sqrt(number); a > 2; a++)
	{
		if (number % a == 0)
		{
			printf("%d\n", a);
			break;
		}
	}

	return (0);
}

