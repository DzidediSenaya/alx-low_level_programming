# include "main.h"

/**
* get_bit - returns the value of a bit at a given index
* @n: the number to get the bit value from
* @index: the index of the bit to get
* Return: the value of the bit at the given index or
* -1 if an error occurred
*/

int get_bit(unsigned long int n, unsigned int index)
{
if (index >= (sizeof(unsigned long int) * 8))
/* Check if index is greater than or equal to the*/
/* number of bits in an unsigned long int */

return (-1);/*if not valid*/

return ((n >> index) & 1);
/* Shift the number n to the right by index to get the bit at index */
/* and return it*/
}

