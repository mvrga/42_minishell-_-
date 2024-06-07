/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:55:30 by marcribe          #+#    #+#             */
/*   Updated: 2023/11/08 10:12:22 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	print_unsnbr(unsigned int n)
{
	static unsigned int	count;
	unsigned int		sign;

	sign = 0;
	count = 0;
	if (n >= 10)
		print_unsnbr(n / 10);
	count += print_char((n % 10) + 48);
	return (count + sign);
}
