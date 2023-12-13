#include "minishell.h"

/**
 * get_word_len1 - get_word_len1
 * @str: str
 * Return: string
 */
static int	get_word_len1(char const *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (!(str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

/**
 * ft_countwordsall - ft_countwordsall
 * @str: str
 * Return: string
 */
static int	ft_countwordsall(char const *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!((str[i] == ' ' || str[i] == '\t')) && str[i] != '\0')
			count++;
		while (!((str[i] == ' ' || str[i] == '\t')) && str[i] != '\0')
			i++;
	}
	return (count);
}

/**
 * ft_strsplits - ft_strsplits
 * @s: s
 * Return: string
 */
char	**ft_strsplits(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	**str2;

	str2 = (char **)malloc(sizeof(*str2) * (ft_countwordsall(s) + 1));
	if (!s || !(str2))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwordsall(s))
	{
		k = 0;
		str2[i] = ft_strnew(get_word_len1(&s[j]) + 1);
		if (!(str2[i]))
			str2[i] = NULL;
		while (s[j] == ' ' || s[j] == '\t')
			j++;
		while (!(s[j] == ' ' || s[j] == '\t') && s[j])
			str2[i][k++] = s[j++];
		str2[i][k] = '\0';
	}
	str2[i] = 0;
	return (str2);
}

/**
 * ft_strjoin - ft_strjoin
 * @sa: sa
 * @sb: sb
 * Return: string
 */
char	*ft_strjoin(char const *sa, char const *sb)
{
	size_t		size;
	char		*s;
	int			i;
	int			j;

	if (sa == NULL && sb == NULL)
		return (NULL);
	if (sa == NULL)
		return (ft_strdup(sb));
	if (sb == NULL)
		return (ft_strdup(sa));
	size = ft_strlen(sa) + ft_strlen(sb);
	s = (char *)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	j = -1;
	while (sa[++j])
		s[i++] = sa[j];
	j = -1;
	while (sb[++j])
		s[i++] = sb[j];
	s[i] = '\0';
	return (s);
}

/**
 * ft_strjoin2 - ft_strjoin2
 * @sa: sa
 * @sb: sb
 * @tofree: tofree
 * Return: string
 */
char	*ft_strjoin2(char *sa, char *sb, int tofree)
{
	char	*new;

	new = ft_strjoin(sa, sb);
	if (!(new))
		return (NULL);
	free(sa);
	sa = NULL;
	if (tofree && sb)
	{
		free(sb);
		sb = NULL;
	}
	return (new);
}
