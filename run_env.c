
#include "minishell.h"

void	display_m_env(void)
{
	int		i;

	i = 0;
	while (m_env[i])
    {
        ft_putstr(m_env[i]);
		ft_putchar('\n');
        i++;
    }
}

int     run_env(char **input)
{
	if (dp_len(input) == 1)
	{
		display_m_env();
		return (1);
	}
	else
		ft_putstr("WORK ON env NOT DONE YET!!\n");
    return (0);
}