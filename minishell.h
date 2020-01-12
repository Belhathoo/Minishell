/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:19:17 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/03 15:19:21 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"


char    **m_env;


typedef struct          s_input
{
    char                c;
    struct s_input      *next;
}                       t_input;

/*
typedef struct minishell
{
    t_input     *commads;

};
*/

void    get_m_env(char **env);
void	display_m_env(void);

char    *get_var(char *name);
void    set_var(char *name, char *value);


char	**ft_lstsplit(t_input **s, char c);
char    **ft_lsttoarr(t_input *input);

int     lstlen(t_input *l);



int     ft_check_cmds(char **cmds);

int     run_setenv(char **input);
int     run_env(char **input);
int		run_cd(char	**input);


int     dp_len(char **env);
void	free_tab(char ***tab);
void	ft_clean_lst(t_input **args);

#endif
