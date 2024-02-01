/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:14:30 by mgur              #+#    #+#             */
/*   Updated: 2022/10/20 17:50:30 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstc;
	unsigned char	*srcc;

	if (!dst && !src)
		return (NULL);
	dstc = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	if (dst < src)
		while (len--)
			*dstc++ = *srcc++;
	else
	{
		srcc = (unsigned char *)src + (len -1);
		dstc = (unsigned char *)dst + (len -1);
		while (len--)
			*dstc-- = *srcc--;
	}
	return (dst);
}
