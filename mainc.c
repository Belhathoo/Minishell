/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:18:47 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/03 15:18:56 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int     dp_len(char **env)
{
    int i;

    i = 0;
    while (env[i])
        i++;
    return (i);
}

void	free_tab(char ***tab)
{
	int		i;
	char	**tmp;

	tmp = *tab;
	i = 0;
	while (tmp[i])
	{
		ft_strdel(&tmp[i]);
		i++;
	}
	free(tmp);
	tmp = NULL;
}

void	ft_clean_lst(t_input **args)
{
	t_input	*h;
	t_input	*n;

	h = *args;
	while (h)
	{
		n = h->next;
		free(h);
		h = n;
	}
	free(h);
}

void    display_prompt(void)
{
    ft_putstr("my-sh>>$ ");
}


/*char       *get_input(void)
{
//    char        buff;
 //   int         nb_oct;
    char        *input;

    if(!get_next_line(0, &input))
        return (NULL);
    return (input);
}*/

int     main(int ac, char **av, char **env)
{
    int         i;
    char         *input;
    char        **cmds;
    t_env       *m_env;
    char    *pwd;
	char	buff[4097];

    cmds = NULL;
    input = NULL;
    m_env = get_m_env(env);
    while (1)
    {   
      	pwd = getcwd(buff, 4096);
        printf("\n\t--PWD$ %s\n", pwd);
        display_prompt();
        if (!get_next_line(0, &input))
        {
            free (input);
            continue;
        }

        cmds = ft_strsplit(input, ';');;
        /*i = 0;
        while (cmds[i])
        {
            printf("HERE|%s|\n", cmds[i]);
            i++;
        }*/
        if (ft_check_cmds(cmds, &m_env) == -1)
        {
            free_tab(&cmds);
            ft_strdel(&input);
            break;
        }
        ft_strdel(&input);
        free_tab(&cmds);
    }
    return (0);
}
