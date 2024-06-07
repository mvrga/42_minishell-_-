/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:43:04 by jveras            #+#    #+#             */
/*   Updated: 2024/06/07 17:08:02 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*init_env(char **environ)
{
	t_env	*env;
	int		i;

	env = ft_calloc(sizeof(t_env), 1);
	if (!env)
	{
		ft_putstr_fd("Error: Alocating memory: init_env()\n", 2);
		return (NULL);
	}
	env->env_var_s = NULL;
	env->next = NULL;
	i = 0;
	while (environ[i])
	{
		append_env_var(env, environ[i]);
		i++;
	}
	return (env);
}

void	append_env_var(t_env *env, char *env_s)
{
	t_env	*current;
	t_env	*new_env_var;

	if (!env->env_var_s)
	{
		env->env_var_s = env_s;
		env->next = NULL;
		return ;
	}
	current = env;
	while (current->next)
		current = current->next;
	new_env_var = ft_calloc(sizeof(t_env), 1);
	if (!new_env_var)
	{
		ft_putstr_fd("Error: Alocating memory: append_env_var()\n", 2);
		return ;
	}
	new_env_var->env_var_s = env_s;
	new_env_var->next = NULL;
	current->next = new_env_var;
}

void	list_remove_if(t_env **env, char *str, int (*cmp)(const char *,
			const char *, size_t))
{
	t_env	*current;
	t_env	*previous;

	current = *env;
	previous = NULL;
	if (!env || !*env || !str || !cmp)
		return ;
	while (current && cmp(str, current->env_var_s, ft_strlen(str)) != 0)
	{
		previous = current;
		current = current->next;
	}
	if (!current)
		return ;
	if (previous)
	{
		previous->next = current->next;
		free(current);
		return ;
	}
	*env = current->next;
	free(current);
}
