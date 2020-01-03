
#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"


typedef struct          s_input
{
    char                c;
    struct s_input      *next;
}                       t_input;

/*
typedef struct minishell
{
    t_input     *commads;

};
*/
char	**ft_lstsplit(t_input **s, char c);
char    **ft_lsttoarr(t_input *input);


#endif