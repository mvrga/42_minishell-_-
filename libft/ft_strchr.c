/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:19:02 by marcribe          #+#    #+#             */
/*   Updated: 2023/10/23 14:54:34 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr_s;

	ptr_s = (char *)s;
	while (*ptr_s != '\0')
	{
		if (*ptr_s == (unsigned char)c)
		{
			return (ptr_s);
		}
		ptr_s++;
	}
	if (c == 0)
	{
		return (ptr_s);
	}
	return (NULL);
}
