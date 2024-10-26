#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - checks if palindrome
 * @n: number to check
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	unsigned long num, valr = 0;

	num = n;

	while (num != 0)
	{
		valr = valr * 10;
		valr = valr + num % 10;
		num = num / 10;
	}
	if (n == valr)
		return (1);
	else
		return (0);
}
