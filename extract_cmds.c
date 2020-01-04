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

int     ft_check_cmds(char **cmds)
{
	char    **input;
	int     i;

	i = 0;
//	input = (char ***)malloc(sizeof(char **));
	while (cmds[i])
	{
		input = ft_strsplits(cmds[i]);
		/// check 1st input & exec then ++ //
		i++;
	}
	i = 0;
	while(input[i])
	{
		printf("** %s **\n",input[i]);
		i++;
	}
}

