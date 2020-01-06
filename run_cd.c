
#include "minishell.h"

void    ft_chdir(char *path)
{
    char    *home;

    if (!(ft_strcmp(path, "home")))
    {
        home = get_var("HOME");
        if((chdir(home) == 0))            /// chdir = 0 || -1(errno)
            return ;
    //    ft_strdel(&home);
    }
}

int		run_cd(char	**input)
{
	int		len;

	len = dp_len(input);
	if (len == 1)
	{
		ft_chdir("home");
		return (1);
	}
	else if (len == 2)
	{
		ft_chdir(input[1]);
		return (1);
	}
	else
		ft_putstr("cd: Too many arguments.\n");
	return (0);
}


