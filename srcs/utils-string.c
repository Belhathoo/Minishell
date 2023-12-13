#include "minishell.h"

/**
 * ft_strlen - ft_strlen
 * @s: s
 * Return: string
 */
size_t ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (s && s[size])
		size++;
	return (size);
}

/**
 * ft_strlen2 - ft_strlen2
 * @twodim: twodim
 * Return: string
 */
size_t ft_strlen2(char **twodim)
{
	int s;

	s = 0;
	while (twodim && twodim[s])
		s++;
	return (s);
}

/**
 * ft_strcmp - ft_strcmp
 * @sa: sa
 * @sb: sb
 * Return: string
 */
int ft_strcmp(const char *sa, const char *sb)
{
	int i;

	i = 0;
	while (sa[i] && sb[i] && sa[i] == sb[i])
		i++;
	return ((unsigned char)sa[i] - (unsigned char)sb[i]);
}

/**
 * ft_strstartswith - ft_strstartswith
 * @sa: sa
 * @sb: sb
 * Return: string
 */
int ft_strstartswith(char *sa, char *sb)
{
	int i;

	i = -1;
	while (sb[++i])
		if (sa[i] != sb[i])
			return (0);
	return (1);
}

/**
 * ft_strendswith - ft_strendswith
 * @sa: sa
 * @sb: sb
 * Return: string
 */
int ft_strendswith(char *sa, char *sb)
{
	int i;

	i = -1;
	while (sa[++i])
		if (sa[i] == sb[0])
			if (ft_strcmp(sa + i, sb) == 0)
				return (1);
	return (0);
}
