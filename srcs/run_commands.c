#include "minishell.h"

/**
 * run - run programm
 * @cmd: cmd
 * @input: path
 * @env: env
 * Return: char
 */
int	run(char *cmd, char **input, char **env)
{
	pid_t	pid;

	pid = fork();
	signal(SIGINT, ft_child_signal);
	if (pid < 0)
	{
		ft_put3str("my_sh: ", "Fork failed to create a new process.", "\n");
		return (0);
	}
	if (pid == 0 && execve(cmd, input, env) == -1)
	{
		ft_put2str("my_sh: command not found: ", input[0]);
		return (-1);
	}
	wait(&pid);
	return (1);
}

/**
 * check_exec - check_exec programm
 * @path: path
 * @st: st
 * @in: in
 * @env: env
 * Return: char
 */
int	check_exec(char *path, struct stat st, char ***in, char **env)
{
	char	**input;

	input = *in;
	if (st.st_mode & S_IFREG)
	{
		if (st.st_mode & S_IXUSR)
		{
			if (run(path, input, env) == -1)
			{
				ft_free(in);
				return (-2);
			}
		}
		else
			ft_put3str("my_sh: permision denied: ", input[0], "\n");
		ft_free(in);
		return (1);
	}
	if (st.st_mode & S_IFDIR && ft_strlen2(input) == 1)
	{
		ft_chdir(input[0], 0, env);
		ft_free(in);
		return (1);
	}
	return (0);
}

/**
 * check_one_cmd - check_one_cmd programm
 * @input: input
 * @env: env
 * Return: char
 */
int	check_one_cmd(char ***input, char **env)
{
	int			isbuiltin;
	struct stat	st;
	int			ret;

	isbuiltin = is_builtin(input, env);
	if (isbuiltin == -1)
		return (-1);
	if (isbuiltin || is_bin(input, env))
		return (1);
	if (lstat((*input)[0], &st) != -1)
	{
		ret = check_exec((*input)[0], st, input, env);
		if (ret == -2)
			free_exit();
		return (ret);
	}
	return (0);
}

/**
 * execution - execution programm
 * @commandss: commands
 * @env: env
 * Return: char
 */
int	execution(char ***commandss, char **env)
{
	int		i;
	int		ret;
	char	**cmd;
	char	**commands;

	i = -1;
	ret = 1;
	commands = *commandss;
	while (commands && commands[++i])
	{
		cmd = ft_strsplits(commands[i]);
		ret = check_one_cmd(&cmd, env);
		if (ret == -1)
			break;
		if (ret == 0)
			ft_put4str("my_sh: ", "command not found: ", cmd[0], "\n");
		ft_free(&cmd);
	}
	ft_free(commandss);
	return (ret);
}
