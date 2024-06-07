/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:48:47 by jveras            #+#    #+#             */
/*   Updated: 2024/06/07 09:20:14 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*remove_quotes(char *arg)
{
	char	*new;

	if (*arg == '\"')
	{
		new = ft_strtrim(arg, "\"");
		free(arg);
		arg = new;
	}
	else if (*arg == '\'')
	{
		new = ft_strtrim(arg, "\'");
		free(arg);
		arg = new;
	}
	return (arg);
}

static char	*handle_dollar_question(char *arg, unsigned int g_exit_status)
{
	free(arg);
	return (ft_itoa(g_exit_status));
}

static char	*handle_dollar(char *arg, t_env *env)
{
	t_env	*aux;
	char	*new;
	int		len;

	aux = env;
	if (*arg == '\"')
	{
		new = ft_strtrim(arg, "\"");
		free(arg);
		arg = new;
	}
	while (aux)
	{
		len = ft_strlen(arg + 1);
		if (!ft_strncmp(arg + 1, aux->env_var_s, len))
		{
			free(arg);
			return (ft_strdup(ft_strchr(aux->env_var_s, '=') + 1));
		}
		aux = aux->next;
	}
	return (arg);
}

static char	*handle_tilde(char *arg, t_env *env)
{
	t_env	*aux;
	char	*temp;

	aux = env;
	while (aux)
	{
		if (!ft_strncmp(aux->env_var_s, "HOME=", 5))
		{
			temp = ft_strjoin(aux->env_var_s + 5, arg + 1);
			free(arg);
			arg = temp;
			break ;
		}
		aux = aux->next;
	}
	return (arg);
}

void	expand(t_word **word, t_env *env)
{
	t_word				*expand;
	extern unsigned int	g_exit_status;

	expand = *word;
	while (expand)
	{
		if (*expand->word != '\'' && (!ft_strncmp(expand->word, "$?", 3)
				|| !ft_strncmp(expand->word, "\"$?\"", 5)))
			expand->word = handle_dollar_question(expand->word, g_exit_status);
		else if (*expand->word != '\'' && (!ft_strncmp(expand->word, "$", 1)
				|| !ft_strncmp(expand->word, "\"$", 2)))
			expand->word = handle_dollar(expand->word, env);
		else if (!ft_strncmp(expand->word, "~", 1) && (*expand->word != '\''
				|| *expand->word != '\"'))
			expand->word = handle_tilde(expand->word, env);
		else if ((*expand->word != '\'' || *expand->word != '\"'))
			expand->word = remove_quotes(expand->word);
		expand = expand->next;
	}
}
