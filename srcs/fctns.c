/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:42:24 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/16 14:42:27 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

/*int     lstlen(t_input *l)
{
	int     size;
	t_input *tt;

	size = 0;
	tt = l;
	while(tt)
	{
		size++;
		tt = tt->next;
	}
	return (size);
}*/


char	*do_path(char *name, char *d_name)
{
	char	*path;
	char	*tmp;

	if ((name[0] == '/' && name[1] == '\0') ||
					name[ft_strlen(name) - 1] == '/' || d_name[0] == '/')
		path = ft_strjoin(name, d_name);
	else
	{
		tmp = ft_strjoin(name, "/");
		path = ft_strjoin(tmp, d_name);
		ft_strdel(&tmp);
	}
	return (path);
}

t_env         *create_maillon(void)
{
    t_env *l;

     l = (t_env *)malloc(sizeof(t_env));
     l->next = NULL;
    return (l);
}

void            ft_alloc(t_env **param, t_env **curr, t_env **tt)
{
        if ((*param) == NULL)
        {
    			printf("1st\n");
	            (*param) = create_maillon();
                (*tt) = (*param);
                (*param)->var = ft_strdup((*curr)->var);
        }
        else
        {
				printf("2nd\n");
                (*param)->next = create_maillon();
                (*param)->next->var = ft_strdup((*curr)->var);
                (*param) = (*param)->next;
        }
}

int		is_first_word(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

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

void	ft_clean_lst(t_env **args)
{
	t_env	*h;
	t_env	*n;

	h = *args;
	while (h)
	{
		n = h->next;
        ft_strdel(&h->var);
		free(h);
		h = n;
	}
	free(h);
}
void    ft_put3str (char *s1, char *s2, char *s3)
{
    ft_putstr(s1);
    ft_putstr(s2);
    ft_putstr(s3);
}

char    **ft_lsttoarr(t_env *env)
{
        char    *str;
        char    **m_env;
        int     i;

        i = 0;
        if (!env)
            return (NULL);
        if (!(str = (char *)malloc(lstlen(env) + 1)))
                return (NULL);
        while (env)
        {
                str[i] = env->var;
                i++;
                env = env->next;
        }
        str[i] = '\0';
        return (m_env);
}