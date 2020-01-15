
#include "minishell.h"

void	display_m_env(t_env *m_env)
{
	int		i;
	t_env	*env;

	env = m_env;
	i = 0;
	printf("LALA\n")
	while (env)
    {
        ft_putstr(env->var);
		ft_putchar('\n');
        env = env->next;
    }
	m_env = env;
}

int     run_env(char **input, t_env *m_env)
{
	if (dp_len(input) == 1)
	{
		display_m_env(m_env);
		return (1);
	}
	else
		ft_putstr("env: Too many arguments.\n");
    return (0);
}