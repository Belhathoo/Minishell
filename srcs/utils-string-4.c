#include "minishell.h"

/**
 * ft_strchjoin - ft_strchjoin
 * @sa: sa
 * @c: c
 * Return: string
 */
char	*ft_strchjoin(const char *sa, char c)
{
	char	*new_str;
	size_t	i;
	size_t	sa_len;

	if (!c)
		return (ft_strdup(sa));
	sa_len = ft_strlen(sa);
	new_str = ft_strnew(sa_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < sa_len)
		*(new_str + i) = *(sa + i);
	*(new_str + i) = c;
	*(new_str + i + 1) = '\0';
	return (new_str);
}

/**
 * ft_strchjoinf - ft_strchjoinf
 * @sa: sa
 * @c: c
 * Return: string
 */
char	*ft_strchjoinf(char *sa, char c)
{
	char	*new;

	new = ft_strchjoin(sa, c);
	if (!(new))
		return (NULL);
	free(sa);
	sa = NULL;
	return (new);
}

/**
 * ft_strstr - ft_strstr
 * @str: str
 * @to_find: to_find
 * Return: string
 */
char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return ((char *)(str + i));
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * ft_strsub - ft_strsub
 * @s: s
 * @start: start
 * @len: len
 * Return: string
 */
char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
