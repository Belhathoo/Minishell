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

t_input         *create_maillon(void)
{
    t_input *l;

     l = (t_input *)malloc(sizeof(t_input));
     l->next = NULL;
    return (l);
}

void            ft_alloc(t_input **param, t_input **curr, t_input **tt)
{
        if ((*param) == NULL)
        {
                (*param) = create_maillon();
                (*tt) = (*param);
                (*param)->c = (*curr)->c;
        }
        else
        {
                (*param)->next = create_maillon();
                (*param)->next->c = (*curr)->c;
                (*param) = (*param)->next;
        }
}

t_input    *get_input(void)
{
    char        buff;
    int         nb_oct;
    t_input     *input;
    t_input     *tt;
    t_input     *curr;

    tt = NULL;
    input = NULL;
    curr = create_maillon();
    while ((nb_oct = read(0, &buff, 1)) && buff != '\n')
    {
        curr->c = buff;
        ft_alloc(&input, &curr, &tt);
    }
    free(curr);
    input = tt;
    return (input);
}

int     main(int ac, char **av, char **env)
{
    int         i;
    t_input     *input;
    char        **cmds;

    char    *pwd;
	char	buff[4097];

    i = 0;

    cmds = NULL;
    input = NULL;
    get_m_env(env);
    while (1)
    {   
      	pwd = getcwd(buff, 4096);
     //   printf("\n\t**PWD** %s\n", pwd);
        display_prompt();
        if (!(input = get_input()))
        {
            free (input);
            continue;
        }
        cmds = ft_lsttoarr(input);
        if (ft_check_cmds(cmds) == -1)
        {
            printf("\nQUITTING!\n");
            free_tab(&cmds);
            ft_clean_lst(&input);
            break;
        }
        ft_clean_lst(&input);
        free_tab(&cmds);

        /*while (m_env[i])
        {
            printf("%s\n",m_env[i]);
            i++;
        }*/
    }
    return (0);
}
