#include "main.h"

/**
 *print_times_table - print time table.
 * @n: integer
 *Return:void
 */
void print_times_table(int n)
{
	int a, b, c;

	if (n >= 0 && n <= 15)
	{
		for (a = 0; a <= n; a++)
		{
			_putchar('0');
			if (n != 0)
				_putchar(',');
			for (b = 1; b <= n; b++)
			{
				c = a * b;
				if (c < 10)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar(' ');
					_putchar('0' + c);
				}
				else if (c < 100)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar((c / 10) + '0');
					_putchar((c % 10) + '0');
				}
				else
				{
					_putchar(' ');
					_putchar((c / 100) + '0');
					_putchar(((c % 100) / 10) + '0');
					_putchar(((c % 100) % 10) + '0');
				}
				if (a < n)
					_putchar(',');
			}
			_putchar('\n');
		}
	}
}
