
# include "minishell.h"

int	ft_lstword_size(t_input *str, char c)
{
	int		word_size;

	word_size = 0;
	while (str && str->c != c)
	{
		word_size++;
		str = str->next;
	}
    printf("lstwrd: %d\t%c\n", word_size, str->c);
	return (word_size);
}

int		ft_nbr_lstwords(t_input *str, char c)
{
	int		nbr;
	int		i;
    t_input *tt;
    tt = str;
	nbr = 0;
	i = 0;
	if (!str)
		return (0);
	while (str)
	{
		if (str && str->c != c)
		{

			ft_lstword_size(str, c);
			str = str->next;
            nbr++;
		}
		else
			str = str->next;
	}
    str = tt;
	return (nbr);
}

char	**ft_lstsplit(t_input **lst, char c)
{
	int		i[3];
	char	**new_s;
    t_input *s;
    t_input *tt;
	i[0] = 0;
	i[2] = 0;
    s = (*lst);
	if (!s || s->c == '\0')
		return (NULL);
	tt = s;
    if (!(new_s = (char **)malloc((ft_nbr_lstwords(s, c) + 1) * sizeof(char*))))
		return (NULL);
    s = tt;

	while (s)
	{
		while (s && s->c == c)
			s = s->next;
        if (s)
		{
    		tt = s;
			if (!(new_s[i[0]] = (char *)malloc(ft_lstword_size(s, c) + 1)))
				return (NULL);
			printf("mpmp\n");
            s = tt;
            while (s && s->c != c)
            {
            printf("hjhj\n");
            	new_s[i[0]][i[1]++] = s->c;
                s = s->next;
            }
            new_s[i[0]++][i[1]] = '\0';
		}
	}
  //  free(s);
	new_s[i[0]] = 0;
	return (new_s);
}