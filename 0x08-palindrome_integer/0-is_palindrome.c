#include "palindrome.h"
/**
 * is_palindrome - checks whether or not
 * a given unsigned integer is a palindrome.
 * @n: is the number to be checked.
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long aux = 0, n1 = n;
	int mid = 0, first = 0, last = 0;

	while (n1)
	{
		aux = (aux * 10) + (n1 % 10);
		n1 /= 10, mid++;
	}
	n1 = n;
	mid = (mid / 2) + (mid % 2);
	while (mid)
	{
		last = n1 % 10;
		first = aux % 10;
		if (first != last)
			return (0);
		n1 /= 10, aux /= 10;
		mid--;
	}
	return (1);
}
