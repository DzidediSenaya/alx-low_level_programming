#include "main.h"
/**
*print_line - print line
*@n: number of times to print character
*
*/

void print_line(int n)
{
	int a;

	for (a = 0; a < n; a++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
