
# include "minishell.h"

static int		is_first_word(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
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

/*void            *set_var(char *name, char *value)
{

}*/