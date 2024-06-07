/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:40:28 by jveras           #+#    #+#             */
/*   Updated: 2024/06/07 11:42:03 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	loop_echo_command(t_word *current)
{
	while (current)
	{
		printf("%s", current->word);
		if (current->next)
			printf(" ");
		current = current->next;
	}
}

void	echo_command(t_word *word)
{
	t_word						*current;
	extern unsigned int			g_exit_status;

	g_exit_status = 0;
	if (ft_strncmp(word->word, "echo", ft_strlen(word->word)) == 0)
	{
		if (!word->next)
		{
			printf("\n");
			return ;
		}
		current = word->next;
		if (ft_strncmp(word->next->word, "-n",
				ft_strlen(word->next->word)) == 0)
			current = current->next;
		loop_echo_command(current);
		if (ft_strncmp(word->next->word, "-n",
				ft_strlen(word->next->word)) != 0)
			printf("\n");
		return ;
	}
	g_exit_status = 1;
}
