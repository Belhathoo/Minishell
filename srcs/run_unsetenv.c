/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:30:34 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/20 18:30:47 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void		unset_var(char *var, t_env **m_env)
{
	t_env	*env;
	t_env	*previous;
	t_env	*tmp;
    char    *name;

	if ((*m_env) == NULL)
		return ;
	previous = (*m_env);
	name = ft_strjoin(var, "=");
    if (is_first_word(previous->var, name))
	{
		(*m_env) = previous->next;
		free(previous->var);
		free(previous);
        previous = NULL;
		return ;
	}
	tmp = previous->next;
	while (tmp)
	{
		if (is_first_word(tmp->var, name))
		{
            previous->next = tmp->next;
			free(tmp->var);
			free(tmp);
			return ;
		}
		previous = tmp;
		tmp = tmp->next;
	}
}

int     run_unsetenv(char **input, t_env **m_env)
{
    int     len;
    int     i;
    t_env   *env;

    i = 1;
    env = *m_env;
    len = dp_len(input);
    if (len == 1)
        ft_putendl("unsetenv: Too few arguments.");
    else
    {
        while (input[i])
        {
            unset_var(input[i], m_env);
            i++;
        }
    }
    if (env)
        (*m_env) = env;
    return (1);
}


/*
element* supprimerElement(element* list, int valeur)
{
element  *tmp;
element  *previous;
 
if (list == NULL) // si la liste est NULL on s'arrete tout de suite
  return (list);
previous = list;
if (previous->data == valeur) // Verifie la tete de liste, cas particulier
{
  liste = previous->next;
  free(previous);
  return (list);
}
tmp = previous->next; // le cas n est gere on se place donc sur le cas n+1
while(tmp != NULL) // On Mouline est on supprime si on trouve l'element
{
  if (tmp->data == valeur)
  {
    previous->next = tmp->next;
    free(tmp);
    return (liste);
  }
  previous = tmp; // pour ce souvenir dans la prochaine iteration du precedent
  tmp = tmp->next;
}
return liste;
}*/