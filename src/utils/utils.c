/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:25:32 by jveras            #+#    #+#             */
/*   Updated: 2024/06/07 15:55:32 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(t_word *data, t_env *env)
{
	if (ft_strncmp("cd", data->word, ft_strlen(data->word)) == 0)
	{
		cd(data, env);
		return (0);
	}
	else if (ft_strncmp("echo", data->word, ft_strlen(data->word)) == 0)
	{
		echo_command(data);
		return (0);
	}
	else if (ft_strncmp("export", data->word, ft_strlen(data->word)) == 0)
	{
		func_export(data, env);
		return (0);
	}
	else if (ft_strncmp("exit", data->word, ft_strlen(data->word)) == 0)
	{
		ft_exit(data);
		exit(0);
	}
	else if (is_builtin2(data, env) == 0)
		return (0);
	else
		return (1);
}

int	is_builtin2(t_word *data, t_env *env)
{
	if (ft_strncmp("unset", data->word, ft_strlen(data->word)) == 0)
	{
		unset_command(data, env);
		return (0);
	}
	if (ft_strncmp("env", data->word, ft_strlen(data->word)) == 0)
	{
		env_command(data->word, env);
		return (0);
	}
	else if (ft_strncmp("pwd", data->word, ft_strlen(data->word)) == 0)
	{
		pwd(data);
		return (0);
	}
	else
		return (1);
}

void	free_list(t_word *data)
{
	t_word	*tmp;

	while (data)
	{
		tmp = data;
		data = data->next;
		free(tmp->word);
		free(tmp);
	}
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
