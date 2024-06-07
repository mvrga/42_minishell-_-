/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:27:46 by jveras            #+#    #+#             */
/*   Updated: 2024/06/07 14:47:07 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_sigint(int signo)
{
	char	*path;

	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		path = get_current_pwd();
		ft_printf("%s#%s  %s%s%s\n%s$%s", \
			BWHT, RESET_COLOR, BMAG, path, \
			RESET_COLOR, BGRN, RESET_COLOR);
		rl_redisplay();
	}
	free(path);
}
