
# include "minishell.h"

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
                (*param) = create_maillon();
                (*tt) = (*param);
                (*param)->var = (*curr)->var;
        }
        else
        {
                (*param)->next = create_maillon();
                (*param)->next->var = (*curr)->var;
                (*param) = (*param)->next;
        }
}

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

static int		is_first_word(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

t_env		*find_var_pos(char *var, t_env *m_env)
{
	char	*t;
	t_env	*tmp;

	tmp = m_env;
	while (tmp)
	{
		printf("LOLO\n");
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

void	set_var(char *name, char *value, t_env **m_env)
{
	t_env		*pos;
	t_env		*env;
	char		*tmp;

	env = *m_env;
	
	pos = find_var_pos(name, env);
	//printf("LOLO%s; \n",pos->var);
	//env = *m_env;
	if (value)
     	tmp = ft_strjoin("=", value);
	if (pos)
	{
		free(pos);
		if (value)
			pos->var = ft_strjoin(name, tmp);
		else
			pos->var = ft_strjoin(name, "=");
	}
	else
	{
		pos = create_maillon();
		if (value)
			pos->var = ft_strjoin(name, tmp);
		else
			pos->var = ft_strjoin(name, "=");
		while (*m_env)
			(*m_env) = (*m_env)->next;
		(*m_env) = pos;
	}
	printf("//m_env(pos): %s\n",  pos->var);
	if (value)
     	free(tmp);
	//*m_env = env;
}