/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:42:37 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/16 14:42:39 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"


t_env			*get_m_env(char **env)
{
    int		i;
	t_env	*curr;
	t_env	*tt;
	t_env	*m_env;

    i =0;
    curr = create_maillon();
	while (env[i])
    {
        curr->var = ft_strdup(env[i]);
		ft_alloc(&m_env, &curr, &tt);
        i++;
    }
	free(curr);
	m_env = tt;
	return (m_env);
}

t_env		*find_var_pos(char *var, t_env *m_env)
{
	char	*t;
	t_env	*tmp;

	tmp = m_env;
	while (tmp)
	{
		t = ft_strjoin(var, "=");
		if (is_first_word(tmp->var, t))
		{
			free(t);
			return (tmp);
		}
		tmp = tmp->next;
		free(t);
	}
	return (NULL);
}

char            *get_var(char *name, t_env *m_env)
{
   	int		i;
	char	*tmp;
	t_env	*env;

	env = m_env;
	i = -1;
	while (env)
	{
		tmp = ft_strjoin(name, "=");
		if (is_first_word(env->var, tmp))
		{
			free(tmp);
			return (ft_strchr(env->var, '=') + 1);
		}
		env = env->next;
		free(tmp);
	}
	return (NULL);
}

void		set_var(char *name, char *value, t_env **env)
{
	t_env		*pos;
	t_env		*tt;
	t_env		*m_env;
	char		*tmp;
			
	pos = find_var_pos(name, *env);
	if (value)
     	tmp = ft_strjoin("=", value);
	if (pos)
	{
		free(pos->var);
		if (value)
			pos->var = ft_strjoin(name, tmp);
		else
			pos->var = ft_strjoin(name, "=");
	}
	else
	{
		tt = *env;
		pos = create_maillon();
		if (value)
			pos->var = ft_strjoin(name, tmp);
		else
			pos->var = ft_strjoin(name, "=");
		while (*env && (*env)->next)
			(*env) = (*env)->next;
		ft_alloc(env, &pos, &tt);
		*env = tt;
		free (pos);
	}
	if (value)
     	free(tmp);
}









