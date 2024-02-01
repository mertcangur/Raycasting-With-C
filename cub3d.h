/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:13:09 by sozbayra          #+#    #+#             */
/*   Updated: 2024/01/15 11:42:31 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft-main/libft.h"
# include "./mlx/mlx.h"
# include "get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <string.h>

typedef struct fmlx
{
	void	*init;
	void	*win;
	void	*object;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_fmlx;

typedef struct fa
{
	int		*no_data;
	int		*so_data;
	int		*we_data;
	int		*ea_data;

	int		no_size_line;
	int		so_size_line;
	int		we_size_line;
	int		ea_size_line;

	int		no_endian;
	int		so_endian;
	int		we_endian;
	int		ea_endian;

	int		no_b;
	int		so_b;
	int		we_b;
	int		ea_b;

	void	*i_no;
	void	*i_so;
	void	*i_we;
	void	*i_ea;

}			t_fa;

typedef struct fk
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;

}			t_fk;

typedef struct fp
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	map_x;
	double	map_y;
	double	perp_wall_dist;
	double	step;
	double	tex_pos;
	double	tex_step;

	int		line_height;
	int		hit;
	int		side;
	int		step_x;
	int		step_y;
	int		draw_start;
	int		draw_end;
	int		text_num;
	int		text_x;
}			t_fp;

typedef struct fm
{
	int		check;
	int		width;
	int		height;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	long	f;
	long	c;
	char	**map;
	char	direct;
	int		lines;
	int		max_line_c;
}			t_fm;

typedef struct cub3d
{
	t_fm	map;
	t_fa	asset;
	t_fk	keys;
	t_fp	player;
	t_fmlx	mlx;
}			t_cub3d;

int			check_cub(char *str);
int			check_map(char *str, t_cub3d **cub3d);
int			check_map2(char *str, t_cub3d **cub3d);
char		*ft_strdup2(const char *s1, int i);
char		**ft_split2(const char *s);
int			count_of_map_line(int line, char *str, t_fm *map);
int			check_map_valid(t_fm *map, t_fp *player);
int			mapline_ut(int fd, char *str, int line);
void		take_care_the_map(t_fm *map, char *str, int line);
void		init_free(t_fm *map);
void		init_map(t_fm *map);
int			check_elements_same(t_fm *map);
void		init_data(t_cub3d *cub3d);
void		player_init(t_cub3d *cub3d);
void		keys_init(t_cub3d *cub3d);
void		init_xpm(t_cub3d *cub3d);
int			render(t_cub3d *cub3d);
int			close_window(t_cub3d *cub3d);
int			key_press(int keycode, t_cub3d *cub3d);
int			key_release(int keycode, t_cub3d *cub3d);
int			start_render(t_cub3d *cub3d);
void		key_w(t_cub3d *cub3d);
void		key_s(t_cub3d *cub3d);
void		key_right(t_cub3d *cub3d);
void		key_left(t_cub3d *cub3d);
void		key(t_cub3d *cub3d);
void		raycast(t_cub3d *cub3d);
int			is_player(char c);
void		text(t_cub3d *cub3d, int x);
void		key_a(t_cub3d *cub3d);
void		key_d(t_cub3d *cub3d);
int			ft_atoiup(char *str);
int			for_f(char *str);
void		free_split(char **split);
int			is_same(char *str, char *str2);
int			check_dot(char *str);
void		let_free(t_cub3d *cub3d);
void		check_map_clone(char *str, t_cub3d **cub3d, int line);
void		if_max(t_fm *map, char *str);
void		ft_error(char *str);
int			check_elements_valid(char *str);
int			check_elements(char **lol, t_cub3d **cub3d);
int			check_for_m2(char **lol);
void		raycast2(t_cub3d *cub3d, int i);
void		hit(t_cub3d *cub3d);
void		dir(t_cub3d *cub3d);
void		dist(t_cub3d *cub3d);
void		key(t_cub3d *cub3d);
int			is_space(char *str);
int			is_just_space(char *str);

#endif
