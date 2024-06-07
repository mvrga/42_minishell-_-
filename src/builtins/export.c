/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:26:28 by jveras            #+#    #+#             */
/*   Updated: 2024/06/07 11:54:54 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*add_declare(void *content)
{
	char	*str_content;

	str_content = (char *)content;
	str_content = ft_strjoin("declare -x ", str_content);
	return (str_content);
}

void	sort_env(t_env *env, t_word *word)
{
	t_env	*export_env;
	t_env	*export_lst;

	export_env = ft_lstcopy(env);
	if (!export_env)
		return ;
	ft_sortlist(export_env, ft_strcmp);
	export_lst = ft_lstmap(export_env, add_declare, free);
	ft_lstclear(&export_env, free);
	func_env(export_lst, word);
	ft_lstclear(&export_lst, free);
}

int	update_var(char *arg, t_env *env)
{
	t_env	*aux;
	int		j;

	aux = env;
	while (env)
	{
		j = many_char(env->env_var_s, '=');
		if (!ft_strncmp(env->env_var_s, arg, j))
		{
			free(env->env_var_s);
			env->env_var_s = ft_strdup(arg);
			return (1);
		}
		env = env->next;
	}
	env = aux;
	return (0);
}

int	export_cmd(t_word *export, t_env *env)
{
	t_env				*node;
	extern unsigned int	g_exit_status;

	g_exit_status = 0;
	while (export)
	{
		if (ft_isdigit(*export->word))
		{
			printf("minishell: export: `%s`: "
				"not a valid identifier\n", export->word);
			g_exit_status = 1;
		}
		else if (!update_var(export->word, env))
		{
			node = ft_lstnew_env(ft_strdup(export->word));
			if (!node)
			{
				ft_lstclear(&node, free);
				return (g_exit_status);
			}
			ft_lstadd_back_env(&env, node);
		}
		export = export->next;
	}
	return (g_exit_status);
}

int	func_export(t_word *word, t_env *env)
{
	extern unsigned int	g_exit_status;
	t_word				*export;

	export = word->head;
	if (!export->next)
	{
		sort_env(env, word);
		return (1);
	}
	export = export->next;
	g_exit_status = export_cmd(export, env);
	return (1);
}
