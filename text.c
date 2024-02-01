/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:05:20 by mgur              #+#    #+#             */
/*   Updated: 2024/01/15 02:11:59 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_text(t_cub3d *cub3d)
{
	double	wallx;

	cub3d->player.text_num = cub3d->map.map[(int)cub3d->player.map_x]
	[(int)cub3d->player.map_y] - 1;
	if (cub3d->player.side == 0)
		wallx = cub3d->player.pos_y + cub3d->player.perp_wall_dist
			* cub3d->player.raydir_y;
	else
		wallx = cub3d->player.pos_x + cub3d->player.perp_wall_dist
			* cub3d->player.raydir_x;
	wallx -= floor(wallx);
	cub3d->player.text_x = (int)(wallx * (double)64);
	if (cub3d->player.side == 0 && cub3d->player.raydir_x > 0)
		cub3d->player.text_x = 64 - cub3d->player.text_x - 1;
	if (cub3d->player.side == 1 && cub3d->player.raydir_y < 0)
		cub3d->player.text_x = 64 - cub3d->player.text_x - 1;
	cub3d->player.tex_step = 1.0 * 64 / cub3d->player.line_height;
	cub3d->player.tex_pos = (cub3d->player.draw_start - 1080 / 2
			+ cub3d->player.line_height / 2) * cub3d->player.tex_step;
}

void	text(t_cub3d *cub3d, int x)
{
	int	texty;

	init_text(cub3d);
	while (cub3d->player.draw_start < cub3d->player.draw_end)
	{
		texty = (int)cub3d->player.tex_pos & (64 - 1);
		cub3d->player.tex_pos += cub3d->player.tex_step;
		if (cub3d->player.side == 0 && cub3d->player.raydir_x > 0)
			cub3d->mlx.addr[cub3d->player.draw_start * cub3d->map.width
				+ x] = cub3d->asset.so_data[64 * texty + cub3d->player.text_x];
		else if (cub3d->player.side == 0 && cub3d->player.raydir_x < 0)
			cub3d->mlx.addr[cub3d->player.draw_start * cub3d->map.width
				+ x] = cub3d->asset.no_data[64 * texty + cub3d->player.text_x];
		else if (cub3d->player.side == 1 && cub3d->player.raydir_y > 0)
			cub3d->mlx.addr[cub3d->player.draw_start * cub3d->map.width
				+ x] = cub3d->asset.ea_data[64 * texty + cub3d->player.text_x];
		else
			cub3d->mlx.addr[cub3d->player.draw_start * cub3d->map.width
				+ x] = cub3d->asset.we_data[64 * texty + cub3d->player.text_x];
		cub3d->player.draw_start++;
	}
}
