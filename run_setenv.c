
#include "minishell.h"

int     run_setenv(char **input)
{
    int     len;

    len = dp_len(input);
    printf("Len: %d, %s ||\n", len, input[len - 1]);
    if (len == 1)
        display_m_env();
    else if (len == 2)
        set_var(input[1], "");
    else if (len == 3)
        set_var(input[1], input[2]);
    else
        ft_putstr("setenv: Too many arguments.\n");
    return (1);
    }