/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:30:11 by jveras            #+#    #+#             */
/*   Updated: 2024/06/07 17:13:19 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

unsigned int	g_exit_status;

int	main(void)
{
	extern char	**environ;
	char		*input;
	t_env		*env;
	t_word		*data;

	input = NULL;
	data = NULL;
	env = init_env(environ);
	env->environ = environ;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	implemente_prompt(input, data, env);
	ft_lstclear(&env, free);
	return (0);
}
