
#include "minishell.h"

int    ft_chdir(char *path, int choix)
{
    char    *tmp;
    char    *pwd;
	char	buff[4097];
	char	buff1[4097];

	pwd = getcwd(buff, 4096);
    if (choix == 0)
    {
    	tmp = get_var("HOME");
		chdir(tmp);
		set_var("PWD", tmp);
		if (strcmp(pwd, tmp))
			set_var("OLD_PWD", pwd);
		return (1);
    }
	else if (choix == -1)
	{
		tmp = get_var("OLD_PWD");
		if(chdir(tmp) == 0)
	    {
			printf("(-)LO%s\tOLD: %s\n", tmp, pwd);
			set_var("PWD", tmp);
		    if (strcmp(pwd, tmp))
				set_var("OLD_PWD", pwd);
			return (1);
		}
	}
	else if (chdir(path) == 0)
	{
		tmp = getcwd(buff1, 4096);
		set_var("PWD", tmp);
		if (strcmp(pwd, tmp))
			set_var("OLD_PWD", pwd);
	    return (1);
	}
	else
	{
		ft_putstr("cd: ");
		ft_putstr(path);
		if (access(path, F_OK) == -1)
			ft_putstr(": no such file or directory. ");
		else if (access(path, R_OK) == -1)
			ft_putstr(": permission denied. ");
		else
			ft_putstr(": not a directory. ");
	}
	return (0);
}

int		run_cd(char	**input)
{
	int		len;
	char	*opwd;

	len = dp_len(input);
	if (len == 1)
	{
		ft_chdir("", 0);
		return (1);
	}
	else if (len == 2)
	{
		if (!(ft_strcmp(input[1], "--")))
		{
			ft_chdir("", 0);
			return (1);
		}
		else if (!(ft_strcmp(input[1], "-")))
		{
			ft_chdir("", -1);
			return (1);
		}
		else
			ft_chdir(input[1], 1);
		return (1);
	}
	else
		ft_putstr("cd: Too many arguments.\n");
	return (0);
}
