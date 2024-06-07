/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:49:07 by jveras            #+#    #+#             */
/*   Updated: 2024/06/07 11:49:01 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	token(t_word *data)
{
	t_word	*current;
	int		i;

	current = data;
	while (current && current->word)
	{
		i = 0;
		if (current->word[i] == '|')
			current->flag = PIPE;
		else if (!ft_strncmp("<<", current->word, 3))
			current->flag = HDOC;
		else if (!ft_strncmp(">>", current->word, 3))
			current->flag = APPEND;
		else if (current->word[i] == '<')
			current->flag = RDIN;
		else if (current->word[i] == '>')
			current->flag = RDOUT;
		else
			current->flag = WORD;
		current = current->next;
	}
}

size_t	list_size(t_env *env)
{
	size_t	counter;
	t_env	*current;

	counter = 0;
	current = env;
	while (current)
	{
		counter++;
		current = current->next;
	}
	return (counter);
}

char	**env_list_to_sstrs(t_env *env)
{
	int		i;
	char	**sstrs;
	t_env	*current;

	sstrs = malloc(sizeof(char *) * list_size(env) + 1);
	current = env;
	i = 0;
	while (current)
	{
		sstrs[i] = current->env_var_s;
		current = current->next;
		i++;
	}
	sstrs[i] = NULL;
	return (sstrs);
}

int	many_char(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			i++;
		else
			break ;
	}
	return (i);
}
