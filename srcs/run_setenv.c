#include "minishell.h"

/**
 * set_env_var - set_env_var programm
 * @key: key
 * @value: value
 * Return: char
 */
void	set_env_var(char *key, char *value)
{
	int		pos;
	char	*tmp;

	pos = find_var_index(key);
	tmp = ft_strjoin("=", value);
	if (g_env[pos])
	{
		free(g_env[pos]);
		g_env[pos] = ft_strjoin(key, tmp);
	}
	else
	{
		g_env = realloc_env(pos + 1);
		g_env[pos] = ft_strjoin(key, tmp);
	}
	if (value)
		free(tmp);
}

/**
 * run_setenv - run_setenv programm
 * @input: input
 * Return: char
 */
int	run_setenv(char **input)
{
	int	len;

	len = ft_strlen2(input);
	if (len == 1)
		print_env();
	else if (len == 2)
		set_env_var(input[1], "");
	else if (len == 3)
		set_env_var(input[1], input[2]);
	else
		ft_putstr("setenv: Too many arguments.\n");
	return (1);
}
