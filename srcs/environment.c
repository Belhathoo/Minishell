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
	tt = NULL;
	m_env = NULL;
    curr = create_maillon();
	while (env[i])
    {
        curr->var = ft_strdup(env[i]);
		ft_alloc(&m_env, &curr, &tt);
        i++;
    }
	free(curr);
	curr = NULL;
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
			ft_strdel(&t);
			return (tmp);
		}
		tmp = tmp->next;
		ft_strdel(&t);
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
			ft_strdel(&tmp);
			return (ft_strchr(env->var, '=') + 1);
		}
		env = env->next;
		ft_strdel(&tmp);
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
		ft_strdel(&pos->var);
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
		pos = NULL;
	}
	if (value)
     	ft_strdel(&tmp);
}



// int        check_expansions(char **arg, t_env *m_env)
// {
//     int     i;
//     int     j;
//     char    *tmp = NULL;
//     char    *tmp1 = NULL;
//     t_env   *pos;

//     i = 0;
//     if (!arg || !(*arg)[i])
//         return (0);
//     while ((*arg)[i] && (*arg)[i] != '$')
//         i++;
//     if (i == ft_strlen(arg))
//         return (0);
//     if (!(tmp = (char *)ft_memalloc(sizeof(char) * i + 1)))
//         return (0);
//     j = i;
//     i  = 0;
//     while ((*arg)[i])
//     {
//         if (!arg[i + 1] || (*arg)[i] != '$')
//             tmp[i] = (*arg)[i];  
//         else
//         {
//             tmp[i] = '\0';
//             if (!(pos = find_var_pos(arg + i + 1, m_env)))
//             {
//                 ft_strdel(&tmp);
//                 ft_putstr(arg + i + 1);
//                 ft_putendl(": Undefined variable");
//                 break;
//             }
//             else
//             {   
//                 tmp1 = ft_strjoin(tmp, ft_strchr(pos->var, '=') + 1);
//                 free(tmp);
//                 return (tmp1);
//             }
//         }
//         i++;
//     }
//  `



