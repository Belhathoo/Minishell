#include "minishell.h"

/**
 * prompt - prompt programm
 * @env: env
 */

void prompt(void)
{
	ft_put3str("\033[1;36m", "\033[1;34m", "my_sh ");
	ft_putstr("\033[1;31m$ \033[0m");
}

/**
 * input_handler - input_handler programm
 * @env: env
 * Return: getline input
 */

char *input_handler(char **env)
{
	char *input;
	char buf;
	int nbr_oct;
	int i[2];

	input = ft_strnew(0);
	i[0] = 0;
	i[1] = 1;
	nbr_oct = read(0, &buf, 1);
	while (nbr_oct && buf != '\n')
	{
		*(input + i[0]++) = buf;
		input = ft_realloc((void **)(&input), i[1], i[1] + 1);
		i[1]++;
		nbr_oct = read(0, &buf, 1);
	}
	*(input + i[0]) = '\0';
	if (!nbr_oct)
	{
		free(input);
		free_exit();
	}
	if ((ft_strchr((input), '$') != NULL) || (ft_strchr((input), '~') != NULL))
		parser(&input, env);
	return (input);
}

/**
 * main - main programm
 * Description: program description
 * @ac: argc
 * @av: argv
 * @env: environment the parameter
 *
 * Return: Always 0 (Success)!
 */

int main(int ac, char **av, char **env)
{
	char *input;
	char **cmds;

	(void)ac;
	(void)av;
	input = NULL;
	while (1)
	{
		prompt();
		signal(SIGINT, ft_signal);
		input = input_handler(env);
		if (ft_isempty(&input))
			continue;
		cmds = ft_strsplit(input, ';');
		free(input);
		if (execution(&cmds, env) == -1)
		{
			ft_putendl("\033[0;31m my_sh terminated.\033[0m");
			break;
		}
	}
	return (0);
}
