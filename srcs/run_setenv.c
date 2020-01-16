/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:42:58 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/16 14:43:01 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     run_setenv(char **input, t_env **m_env)
{
    int     len;
    t_env   *env;

    env = *m_env;
    len = dp_len(input);
    //printf("Len: %d, %s ||\n", len, input[len - 1]);
    if (len == 1)
        display_m_env(*m_env);
    else if (len == 2)
        set_var(input[1], "", m_env);
    else if (len == 3)
        set_var(input[1], input[2], m_env);
    else
        ft_putstr("setenv: Too many arguments.\n");
    if (env)
        (*m_env) = env;
//    if (m_env)
  //      printf("00//%s ..\n", (*m_env)->var);
    return (1);
}
