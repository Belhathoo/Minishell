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

char	**ft_strsplits(char const *s)
{
	int		i[3];
	char	**new_s;

	i[0] = 0;
	i[2] = 0;
	if (s == NULL)
		return (NULL);
	if (!(new_s = (char **)malloc((ft_nbr_words(s,) + 1) * sizeof(char*))))
		return (NULL);
	while (s[i[2]])
	{
		while (s[i[2]] == c && s[i[2]])
			i[2]++;
		if (s[i[2]])
		{
			i[1] = 0;
			if (!(new_s[i[0]] = (char *)malloc(ft_word_size(s, c, i[2]) + 1)))
				return (NULL);
			while (s[i[2]] != c && s[i[2]])
				new_s[i[0]][i[1]++] = s[i[2]++];
			new_s[i[0]++][i[1]] = '\0';
		}
	}
	new_s[i[0]] = 0;
	return (new_s);
}


int     ft_check_cmds(cmds)
{
    char    **input;
}

