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

void    display_prompt(void)
{
    ft_putstr("\nmy.sh>>$ ");
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
    m_env = get_m_env(env);
    //m_env = NULL;
    while (1)
    {   
      	//pwd = getcwd(buff, 4096);
        //printf("\n\t--PWD$ %s\n", pwd);
        display_prompt();
        if (!get_next_line(0, &input))
        {
            free (input);
            continue;
        }
        cmds = ft_strsplit(input, ';');;
        if (ft_check_cmds(cmds, &m_env) == -1)
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
