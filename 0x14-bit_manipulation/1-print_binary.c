#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print
 */

void print_binary(unsigned long int n)
{
unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
/* Create a mask with the most significant bit set */
int flag = 0; /* Initialize flag variable */
while (mask > 0)
{
/* Loop through each bit in the mask */
if ((n & mask) == mask)
{
/* Check if the current bit is set in n */
_putchar('1'); /* If the current bit is set, print '1' */
flag = 1; /* Set flag to indicate that a bit has been printed */
}
else if (flag == 1)
{
/* If the current bit is not set*/
/*and a bit has already been printed */
_putchar('0'); /* Print '0' */
}
mask >>= 1; /* Shift the mask one bit to the right */
}

if (flag == 0)
{
/* If no bits were printed, print '0' */
_putchar('0');
}
}

