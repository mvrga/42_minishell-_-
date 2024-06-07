/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:57:01 by marcribe          #+#    #+#             */
/*   Updated: 2023/11/08 13:13:17 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;
	int				result;

	result = 0;
	i = 0;
	va_start(args, input);
	while (input[i])
	{
		if ((input[i] == '%') && (ft_strchr("cspdiuxX%", input[i + 1])))
		{
			result += check_type_input(input, i, args);
			i++;
		}
		else
			result += print_char(input[i]);
		i++;
	}
	va_end(args);
	return (result);
}
