#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to
 * flip to get from one number to another.
 * @n: the first number.
 * @m: the second number.
 *
 * Return: the number of bits to flip.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
/* Calculate the XOR result of the two input numbers */
unsigned long int xor_result = n ^ m;
/* Initialize count variable to 0 to count the number of flipped bits */
unsigned int count = 0;
    
/* Loop over the XOR result until all flipped bits are counted */
while (xor_result)
{
/* Check if the least significant bit of the XOR result is 1 */
if (xor_result & 1)
{
/* Increment count if the least significant bit is 1 */
count++;
}
/* Shift the XOR result right by 1 bit to check the next bit */
xor_result >>= 1;
}
    
/* Return the total count of flipped bits */
return (count);
}

