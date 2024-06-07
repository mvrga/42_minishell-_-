/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:56:47 by marcribe          #+#    #+#             */
/*   Updated: 2023/10/30 11:18:21 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;
	char	*ptr;

	ptr = (char *)big;
	l_len = ft_strlen(little);
	if (l_len == 0)
		return (ptr);
	if (len == 0)
		return (0);
	while (*ptr && len >= l_len)
	{
		if ((*ptr == *little) && (ft_strncmp(ptr, little, l_len) == 0))
		{
			return (ptr);
		}
		ptr++;
		len--;
	}
	return (NULL);
}
