/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:19:03 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/03 15:19:06 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int		is_builtin(char **input, t_env **m_env)
{
	if (ft_strequ(input[0], "exit"))
	{
		if (dp_len(input) == 1)
			return (-1);
		else
			ft_putstr("exit : Exxpression Syntax.");
		return (1);
	}
	if (ft_strequ(input[0], "env"))
		return (run_env(input, *m_env));
	if (ft_strequ(input[0], "setenv"))
		return (run_setenv(input, m_env));
	if (ft_strequ(input[0], "unsetenv"))
		return (run_unsetenv(input, m_env));
//	if (ft_strequ(input[0], "cd"))
//		return (run_cd(input, m_env));
//	if (ft_strequ(input[0], "echo"))
//		return (run_echo(input, m_env));
	printf("No Builtins!\n");
	return (0);
}


int		run_cmd(char *cmd, char **input, char **m_env)
{
	pid_t	pid;

	printf("OPLAA!!");
	pid = fork();
	if (pid < 0)
	{
		ft_putendl("Fork failed to create a new process.");
		return (0);
	}
	if (pid == 0)
	{
		execve(cmd, input, m_env);
		ft_putendl("error!");
	}
	if (pid > 0)
		wait(&pid);
	return (1);
}

int		check_exec(char *path, struct stat st, char **input, t_env *env)
{
	char	**m_env;

	m_env = ft_lsttoarr(env);
	if (st.st_mode & S_IFREG)
	{
		if (st.st_mode & S_IEXEC)
			return (run_cmd(path, input, m_env));
		else
			ft_put3str("minishell: permision denied: ", input[0], "\n");	
		return (1);
	}
	return (0);
}

int		is_bin(char **input, t_env *m_env)
{
	struct stat st;
	char		**path;
	char		*exc;
	int			i;

	i = 0;
	path = ft_strsplit(get_var("PATH", m_env), ':');
	while (path && path[i])
	{
		if (is_first_word(path[i], input[0]))
			exc = ft_strdup(input[0]);
		else
			exc = do_path(path[i], input[0]);
		if (lstat(exc, &st) != -1)
		{
			if (check_exec(exc, st, input, m_env))
			{
				free(exc);
				free_tab(&path);
				return (1);
			}
		}
		free(exc);
		i++;
	}
	free_tab(&path);
	return (0);
}

int		ft_check_one_cmd(char **input, t_env **m_env)
{
		int				x;
		struct stat		st;

		x = is_builtin(input, m_env);
		if (x == -1)
			return (-1);
		if (x == 1 || is_bin(input, *m_env))
			return (1);
		printf("**NO BINS**\n");
		if (lstat(input[0], &st) != -1)
			return(check_exec(input[0], st, input, *m_env));
		return (0);
}

int     ft_check_cmds(char **cmds, t_env **m_env)
{
	char		**input;
	int			x;
	int			i;

	i = 0;
	while (cmds[i])
	{
		input = ft_strsplits(cmds[i]);
		x = ft_check_one_cmd(input, m_env);
		if (x == -1)
			return (-1);
		if (x == 0)
			ft_put3str("00minishell: command not found: ", input[0], "\n");
		i++;
	}
	return (1);
}

