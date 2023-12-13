#include "minishell.h"

/**
 * ft_child_signal - ft_child_signal
 * @signo: sign
*/

void ft_child_signal(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, ft_child_signal);
	}
}


/**
 * ft_signal - ft_signal
 * @signo: sign
*/

void ft_signal(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		prompt();
		signal(SIGINT, ft_signal);
	}
}
