/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:19:17 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/15 20:14:45 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"



typedef struct          s_input
{
    char                c;
    struct s_input      *next;
}                       t_input;

typedef struct          s_env
{
    char                *var;
    struct s_env        *next;
}                       t_env;



t_env         *create_maillon(void);
void            ft_alloc(t_env **param, t_env **curr, t_env **tt);

void    get_m_env(char **env, t_env **m_env);
void	display_m_env(t_env **m_env);

char    *get_var(char *name, t_env *m_env);
void    set_var(char *name, char *value, t_env *m_env);


char	**ft_lstsplit(t_input **s, char c);
char    **ft_lsttoarr(t_input *input);



int     ft_check_cmds(char **cmds, t_env *m_env);

int     run_setenv(char **input, t_env *m_env);
int     run_env(char **input, t_env *m_env);
int		run_cd(char	**input, t_env *m_env);


int     dp_len(char **env);
void	free_tab(char ***tab);
void	ft_clean_lst(t_env **args);
int     lstlen(t_input *l);
#endif
