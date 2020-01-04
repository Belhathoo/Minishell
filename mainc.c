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

void    get_m_env(char **env)
{
    int i;

    i =0;
    m_env = (char **)malloc(sizeof(char *) * (dp_len(env) + 1));
    printf("\n\nenvlen = %d\n", dp_len(env));
    while (env[i])
    {
        m_env[i] = ft_strdup(env[i]);
        i++;
    }
   m_env[i] = NULL;
}

void    display_prompt(void)
{
    ft_putstr("&my$sh$>>");
}

t_input         *create_args(void)
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
                (*param) = create_args();
                (*tt) = (*param);
                (*param)->c = (*curr)->c;
        }
        else
        {
                (*param)->next = create_args();
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
    curr = create_args();
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
    i = 0;

    cmds = NULL;
    input = NULL;
    get_m_env(env);
    while (1)
    {   
        display_prompt();
        if (!(input = get_input()))
        {
            free (input);
            continue;
        }
        cmds = ft_lsttoarr(input);
        printf("||%s||\n",cmds[0]);
        ft_check_cmds(cmds);
            
        
        free (input);
        free(cmds);   // !!free all !!




    
    
    /*while (m_env[i])
    {
        printf("%s\n",m_env[i]);
        i++;
    }*/
    }



    return (0);
    
}
