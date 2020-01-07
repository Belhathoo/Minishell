
# include "minishell.h"

static void		realloc_env(int new_size)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (new_size + 1));
	i = -1;
	while (m_env[++i] && i < new_size)
	{
		new[i] = ft_strdup(m_env[i]);
		free(m_env[i]);
	}
	free(m_env);
	m_env = new;
//	return (new);
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
	tmp = ft_strjoin("=", value);
	if (m_env[pos])
	{
		free(m_env[pos]);
		if (value != NULL)
			m_env[pos] = ft_strjoin(name, tmp);
		else
			m_env[pos] = ft_strjoin(name, "=");
	}
	else
	{
		realloc_env(pos + 1);
		if (value != NULL)
			m_env[pos] = ft_strjoin(name, tmp);
		else
			m_env[pos] = ft_strjoin(name, "=");
	}
	free(tmp);
}