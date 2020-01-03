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

# define SPA(x) (x == ' ' || x == '\t' || x == '\r' || x == '\f')

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
char	**ft_lstsplit(t_input **s, char c);
char    **ft_lsttoarr(t_input *input);


ft_check_cmds(cmds);


#endif
