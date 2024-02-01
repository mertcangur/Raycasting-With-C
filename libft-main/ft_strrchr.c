/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:19:42 by mgur              #+#    #+#             */
/*   Updated: 2022/10/18 18:17:55 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*rslt;
	int		len;

	i = 0;
	rslt = (char *)s;
	len = (ft_strlen(s));
	while (i <= len)
	{
		if (rslt[len] == (char)c)
			return (rslt + len);
		len--;
	}
	return (NULL);
}
