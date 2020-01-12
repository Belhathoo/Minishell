
# include "minishell.h"

void    get_m_env(char **env)
{
    int i;

    i =0;
    m_env = (char **)malloc(sizeof(char *) * (dp_len(env) + 1));
    while (env[i])
    {
        m_env[i] = ft_strdup(env[i]);
        i++;
    }
   m_env[i] = NULL;
}

static char		**realloc_env(int new_size)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (new_size + 1));
	i = 0;
	while (m_env[i])
	{
		new[i] = ft_strdup(m_env[i]);
		free(m_env[i]);
		i++;
	}
	new[i + 1] = NULL;
	free(m_env);
	return (new);
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

int		find_var_pos(char *var)
{
	int		i;
	char	*tmp;

	i = 0;
	while (m_env[i])
	{
		tmp = ft_strjoin(var, "=");
		if (is_first_word(m_env[i], tmp))
		{
			free(tmp);
			return (i);
		}
		i++;
		free(tmp);
	}
	return (i);
}

char            *get_var(char *name)
{
   	int		i;
	char	*tmp;

	i = -1;
	while (m_env[++i])
	{
		tmp = ft_strjoin(name, "=");
		if (is_first_word(m_env[i], tmp))
		{
			free(tmp);
			return (ft_strchr(m_env[i], '=') + 1);
		}
		free(tmp);
	}
	return (NULL);
}

void	set_var(char *name, char *value)
{
	int		pos;
	char	*tmp;

	pos = find_var_pos(name);
	if (value)
     	tmp = ft_strjoin("=", value);
	if (m_env[pos])
	{
		free(m_env[pos]);
		if (value)
			m_env[pos] = ft_strjoin(name, tmp);
		else
			m_env[pos] = ft_strjoin(name, "=");
	}
	else
	{
		m_env = realloc_env(pos + 1);
		if (value)
			m_env[pos] = ft_strjoin(name, tmp);
		else
			m_env[pos] = ft_strjoin(name, "=");
	}
//	printf("//m_env(pos)%d: %s\n", pos,  m_env[pos]);
	if (value)
     	free(tmp);
}