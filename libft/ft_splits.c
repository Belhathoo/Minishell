
#include "libft.h"
#include "../minishell.h"
int		ft_countwordsall(char *str)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (SPA(str[i]))
			i++;
		if (!SPA(str[i]) && str[i] != '\0')
			count++;
		while (!SPA(str[i]) && str[i] != '\0')
			i++;
	}
	return (count);
}

static int		get_word_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (SPA(str[i]))
		i++;
	while (!SPA(str[i]) && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplits(char *s)
{
	int		i;
	int		j;
	int		k;
	char	**str2;

	if (!s || !(str2 = (char **)malloc(sizeof(*str2) *
		(ft_countwordsall(s) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwordsall(s))
	{
		k = 0;
		if (!(str2[i] = ft_strnew(get_word_len(&s[j]) + 1)))
			str2[i] = NULL;
		while (SPA(s[j]))
			j++;
		while (!SPA(s[j]) && s[j])
			str2[i][k++] = s[j++];
		str2[i][k] = '\0';
	}
	str2[i] = 0;	
	return (str2);
}