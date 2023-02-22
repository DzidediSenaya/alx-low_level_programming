#include <stdio.h>

/**
  * main - Prints the first 50 fibonacci numbers
  *
  * Return: Always 0
  */
int main(void)
{
	int a;
	unsigned long b = 0, b = 1, sum;

	for (a = 0; a < 50; a++)
	{
		sum = b + c;
		printf("%lu", sum);

		b = b;
		c = sum;

		if (a == 49)
			printf("\n");
		else
			printf(", ");
	}

	return (0);
}
