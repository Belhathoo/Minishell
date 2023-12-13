#include "minishell.h"

/**
 * cd_error - cd_error programm
 * @path: path
 * Return: char
 */
void	cd_error(char *path)
{
	ft_putstr("cd: ");
	if (access(path, F_OK) == -1)
		ft_putstr("no such file or directory: ");
	else if (access(path, R_OK) == -1)
		ft_putstr("permission denied: ");
	else
		ft_putstr("not a directory: ");
	ft_putendl(path);
}

/**
 * ft_chdir - ft_chdir programm
 * @path: path
 * @print: print
 */
void	ft_chdir(char *path, int print)
{
	char	*cwd;
	char	buff[4097];
	char	*parsed;

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
		if (print)
		{
			parsed = parse_home(path);
			ft_putendl(parsed);
			free(parsed);
		}
		set_env_var("OLDPWD", cwd);
	}
	else
		cd_error(path);
}
/**
 * has_two_args - has_two_args programm
 * @args: args
 * Return: char
 */
static int	has_two_args(char **args)
{
	char	*cwd;
	char	buff[4096 + 1];
	char	*tmp;

	if (args[3])
	{
		ft_putendl("cd: too many arguments");
		return (1);
	}
	cwd = getcwd(buff, 4096);
	tmp = strreplace(cwd, args[1], args[2]);
	if (!tmp)
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putendl(args[1]);
		ft_strdel(&tmp);
		return (1);
	}
	ft_chdir(tmp, 1);
	free(tmp);
	return (1);
}

/**
 * run_cd - run_cd programm
 * @input: input
 * Return: char
 */
int	run_cd(char **input)
{
	char	*home;

	home = get_var("HOME");
	if (!input[1])
		ft_chdir(home, 0);
	else if (input[2])
		has_two_args(input);
	else if (ft_strequ(input[1], "--"))
		ft_chdir(home, 0);
	else if (input[1][0] == '-' && !input[0][2])
		ft_chdir(get_var("OLDPWD"), 1);
	else
		ft_chdir(input[1], 0);
	return (1);
}
