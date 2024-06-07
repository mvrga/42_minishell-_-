/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:57:22 by marcribe          #+#    #+#             */
/*   Updated: 2023/10/23 15:01:46 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last;

	last = NULL;
	while (*str != '\0')
	{
		if (*str == c)
		{
			last = str;
		}
		str++;
	}
	if (c == 0)
	{
		return ((char *)str);
	}
	return ((char *)last);
}
