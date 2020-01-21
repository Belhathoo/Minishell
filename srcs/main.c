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

int     ft_check_cmds(char **cmds, t_env **m_env)
{
	char		**input;
	int			x;
	int			i;

	i = 0;
	while (cmds[i])
	{
		input = ft_strsplits(cmds[i]);
		if (!input || !(*input))
			return (1);
		x = ft_check_one_cmd(input, m_env);
		if (x == -1)
			return (-1);
		if (x == 0)
			ft_put3str("00minishell: command not found: ", input[0], "\n");
		free_tab(&input);
		i++;
	}
	return (1);
}

/*char    **parser(char ***args)
{

}*/

int     main(int ac, char **av, char **env)
{
    int         i;
    char         *input;
    char        **cmds;
    char        **args;
    t_env       *m_env;


    cmds = NULL;
    input = NULL;
    m_env = get_m_env(env);
    //m_env = NULL;
    while (1)
    {   

        display_prompt();
        if (!get_next_line(0, &input))
        {
            free (input);
            continue;
        }
        cmds = ft_strsplit(input, ';');
       // cmds = parser(&args);
        if (ft_check_cmds(cmds, &m_env) == -1)
        {
            free_tab(&cmds);
            //free(input);
            break;
        }
        //free(input);
        free_tab(&cmds);
    }
    ft_clean_lst(&m_env);
    return (0);
}
