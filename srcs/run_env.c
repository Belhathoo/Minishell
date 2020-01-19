/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:42:13 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/16 14:42:17 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_m_env(t_env *env)
{
	int		i;
	t_env	*m_env;

	m_env = env;
	i = 0;
	while (m_env)
    {
        ft_putstr(m_env->var);
		ft_putchar('\n');
        m_env = m_env->next;
    }
}

int     run_env(char **input, t_env *m_env)
{
	if (dp_len(input) == 1)
		display_m_env(m_env);
	else
		ft_putstr("env: Too many arguments.\n");
    return (1);
}
