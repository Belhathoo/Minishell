#include "minishell.h"

/**
 * check_flag - check_flag programm
 * @arg: arg
 * @n: n
 * Return: char
 */
static int	check_flag(char *arg, int n)
{
	int	i;

	i = 1;
	if (arg[0] != '-')
		return (0);
	while (arg[i])
	{
		if (arg[i] != n)
			return (0);
		i++;
	}
	return (1);
}

/**
 * check_quote - check_quote programm
 * @input: input
 * Return: char
 */
void	check_quote(char *input)
{
	int	start;
	int	end;
	int	len;

	end = 0;
	start = 0;
	len = ft_strlen(input);
	if (input[0] == '"')
		start = 1;
	if (input[len - 1] == '"')
		end = 1;
	if (end && start)
		ft_putnstr(input + 1, len - 2);
	else if (end)
		ft_putnstr(input, len - 1);
	else if (start)
		ft_putstr(input + 1);
	else
		ft_putstr(input);
}

/**
 * run_echo - run_echo programm
 * @input: input
 * Return: char
 */
int	run_echo(char **input)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (input[++i] && ft_strequ(input[i], "-n") && check_flag(input[i], 'n'))
		n = 1;
	while (input[i])
	{
		check_quote(input[i]);
		if (input[++i])
			write(1, " ", 1);
	}
	if (!n)
		write(1, "\n", 1);
	return (1);
}
