/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:49:15 by mgur              #+#    #+#             */
/*   Updated: 2022/10/22 16:06:53 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	findlen(long nn, int len)
{
	while (nn > 9)
	{
		len++;
		nn /= 10;
	}
	return (len);
}

void	putnumber(char *str, int len, long nn, int neg)
{
	str[len--] = '\0';
	while (nn > 9)
	{
		str[len] = (nn % 10) + 48;
		len--;
		nn /= 10;
	}
	str[len--] = (nn % 10) + 48;
	if (neg == -1)
		str[len] = '-';
}

char	*ft_itoa(int nbr)
{
	int		neg;
	long	nn;
	int		len;
	char	*str;

	nn = (long)nbr;
	neg = 1;
	len = 1;
	if (nn < 0)
	{
		neg = -1;
		nn *= -1;
		len++;
	}
	len = findlen(nn, len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	putnumber(str, len, nn, neg);
	return (str);
}
