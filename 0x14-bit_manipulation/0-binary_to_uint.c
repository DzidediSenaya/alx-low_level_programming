# include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - converts a binary string to an unsigned int
 * @b: pointer to a string containing the binary number
 *
 * Return: the unsigned int result of the binary conversion
 */

unsigned int binary_to_uint(const char *b)
{
unsigned int con_num = 0; /*initialize converted number to 0*/
int i = 0; /*index*/

if (b == NULL) /* Check if string is NULL */
return (0);

while (b[i] != '\0') /* Loop through each character of the string */
{
if (b[i] == '0' || b[i] == '1') /* Check if character is a*/
/*valid binary digit */
{
con_num = (con_num << 1) + (b[i] - '0'); /* Convert binary digit to an*/
/*integer and add it to the result */
i++; /* Move to the next character */
}
else
{
return (0); /* Return 0 if a character is not a valid binary digit */
}
}

return (con_num); /* Return the unsigned int result of the binary conversion */
}

