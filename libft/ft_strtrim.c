/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:00:15 by marcribe          #+#    #+#             */
/*   Updated: 2023/10/24 10:44:10 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		size_s1;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set,*s1))
		s1++;
	size_s1 = ft_strlen(s1);
	while (*s1 && ft_strchr(set, s1[size_s1 - 1]))
		size_s1--;
	result = (char *)malloc(size_s1 + 1);
	i = 0;
	if (result)
	{
		while (i < size_s1 && *s1)
		{
			result[i] = *s1;
			i++;
			s1++;
		}
		result[i] = '\0';
	}
	return (result);
}
