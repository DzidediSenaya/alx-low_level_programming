#include "main.h"

/**
 * get_endianness - checks the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
/* Create a 32-bit integer with the value 1 */
unsigned int i = 1;
/* Create a char pointer and point it to the address of i */
char *c = (char *)&i;

/* Check the value of the first byte of i */
if (*c)
return (1); /* If the first byte is non-zero, the system is little endian */
else
return (0); /* If the first byte is zero, the system is big endian */
}

