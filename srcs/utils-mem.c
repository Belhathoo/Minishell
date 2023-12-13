#include "minishell.h"

/**
 * ft_strdup - ft_strdup
 * @src: src
 * Return: string
 */
char *ft_strdup(const char *src)
{
	int i;
	char *str;

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

/**
 * ft_memset - ft_memset
 * @b: b
 * @c: c
 * @len: len
 * Return: string
 */
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

/**
 * ft_strnew - ft_strnew
 * @size: size
 * Return: string
 */
char *ft_strnew(size_t size)
{
	char *s;

	s = (char *)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	ft_memset(s, '\0', size + 1);
	return (s);
}

/**
 * ft_memcpy - ft_memcpy
 * @dst: dst
 * @src: src
 * @n: n
 * Return: string
 */
void *ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return ((void *)dst);
}

/**
 * ft_realloc - ft_realloc
 * @ptr: ptr
 * @old: old
 * @len: len
 * Return: string
 */
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
