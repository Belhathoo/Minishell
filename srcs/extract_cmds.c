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
//	if (ft_strequ(input[0], "cd"))
//		return (run_cd(input, m_env));
	return (0);
}


int		run_cmd(char *cmd, char **input, t_env *env)
{
	pid_t	pid;
	char	**m_env;

	m_env = ft_lsttoarr(env);
	pid = fork();
	if (pid == 0)
		execve(cmd, input, m_env);
	else if (pid < 0)
	{
		free(cmd);
		ft_putendl("Fork failed to create a new process.");
		return (-1);
	}
	wait(&pid);
	if (cmd)
		free(cmd);
	return (0);
}

int		is_bin(char **input, t_env *m_env)
{
	struct stat *st;
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
		if (lstat(exc, st) == -1)
			free(exc);
		else if (run_cmd(exc, input, m_env))
		{
			ft_strdel(&exc);
			free_tab(&path);
			return (1);
		}
		else
			free(exc);
		i++;
	}
	free_tab(&path);
	return (0);
}

int     ft_check_cmds(char **cmds, t_env **m_env)
{
	char		**input;
	struct stat	st;
	int			x;
	int			i;

	i = 0;
	while (cmds[i])
	{
		input = ft_strsplits(cmds[i]);
		x = is_builtin(input, m_env);
		if (x == -1)
		{
			free_tab(&input);
			return (-1);
		}
		if (x == 1 || is_bin(input, m_env))
		{

		}
		else if (lstat(input[0], &st) != -1)
		{
			if (st.st_mode & S_IXUSR)
				run_cmd (input[0], input);
		}
		else
			ft_put2str("minishell: command not found: ", input[0], 0);
		free_tab(&input);
		i++;
	}
	return (1);
}

