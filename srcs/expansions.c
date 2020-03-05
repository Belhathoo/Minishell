
#include "minishell.h"


char	**ft_strsplit0(char const *s, char c)
{
	int		i[3];
	char	**new_s;

	i[0] = 0;
	i[2] = 0;
	if (s == NULL)
		return (NULL);
	if (!(new_s = (char **)malloc((ft_nbr_words(s, c) + 1) * sizeof(char*))))
		return (NULL);
	while (s[i[2]])
	{
		while (s[i[2]] == c && s[i[2]])
			i[2]++;
		if (s[i[2]])
		{
			i[1] = 0;
			if (!(new_s[i[0]] = (char *)malloc(ft_word_size(s, c, i[2]) + 2)))
				return (NULL);
			if (s[i[2] - 1] == c)
				new_s[i[0]][i[1]++] = s[i[2] - 1];
			while (s[i[2]] != c && s[i[2]])
				new_s[i[0]][i[1]++] = s[i[2]++];
			new_s[i[0]++][i[1]] = '\0';
		}
	}
	new_s[i[0]] = 0;
	return (new_s);
}

int		expansions_check(char **arg, t_env *m_env)
{
	int		i;
	int     j;
	int k = 0;
	t_env	*pos;
	char    *tmp;
	char    **tab;

	i = 0;
	j = 0;
	if (!ft_strcmp(*arg, "$") || !ft_strchr((*arg), '$'))
		return (1);
	while ((*arg)[i] && (*arg)[i] != '$')
		i++;
	if (!(*arg)[i + 1])
		return (1);
	tab = ft_strsplit0(*arg, '$');
	while (tab[j])
	{
		tab[j] = ft_strtrim(tab[j]);
		if(tab[j][0] == '$')
		{
			pos = find_var_pos(tab[j] + 1, m_env);
			if (!pos)
			{
				ft_putstr(tab[j] + 1);
				ft_putendl(": Undefined variable");
				return (0);
			}
			ft_strdel(&tab[j]);
			tab[j] = ft_strdup(ft_strchr(pos->var, '=') + 1);
		}
		j++;
	}
	//free(*arg);
	i = 0;
	while (tab[i])
	{
		k = k + ft_strlen(tab[i]);
		i++;
	}
	//arg = (char **)ft_memalloc(sizeof(char *));
	(*arg) = (char *)ft_memalloc(k + 1);
	i = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			(*arg)[k] = tab[i][j];
			k++;
			j++;

		}
		i++;
	}
	(*arg)[k] = '\0';
	
//	while (tab[k])
//	{ 
//		printf("%s\n", tab[k]);
//		k++;
//	}
	/*	tmp = (char *)ft_memalloc(i + ft_strlen(ft_strchr(pos->var, '=') + 1));
		i = 0;
		while ((*arg)[i] && (*arg)[i] != '$')
		{
		tmp[j] = (*arg)[i];
		j++;
		i++;
		}
		i = 0;
		while (pos->var[i] != '=')
		i++;
		while (pos->var[i])
		{
		tmp[j] = pos->var[i];
		j++;
		i++;
		}
		tmp[j] = '\0';
		ft_strdel(arg);
		(*arg) = tmp;*/
	return (1);
}






