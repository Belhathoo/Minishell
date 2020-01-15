
#include "minishell.h"

int     run_setenv(char **input, t_env *m_env)
{
    int     len;
    t_env   *env;

    len = dp_len(input);
    //printf("Len: %d, %s ||\n", len, input[len - 1]);
    if (len == 1)
        display_m_env(&m_env);
    else if (len == 2)
        set_var(input[1], "", m_env);
    else if (len == 3)
        set_var(input[1], input[2], m_env);
    else
        ft_putstr("setenv: Too many arguments.\n");
    return (1);
    }