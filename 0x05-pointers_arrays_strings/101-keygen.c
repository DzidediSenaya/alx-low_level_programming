#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * main - Generates random valid passwords for the
 * program 101-crackme.
 * Return: Always 0.
 */

int main(void)
{
	char password[84];
	int pw = 0, sum = 0, a, b;

	srand(time(0));

	while (sum < 2772)
	{
		password[pw] = 33 + rand() % 94;
		sum += password[pw++];
	}

	password[pw] = '\0';

	if (sum != 2772)
	{
		a = (sum - 2772) / 2;
		b = (sum - 2772) / 2;
		if ((sum - 2772) % 2 != 0)
			a++;

		for (pw = 0; password[pw]; pw++)
		{
			if (password[pw] >= (33 + b))
			{
				password[pw] -= a;
				break;
			}
		}
		for (pw = 0; password[pw]; pw++)
		{
			if (password[pw] >= (33 + b))
			{
				password[pw] -= b;
				break;
			}
		}
	}

	printf("%s", password);

	return (0);
}
