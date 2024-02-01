/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:18:43 by mgur              #+#    #+#             */
/*   Updated: 2022/10/19 14:28:10 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str2[i] == 0)
		return ((char *)str1);
	while (i < len && str1[i] != '\0')
	{
		j = 0;
		while (str1[i + j] == str2[j] && (i + j < len))
		{
			j++;
			if (str2[j] == '\0')
				return ((char *)(str1 + i));
		}
		i++;
	}
	return (NULL);
}
