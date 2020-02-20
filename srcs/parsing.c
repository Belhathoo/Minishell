
# include "minishell.h"

/*
    balance = 0
    if " balance != 2 && (balance == 0) ? balance = 1 : 0
    if ' balance != 1 && (balance == 0) ? balance = 2 : 0
*/

char    *ft_strndup_cmd(char *cmd, size_t n)
{
    char *arg;
    size_t i;
    size_t j;
    int balance = 0;

    if (!(arg = (char*)ft_memalloc(sizeof(char) * (n + 1))))
        return (NULL);
    i = 0;
    j = 0;
    while (i < n)
    {
        if (cmd[i] == '"' && balance != 2)
            balance = (balance == 0) ? 1 : 0;
        if (cmd[i] == '\'' && balance != 1)
            balance = (balance == 0) ? 2 : 0;
        if (cmd[i] == '"' && balance != 2)
            i += (cmd[i + 1] == '"') ? 2 : 1; 
        if (cmd[i] == '\'' && balance != 1)
            i += (cmd[i + 1] == '\'') ? 2 : 1;
        if (!balance && cmd[i] == ' ')
            break ;
        // if (!balance && cmd[i] == ';')
        //     break ;
        arg[j] = cmd[i];
        j++;
        i++;
    }
    arg[j] = '\0';
    return (arg);
}


char    *get_next_argument(char *line, size_t *i, int *pv)
{
    char    *arg;
    char    *a;
    int balance = 0;
    int j;
    
    while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
        (*i)++;
    if (!line[*i])
        return (NULL);
    j = *i;
    while (line[*i])
    {
        if (line[*i] == '"' && balance != 2)
            balance = (balance == 0) ? 1 : 0;
        if (line[*i] == '\'' && balance != 1)
            balance = (balance == 0) ? 2 : 0;
        // if (line[*i] == ';' && !balance)
        // {
        //    (*pv) = 1;
        //     break ;
        // }
        if (line[*i] == ' ' && !balance)
           break ;
        (*i)++;
    } 
    
    arg = ft_strndup_cmd(&line[j], (*i) - j);
    return (arg);
}

char    **join_array(char **array, char *arg)
{
    char    **new_array;
    size_t  i;

    i = 0;
    if (array)
        while (array[i])
            i++; 
    if (!(new_array = (char**)ft_memalloc(sizeof(char*) * (i + 2))))
        return (NULL);
    i = 0;
    while (array && array[i])
    {
        new_array[i] = array[i];
        i++;
    }
    new_array[i] = arg;
    new_array[i + 1] = NULL;
    if (array)
        free(array);
    return (new_array);
}

int		expansions_check(char **arg, t_env *m_env)
{
	int		i;
    int     j;
	t_env	*pos;
    char    *tmp;

	i = 0;
    j = 0;
	if (!ft_strcmp(*arg, "$") || !ft_strchr((*arg), '$'))
		return (1);
    while ((*arg)[i] && (*arg)[i] != '$')
        i++;
    if (!(*arg)[i + 1])
        return (1);
    pos = find_var_pos(ft_strchr((*arg), '$') + 1, m_env);
	if (!pos)
	{
		ft_putstr((*arg) + i + 1);
        ft_putendl(": Undefined variable");
		return (0);
	}
    tmp = (char *)ft_memalloc(i + ft_strlen(pos->var) + 1);
    while ((*arg)[i] && (*arg)[i] != '$')
    {
        tmp[j] = (*arg)[i];
        j++;
        i++;
    }
    i = 0;
    while (pos->var[i])
    {
        tmp[j] = pos->var[i];
        j++;
        i++;
    }
    tmp[j] = '\0';
    ft_strdel(arg);
    (*arg) = tmp;
    return (1);
}

t_cmds      *parse_cmd(char *line, t_env *m_env)
{
    size_t      i;
    int         pv = 0;
    char        *arg;
    t_cmds      *cmds;
    t_cmds      *head = NULL;

    i = 0;
    cmds = create_node();
    head = cmds;
    while ((arg = get_next_argument(line, &i, &pv)))
    {
        if (expansions_check(&arg, m_env) == 0)
        {
            free_tab(&cmds->argv);
            free(cmds);
            ft_strdel(&arg);
            return (NULL);
        }
        printf("|%s\n", arg);
        cmds->argv = join_array(cmds->argv, arg);
        // if (pv != 0)
        // {
        //     printf("next\n");
        //     cmds->next = create_node();
        //     cmds->next->argv = join_array(cmds->next->argv, arg);
        //     cmds = cmds->next;
        //     if (line[i] == ';' && line[i + 1])
        //         i++;
            
        // }     
        // else
        //printf("|%s\n", arg);
        // pv = 0;
    }
    ft_strdel(&arg);
    cmds = head;
    return (cmds);
}





int main(int ac, char **av, char **env)
{
    //char **arg;
    t_cmds *cmds;
    t_env   *m_env;

    m_env = get_m_env(env);
    cmds = parse_cmd(av[1], m_env);
    
    size_t i;
    while (cmds && cmds->argv)
    {
        i = 0;
        while (cmds->argv[i])
        {
            printf("arg[%zu] = '%s'\t", i, cmds->argv[i]);
            i++;
        }
        printf("\n");
        cmds = cmds->next;
    }
}



// char    **parser(char *input, int len)
// {
//     int     i;
//     int     j;
//     int     k;
//     char    **q_args;

//     i = 0;
//     j = 0;
//    	if (!input || !*input)
// 		return (NULL);
//     if (!(q_args = (char**)malloc(sizeof(char *) * len)))
//         return (NULL);
//     while (input[i])
//     {
//         if (input[i] == '"')
//         {
//             i++;
//             q_args[j] = (char*)malloc(sizeof(char) * ft_word_size(input, '"', i + 1));
//             while (input[i] != '"' && input[i+1])
//             {
//                 k = 0;
//                 q_args[j][k] = input[i];
//                 k++;
//             }
//         }
//         j++;
//         i++;
//     }
//     q_args[j] = NULL;   
//     j = 0;
//     while(q_args && q_args[j])
//         printf("|%s\n", q_args[j++]);
//     return (q_args);
// }