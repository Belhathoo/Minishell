#include "minishell.h"

/**
 * is_first_word - is_first_word
 * @sa: sa
 * @sb: sb
 * Return: string
 */
int	is_first_word(char *sa, char *sb)
{
	int	i;

	i = -1;
	if (!sa || !sb)
		return (0);
	while (sb[++i] && sa[i])
		if (sa[i] != sb[i])
			return (0);
	return (1);
}

/**
 * ft_strequ - ft_strequ
 * @sa: sa
 * @sb: sb
 * Return: string
 */
int	ft_strequ(char const *sa, char const *sb)
{
	if (!sa || !sb)
		return (0);
	while (*sa || *sb)
	{
		if (*sa != *sb)
			return (0);
		sa++;
		sb++;
	}
	return (1);
}

/**
 * ft_strchr - ft_strchr
 * @s: s
 * @c: c
 * Return: string
 */
char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/**
 * ft_strechr - ft_strechr
 * @s: s
 * @c: c
 * Return: string
 */
char	*ft_strechr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (s)
	{
		while (s[i] && i)
		{
			if (s[i] == (char)c)
				return ((char *)(s + i));
			i--;
		}
	}
	return ((char *)s);
}

/**
 * ft_isempty - ft_isempty
 * @str: str
 * Return: string
 */
int ft_isempty(char **str)
{
	int i;
	int ret;

	i = -1;
	ret = 1;
	while (str && (*str) && (*str)[++i])
	{
		if ((*str)[i] > 32 && (*str)[i] <= 126)
			ret = 0;
	}
	if (ret)
		free(*str);
	return (ret);
}
