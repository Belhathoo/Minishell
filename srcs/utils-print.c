#include "minishell.h"

/**
 * ft_putchar - ft_putchar
 * @c: c
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * ft_putendl - ft_putendl
 * @s: c
 */
void ft_putendl(char const *s)
{
	if (s == NULL)
		return;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
}

/**
 * ft_putstr - ft_putstr
 * @s: c
 */

void ft_putstr(char const *s)
{
	if (s == NULL)
		return;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}
