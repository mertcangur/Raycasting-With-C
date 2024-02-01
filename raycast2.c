/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:06:49 by mgur              #+#    #+#             */
/*   Updated: 2024/01/15 02:09:03 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast2(t_cub3d *cub3d, int i)
{
	if (cub3d->player.raydir_x == 0)
		cub3d->player.delta_dist_x = 1e30;
	else
		cub3d->player.delta_dist_x = fabs(1 / cub3d->player.raydir_x);
	if (cub3d->player.raydir_y == 0)
		cub3d->player.delta_dist_y = 1e30;
	else
		cub3d->player.delta_dist_y = fabs(1 / cub3d->player.raydir_y);
	dir(cub3d);
	hit(cub3d);
	dist(cub3d);
	text(cub3d, i);
}

int	key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode == 13)
		cub3d->keys.w = 0;
	if (keycode == 0)
		cub3d->keys.a = 0;
	if (keycode == 1)
		cub3d->keys.s = 0;
	if (keycode == 2)
		cub3d->keys.d = 0;
	if (keycode == 123)
		cub3d->keys.left = 0;
	if (keycode == 124)
		cub3d->keys.right = 0;
	return (0);
}

int	start_render(t_cub3d *cub3d)
{
	cub3d->mlx.init = mlx_init();
	cub3d->mlx.win = mlx_new_window(cub3d->mlx.init, 1920, 1080, "cub3d");
	cub3d->mlx.object = mlx_new_image(cub3d->mlx.init, 1920, 1080);
	cub3d->mlx.addr = (int *)mlx_get_data_addr(cub3d->mlx.object,
			&cub3d->mlx.bits_per_pixel, &cub3d->mlx.line_length,
			&cub3d->mlx.endian);
	init_xpm(cub3d);
	mlx_loop_hook(cub3d->mlx.init, &render, cub3d);
	mlx_hook(cub3d->mlx.win, 2, 1L << 0, &key_press, cub3d);
	mlx_hook(cub3d->mlx.win, 3, 1L << 1, &key_release, cub3d);
	mlx_hook(cub3d->mlx.win, 17, 1L << 17, &close_window, cub3d);
	mlx_loop(cub3d->mlx.init);
	return (0);
}
