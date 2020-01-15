
#include "minishell.h"

void	display_m_env(t_env **env)
{
	int		i;
	t_env	*m_env;

	m_env = *env;
	i = 0;
	while (m_env)
    {
        ft_putstr(m_env->var);
		ft_putchar('\n');
        m_env = m_env->next;
    }
}

int     run_env(char **input, t_env *m_env)
{
	if (dp_len(input) == 1)
	{
		display_m_env(&m_env);
		return (1);
	}
	else
		ft_putstr("env: Too many arguments.\n");
    return (0);
}