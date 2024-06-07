/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:07:19 by jveras           #+#    #+#             */
/*   Updated: 2024/06/07 14:28:30 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	go_to_home(t_env *env)
{
	t_env	*current;

	current = env;
	while (current)
	{
		if (ft_strncmp(current->env_var_s, "HOME=", 5) == 0)
		{
			chdir(current->env_var_s + 5);
		}
		current = current->next;
	}
}

static void	custom_chdir(char *path)
{
	if (chdir(path) == -1)
	{
		ft_printf("cd: no such file or directory: %s\n", path);
	}
}

void	cd(t_word *data, t_env *env)
{
	if (ft_strncmp(data->word, "cd", ft_strlen(data->word)) == 0)
	{
		if (!data->next)
		{
			go_to_home(env);
			return ;
		}
		else if (ft_strncmp("~", data->next->word,
				ft_strlen(data->next->word)) == 0)
		{
			go_to_home(env);
			return ;
		}
		custom_chdir(data->next->word);
	}
}
