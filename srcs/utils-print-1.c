#include "minishell.h"

/**
 * ft_put2str - ft_putstr
 * @s: c
 * @sa: c
 */
void ft_put2str(char const *s, char const *sa)
{
	ft_putstr(s);
	ft_putstr(sa);
}

/**
 * ft_put3str - ft_put3str
 * @s: c
 * @sa: c
 * @sb: c
 */
void ft_put3str(char const *s, char const *sa, char const *sb)
{
	ft_put2str(s, sa);
	ft_putstr(sb);
}

/**
 * ft_put4str - ft_put3str
 * @s: c
 * @sa: c
 * @sb: cn
 * @sc: c
 */
void ft_put4str(char const *s, char const *sa, char const *sb, char const *sc)
{
	ft_put3str(s, sa, sb);
	ft_putstr(sc);
}

/**
 * ft_putnstr - ft_putstr
 * @str: c
 * @n: c
 */
void ft_putnstr(char *str, int n)
{
	int i;

	i = -1;
	if (n < 0)
		ft_putstr(str);
	else
	{
		while (str[++i] && i < n)
			ft_putchar(str[i]);
	}
}
