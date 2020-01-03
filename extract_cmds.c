

# include "minishell.h"

int     lstlen(t_input **l)
{
    int     size;
    t_input *tt;
    
    size = 0;
    tt = *l;
    while(tt)
    {
        size++;
        tt = tt->next;
    }
    return (size);
}

char    **ft_lsttoarr(t_input *input)
{
    t_input *tt;
    char    *str;
    char    **cmds;
    int     i;

    i = 0;
    tt = input;
    if (!input)
        return (NULL);
    if (!(str = (char *)malloc(lstlen(&input) + 1)))
        return (NULL);
    while (input)
    {
        str[i] = input->c;
        i++;
        input = input->next;
    }
    str[i] = '\0';
    cmds = ft_strsplit(str, ';');
    return (cmds);
}