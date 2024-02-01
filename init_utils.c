/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:12:52 by mgur              #+#    #+#             */
/*   Updated: 2024/01/15 17:28:59 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_cub(char *str)
{
	int	len;
	int	fd;

	fd = open(str, O_RDONLY);
	len = strlen(str);
	if (str[--len] == 'b' && str[--len] == 'u' && str[--len] == 'c' \
	&& str[--len] == '.' && fd > 0)
	{
		close(fd);
		return (0);
	}
	else
	{
		close(fd);
		printf("incorrect file extension\n");
		exit(1);
	}
}

void	init_map(t_fm *map)
{
	map->check = 0;
	map->f = -1;
	map->c = -1;
	map->height = 1080;
	map->width = 1920;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->direct = 'G';
}

void	init_free(t_fm *map)
{
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
}

int	for_f(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'F' || str[i] == 'C')
			return (++i);
		i++;
	}
	return (0);
}

int	is_just_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
