/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:39:43 by marcribe          #+#    #+#             */
/*   Updated: 2023/11/08 13:15:14 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	print_int(int n)
{
	static int	count;
	int			sign;

	sign = 0;
	count = 0;
	if (n == -2147483648)
	{
		count = write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		sign = print_char('-');
		n *= -1;
	}
	if (n >= 10)
		print_int(n / 10);
	count += print_char((n % 10) + 48);
	return (count + sign);
}
