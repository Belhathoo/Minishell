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

int     lstlen(t_input *l)
{
	int     size;
	t_input *tt;

	size = 0;
	tt = l;
	while(tt)
	{
		size++;
		tt = tt->next;
	}
	return (size);
}


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
	if (ft_strequ(input[0], "cd"))
		return (run_cd(input, m_env));
	return (0);
}

int     ft_check_cmds(char **cmds, t_env **m_env)
{
	char    **input;
	int		x;
	int     i;
	int		j;

	i = 0;
	while (cmds[i])
	{
		input = ft_strsplits(cmds[i]);
		j = 0;
		if ((x = is_builtin(input, m_env)) == -1)
		{
			free_tab(&input);
			return (-1);
		}
		free_tab(&input);
		i++;
	}
	i = 0;
	return (1);
}

