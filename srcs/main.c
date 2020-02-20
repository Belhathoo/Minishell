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
    char    *pwd;
    char	buff[4097];
    //pwd = getcwd(buff, 4096);
    //printf("\n\t--PWD$ %s\n", pwd);
    ft_putstr("my.sh>>$ ");
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
		//printf("**NO BINS**\n");
		if (lstat(input[0], &st) != -1)
			return(check_exec(input[0], st, input, *m_env));
		return (0);
}

int     ft_check_cmds(t_cmds *cmds, t_env **m_env)
{
	int			x;

	// while (cmds)
	// {
		if (!cmds || !(cmds->argv) || !(*cmds->argv))
		 	return (1);
		x = ft_check_one_cmd(cmds->argv, m_env);
		if (x == -1)
			return (-1);
		if (x == 0)
			ft_put3str("00minishell: command not found: ", cmds->argv[0], "\n");
		//free_tab(&input);
		//cmds  cmds->next;
	//}
	return (1);
}

int    check_quotes(char *input)
{
    int i;
    int q;
    int dq;

    i = 0;
    q = 0;
    dq = 0;
    while (input[i])
    {
        if (input[i] == '"' && !(q % 2))
            dq++;
        if (input[i] == '\'' && !(dq % 2))
            q++;
        i++;
    }
    if (dq % 2 == 1 || q % 2 == 1)
    {
        ft_putendl("Unmatched quote (' or \").");
        return (0);
    }
    return (1);
}

int     main(int ac, char **av, char **env)
{
    char        *input;
    t_cmds      *cmds;
    t_env       *m_env;

    input = NULL;
    //cmds = create_node();
    m_env = get_m_env(env);
    //m_env = NULL;
    
    
    while (1)
    {   

        display_prompt();
        if (!get_next_line(0, &input) || !check_quotes(input))
        {
            free (input);
            continue;
        }
        cmds = parse_cmd(input, m_env);
        if (ft_check_cmds(cmds, &m_env) == -1)
        {
            free_tab(&cmds->argv);
            //free(input);
            break;
        }
        //free(input);
        free_tab(&cmds->argv);
    }
    ft_clean_lst(&m_env);
    return (0);
}
