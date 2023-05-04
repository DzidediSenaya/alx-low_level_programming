#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @n: pointer to the number.
 * @index: index of the bit to clear.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
/* Declare variable mask to store bit mask to clear bit at given index */
unsigned long int mask;

/* Check if index is within range of bits in unsigned long int */
if (index > (sizeof(unsigned long int) * 8 - 1))
{
/* If index is out of range, return -1 to indicate an error */
return (-1);
}

/* Create a mask with a 0 at the bit position to clear and 1s elsewhere */
mask = ~(1UL << index);
/* AND the original value pointed to by n with the mask to clear the bit */
*n &= mask;

/* Return 1 to indicate success */
return (1);
}

