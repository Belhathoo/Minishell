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

void	ft_clean_lst(t_env **args)
{
	t_env	*h;
	t_env	*n;

	h = *args;
	while (h)
	{
		n = h->next;
        ft_strdel(&h->var);
		free(h);
		h = n;
	}
	free(h);
}

void    display_prompt(void)
{
    ft_putstr("my-sh>>$ ");
}

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
    get_m_env(env, &m_env);
    //m_env = NULL;
    while (1)
    {   
      	pwd = getcwd(buff, 4096);
        printf("\n\t--PWD$ %s\n", pwd);
   		//(m_env) ? printf("|%s|\n",m_env->var) : printf("No env!\n");
        display_prompt();
        if (!get_next_line(0, &input))
        {
            free (input);
            continue;
        }
        cmds = ft_strsplit(input, ';');;
        if (ft_check_cmds(cmds, m_env) == -1)
        {
            free_tab(&cmds);
            ft_strdel(&input);
            break;
        }
        ft_strdel(&input);
        free_tab(&cmds);
    }
    ft_clean_lst(&m_env);
    return (0);
}
