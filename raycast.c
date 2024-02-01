/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:37:06 by sozbayra          #+#    #+#             */
/*   Updated: 2024/01/15 02:47:03 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dir(t_cub3d *cub3d)
{
	if (cub3d->player.raydir_x < 0)
	{
		cub3d->player.step_x = -1;
		cub3d->player.side_dist_x = (cub3d->player.pos_x - cub3d->player.map_x)
			* cub3d->player.delta_dist_x;
	}
	else
	{
		cub3d->player.step_x = 1;
		cub3d->player.side_dist_x = (cub3d->player.map_x + 1
				- cub3d->player.pos_x) * cub3d->player.delta_dist_x;
	}
	if (cub3d->player.raydir_y < 0)
	{
		cub3d->player.step_y = -1;
		cub3d->player.side_dist_y = (cub3d->player.pos_y - cub3d->player.map_y)
			* cub3d->player.delta_dist_y;
	}
	else
	{
		cub3d->player.step_y = 1;
		cub3d->player.side_dist_y = (cub3d->player.map_y + 1
				- cub3d->player.pos_y) * cub3d->player.delta_dist_y;
	}
}

void	hit(t_cub3d *cub3d)
{
	cub3d->player.hit = 0;
	while (cub3d->player.hit == 0)
	{
		if (cub3d->player.side_dist_x < cub3d->player.side_dist_y)
		{
			cub3d->player.side_dist_x += cub3d->player.delta_dist_x;
			cub3d->player.map_x += cub3d->player.step_x;
			cub3d->player.side = 0;
		}
		else
		{
			cub3d->player.side_dist_y += cub3d->player.delta_dist_y;
			cub3d->player.map_y += cub3d->player.step_y;
			cub3d->player.side = 1;
		}
		if (cub3d->map.map[(int)cub3d->player.map_x]
			[(int)cub3d->player.map_y] == '1')
			cub3d->player.hit = 1;
	}
}

void	dist(t_cub3d *cub3d)
{
	if (cub3d->player.side == 0)
		cub3d->player.perp_wall_dist = cub3d->player.side_dist_x
			- cub3d->player.delta_dist_x;
	else
		cub3d->player.perp_wall_dist = cub3d->player.side_dist_y
			- cub3d->player.delta_dist_y;
	cub3d->player.line_height = (int)(1080 / cub3d->player.perp_wall_dist);
	cub3d->player.draw_start = -cub3d->player.line_height / 2 + 1080 / 2;
	if (cub3d->player.draw_start < 0)
		cub3d->player.draw_start = 0;
	cub3d->player.draw_end = cub3d->player.line_height / 2 + 1080 / 2;
	if (cub3d->player.draw_end >= 1080)
		cub3d->player.draw_end = 1080 - 1;
}

void	key(t_cub3d *cub3d)
{
	if (cub3d->keys.w)
		key_w(cub3d);
	else if (cub3d->keys.s)
		key_s(cub3d);
	else if (cub3d->keys.left)
		key_left(cub3d);
	else if (cub3d->keys.right)
		key_right(cub3d);
	else if (cub3d->keys.d)
		key_d(cub3d);
	else if (cub3d->keys.a)
		key_a(cub3d);
}

void	raycast(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < (cub3d->map.width))
	{
		cub3d->player.camera_x = 2 * i / (double)cub3d->map.width - 1;
		cub3d->player.raydir_x = cub3d->player.dir_x + cub3d->player.plane_x
			* cub3d->player.camera_x;
		cub3d->player.raydir_y = cub3d->player.dir_y + cub3d->player.plane_y
			* cub3d->player.camera_x;
		cub3d->player.map_x = (int)cub3d->player.pos_x;
		cub3d->player.map_y = (int)cub3d->player.pos_y;
		raycast2(cub3d, i);
		i++;
	}
	mlx_put_image_to_window(cub3d->mlx.init, cub3d->mlx.win,
		cub3d->mlx.object, 0, 0);
}
