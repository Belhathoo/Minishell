#include "minishell.h"

/**
 * ft_free - ft_free
 * @to: to
*/
void ft_free(char ***to)
{
	int i;

	i = -1;
	while (to && (*to) && (*to)[++i])
		free((*to)[i]);
	free((*to));
	(*to) = NULL;
}

/**
 * ft_strdel - ft_strdel
 * @as: as
*/
void ft_strdel(char **as)
{
	if (as == NULL)
		return;
	if (*as)
	{
		free(*as);
		*as = NULL;
	}
}
