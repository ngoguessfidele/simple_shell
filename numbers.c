#include "main.h"

/**
 * numlen- length of a number
 * @n: the integer
 * Return: the length
 */
int numlen(int n)
{
	unsigned int n1;
	int length = 1;

	if (n < 0)
	{
		length++;
		n1 = n * (-1);
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		length++;
		n1 = n1 / 10;
	}
	return (length);
}

/**
 * rev_atoi- from int to string
 * @n: the integer
 * Return: the string
 */
char *rev_atoi(int n)
{
	unsigned int n1;
	int length = numlen(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (length + 1));
	if (buffer == 0)
		return (NULL);
	*(buffer + length) = '\0';
	if (n < 0)
	{
		n1 = n * (-1);
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}
	length--;
	do {
		*(buffer + length) = (n1 % 10) + '0';
		n1 = n1 / 10;
		length--;
	} while (n1 > 0);
	return (buffer);
}

/**
 * _atoi- from string to integer
 * @s: the string
 * Return: the integer
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;
		if (*(s + count) == '-')
			pn *= -1;
		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}
	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
