#include "main.h"

/**
 * nat_sqrt - finds the natural square root of a number
 * @i: number to find square root of
 * @j: square root
 * Return: square root if number has a natural square root
 * else return -1
 */

int nat_sqrt(int i, int j)
{
	if (j * j == i)
		return (j);
	else if (j * j > i)
		return (-1);
	return (nat_sqrt(i, j + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n:number to find square root of
 * Return: square root if nymber has a natural square root
 * else return -1
 */

int _sqrt_recursion(int n)
{
	return (nat_sqrt(n, 1));
}

