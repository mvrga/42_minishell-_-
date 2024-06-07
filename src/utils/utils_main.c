/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:34:12 by jveras            #+#    #+#             */
/*   Updated: 2024/06/07 12:20:02 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	implemente_prompt(char *input, t_word *data, t_env *env)
{
	while (1)
	{
		input = get_user_input();
		if (!input)
		{
			ft_printf("exit\n");
			exit(1);
		}
		if (input[0] == '\0')
			continue ;
		add_history(input);
		data = create_word_lst(input);
		expand(&data, env);
		remove_quotes_all_prompt(data);
		token(data);
		executor(data, env);
		wait_cmds(data);
		free_list(data);
		free(input);
	}
}

int	count_quotes(char *input)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (input[i])
	{
		if (input[i] == 39 || input[i] == 34)
			quotes++;
		i++;
	}
	return (quotes);
}
