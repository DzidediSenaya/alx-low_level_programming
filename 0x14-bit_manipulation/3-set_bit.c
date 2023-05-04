# include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to the unsigned long int variable to modify
 * @index: index of the bit to set to 1
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
/* Checks if index is greater than the number of bits in unsigned long int */
if (index > ((sizeof(unsigned long int) * 8) - 1))
{
/* Returns -1 if index is invalid */
return (-1);
}
/* Shifts 1 to the left by index and perform a bitwise OR operation*/
/*with the value pointed to by n */
*n |= (1UL << index);
/* Returns 1 to indicate success */
return (1);
}

