#include "multithreading.h"

/**
 * factors - list of  factors
 * @num: factors
 * @list: the list
 * Return: Void
 */
void factors(unsigned long num, list_t *list)
{
	unsigned long i, *prime = NULL;

	while (num % 2 == 0)
	{
		prime = calloc(1, sizeof(unsigned long));
		*prime = 2;
		list_add(list, prime);
		num /= 2;
	}
	i = 3;
	while (i * i <= num)
	{
		while (num % i == 0)
		{
			prime = calloc(1, sizeof(unsigned long));
			*prime = i;
			list_add(list, prime);
			num /= i;
		}
		i += 2;
	}
	if (num > 2)
	{
		prime = calloc(1, sizeof(unsigned long));
		*prime = num;
		list_add(list, prime);
	}
}
/**
 * prime_factors - function
 * @s: number
 * Return: list
 */
list_t *prime_factors(char const *s)
{
	unsigned long num = 0;
	int i = 0;
	list_t *list = NULL;

	list = calloc(1, sizeof(list_t));
	if (!list)
	{
		return (NULL);
	}
	list_init(list);

	while (s[i])
	{
		num = (num * 10) + (s[i] - '0');
		i++;
	}
	factors(num, list);
	return (list);
}
