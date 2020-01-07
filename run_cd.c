
#include "minishell.h"

void    ft_chdir(char *path)
{
    char    *home;
    char    *pwd;
	char	buff[4097];

    home = get_var("HOME");
	pwd = getcwd(buff, 4096);
    if (!(ft_strcmp(path, "home0")))
    {
        chdir(home);            /// chdir = 0 || -1(errno)
		set_var("OLD_PWD", pwd);
        set_var("PWD", home);
    }
	else if (chdir(path) == 0)
	{
		set_var("OLD_PWD", pwd);
		set_var("PWD", getcwd(buff, 4096));
	}
	else
	{
		ft_putstr("cd: ");
		ft_putstr(path);
		if (access(path, F_OK) == -1)
			ft_putstr(": no such file or directory. ");
		else if (access(path, R_OK) == -1)
			ft_putstr("permission denied. ");
		else
			ft_putstr("not a directory. ");
	}
}

int		run_cd(char	**input)
{
	int		len;
	char	*opwd;

	len = dp_len(input);
	if (len == 1)
	{
		ft_chdir("home0");
		return (1);
	}
	else if (len == 2)
	{
		if (!(ft_strcmp(input[1], "--")))
		{
			ft_chdir("home0");
			return (1);
		}
		if (!(ft_strcmp(input[1], "-")))
		{
			opwd  = get_var("OLD_PWD");
			if (!opwd)
				return (1);
			ft_chdir(opwd);
			return (1);
		}
		ft_chdir(input[1]);
		return (1);
	}
	else
		ft_putstr("cd: Too many arguments.\n");
	return (0);
}


