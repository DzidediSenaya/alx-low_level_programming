#include <stdio.h>

/**
  * main -  prints all possible combinations of single-digit numbers.
  *
  * Return: Always 0;
  */
int main(void)
{
	int a;

	for (a = '0'; a <= '9'; a++)
	{
		putchar(a);

		if (a != '9')
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}
