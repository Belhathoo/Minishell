/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 04:34:07 by belhatho          #+#    #+#             */
/*   Updated: 2022/05/12 04:30:12 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/************** PRINT ***************/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void ft_put2str(char const *s, char const *s1)
{
	ft_putstr(s);
	ft_putstr(s1);
}

void ft_put3str(char const *s, char const *s1, char const *s2)
{
	ft_put2str(s, s1);
	ft_putstr(s2);
}

void ft_put4str(char const *s, char const *s1, char const *s2,
				char const *s3)
{
	ft_put3str(s, s1, s2);
	ft_putstr(s3);
}

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = -1;
	if (n < 0)
		ft_putstr(str);
	else
	{
		while (str[++i] && i < n)
			ft_putchar(str[i]);
	}
}

/******************************************
 * ******************************************
 * ************** MEMORY **************
 * ******************************************
 *  *******************************************/

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void *ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return ((void *)b);
}

char *ft_strnew(size_t size)
{
	char *s;

	s = (char *)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	ft_memset(s, '\0', size + 1);
	return (s);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return ((void *)dst);
}

void *ft_realloc(void **ptr, size_t old, size_t len)
{
	void *real;

	real = malloc(len);
	ft_memset(real, 0, len);
	if (real)
		ft_memcpy(real, *ptr, old);
	if (*ptr)
		free(*ptr);
	return (real);
}

void	ft_free(char ***to)
{
	int		i;

	i = -1;
	while (to && (*to) && (*to)[++i])
		free((*to)[i]);
	free((*to));
	(*to) = NULL;
}

void	ft_strdel(char **as)
{
	if (as == NULL)
		return ;
	if (*as)
	{
		free(*as);
		*as = NULL;
	}
}

/******************************************
 * ******************************************
 * ************** STRINGS **************
 * ******************************************
 *  *******************************************/

size_t	ft_strlen(const char *s)
{
	size_t			size;

	size = 0;
	while (s && s[size])
		size++;
	return (size);
}

size_t	ft_strlen2(char **twodim)
{
	int		s;

	s = 0;
	while (twodim && twodim[s])
		s++;
	return (s);
}

int ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strstartswith(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

int	ft_strendswith(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i])
		if (s1[i] == s2[0])
			if (ft_strcmp(s1 + i, s2) == 0)
				return (1);
	return (0);
}

int	is_first_word(char *s1, char *s2)
{
	int	i;

	i = -1;
	if (!s1 || !s2)
		return (0);
	while (s2[++i] && s1[i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

int	ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

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

int get_word_len(char const *str, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int ft_countwords(char const *str, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

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

char **ft_strsplit(char const *s, char c)
{
	int i;
	int j;
	int k;
	char **str2;

	str2 = (char **)malloc(sizeof(*str2) * (ft_countwords(s, c) + 1));
	if (!(str2))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwords(s, c))
	{
		k = 0;
		str2[i] = ft_strnew(get_word_len(&s[j], c) + 1);
		if (!(str2[i]))
			str2[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str2[i][k++] = s[j++];
		str2[i][k] = '\0';
	}
	str2[i] = 0;
	return (str2);
}

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



char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	char		*s;
	int			i;
	int			j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
		s[i++] = s1[j];
	j = -1;
	while (s2[++j])
		s[i++] = s2[j];
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin2(char *s1, char *s2, int tofree)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	if (!(new))
		return (NULL);
	free(s1);
	s1 = NULL;
	if (tofree && s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (new);
}

char	*ft_strchjoin(const char *s1, char c)
{
	char	*new_str;
	size_t	i;
	size_t	s1_len;

	if (!c)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	new_str = ft_strnew(s1_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	*(new_str + i + 1) = '\0';
	return (new_str);
}

char	*ft_strchjoinf(char *s1, char c)
{
	char	*new;

	new = ft_strchjoin(s1, c);
	if (!(new))
		return (NULL);
	free(s1);
	s1 = NULL;
	return (new);
}


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