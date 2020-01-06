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

char    **ft_lsttoarr(t_input *input)
{
	t_input *tt;
	char    *str;
	char    **cmds;
	int     i;

	i = 0;
	tt = input;
	if (!input)
		return (NULL);
	if (!(str = (char *)malloc(lstlen(input) + 1)))
		return (NULL);
	while (input)
	{
		str[i] = input->c;
		i++;
		input = input->next;
	}
	str[i] = '\0';
	cmds = ft_strsplit(str, ';');
	return (cmds);
}


int		is_builtin(char **input)
{
	if (ft_strequ(input[0], "exit"))
	{
		if (dp_len(input) == 1)
			return (-1);
		else
			ft_putstr("exit : Exxpression Syntax.");
		return (0);
	}
	if (ft_strequ(input[0], "env"))
		return (run_env(input));
//	if (ft_strequ(input[0], "setenv"))
//		return (run_setenv(input));
	if (ft_strequ(input[0], "cd"))
		return (run_cd(input));
	return (0);
}

int     ft_check_cmds(char **cmds)
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
	/*	while(input[j])
		{
			printf("**%s**\t",input[j]);
			j++;
		}
		printf("\n");*/
		if ((x = is_builtin(input)) == -1)
		{
			free_tab(&input);
			return (-1);
		}
		
		/// check 1st input & exec then ++ //
		i++;
	}
	i = 0;

	return (1);
}

