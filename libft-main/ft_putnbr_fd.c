/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:15:23 by mgur              #+#    #+#             */
/*   Updated: 2022/10/23 13:17:55 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	deneme(int n, int fd)
{
	char	c;
	int		t;

	t = n;
	if (t > 9)
	{
		t = deneme((t / 10), fd);
	}
	c = (n % 10) + 48;
	write(fd, &c, 1);
	return (t);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
		deneme(n, fd);
	}
	else
		deneme(n, fd);
}
