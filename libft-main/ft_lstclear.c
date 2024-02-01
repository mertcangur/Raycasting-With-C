/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:59:14 by mgur              #+#    #+#             */
/*   Updated: 2022/10/20 14:59:15 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (del && lst)
	{
		while (*lst)
		{
			node = *lst;
			*lst = (*lst)->next;
			del(node->content);
			free(node);
		}
	}
}
