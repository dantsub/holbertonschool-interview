#include "holberton.h"

/**
 * _strstrstop - locates a character in a string.
 * @haystack: the buffer source
 * @needle: the char to find
 *
 * Return: The pointer to first occurency or 0.
 */
char *_strstrstop(char *haystack, char *needle)
{
	if (*needle == '\0' && *haystack == '\0')
		return (0);
	if (*needle == '\0')
		return (haystack);
	if (*haystack == '\0')
		return (0);
	if (*haystack == *needle)
		if (_strstrstop((haystack + 1), (needle + 1)) != 0)
			return (_strstrstop(haystack + 1, needle + 1));

	return (0);
}

/**
 * _strstr - locates a substring.
 * @haystack: the buffer source
 * @needle: the string to find
 *
 * Return: The quantity of bytes contents
 */
char *_strstr(char *haystack, char *needle)
{
	if (*needle == '\0')
		return (haystack);
	if (*haystack == '\0')
		return (0);
	if (*haystack == *needle)
	{
		if (_strstrstop(haystack, needle) != 0)
			return (_strstrstop(haystack, needle));
		else
			return (_strstr(haystack + 1, needle));
	}
	else
		return (_strstr(haystack + 1, needle));

	return (0);
}

/**
 * wildcmp - Compares two string to find out if they are identical
 * @s1: The string 1
 * @s2: The string 2
 *
 * Return: 1 if true or 0 if false
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2)
		return (wildcmp(++s1, ++s2));
	if (*s1 == '\0' && *s2 == '*')
		return (wildcmp(s1, ++s2));
	if (*s2 == '*' && *(s2 + 1) == '*')
		return (wildcmp(s1, ++s2));
	if (*s2 == '*' && *(s2 + 1) != *s1)
		return (wildcmp(++s1, s2));
	if (*s2 == '*' && *(s2 + 1) == *s1)
	{
		if (_strstr(s1, (s2 + 1)))
			return (wildcmp(strstr(s1, (s2 + 1)), (s2 + 1)));
		else
			return (wildcmp(s1, ++s2));
	}

	return (0);
}
