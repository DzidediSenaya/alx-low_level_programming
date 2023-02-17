#include <stdio.h>

/**
  * main - Prints all possible different combinations of two digits.
  *
  * Return: Always 0
  */
int main(void)
{
	int a, b;

	a = b = '0';

	for (a = '0'; a <= '9'; a++)
	{
		for (b = '0'; b <= '9'; b++)
		{
			putchar(a);
			putchar(b);

			if ((a != '9') || (a == '9' && b != '9'))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}

	putchar('\n');

	return (0);
}

