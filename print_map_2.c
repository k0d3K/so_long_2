/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:24:02 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/21 12:58:27 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_transition(t_mlx_data *data, t_map *tile, int x, int y)
{
	void	*img_old;
	t_map	*tile_old;

	y += (tile->y_move > 0) - (tile->y_move < 0);
	x += (tile->x_move > 0) - (tile->x_move < 0);
	tile_old = &data->map[y][x];
	if (tile_old->type == 'E')
		img_old = data->img.exit_img;
	else
		img_old = data->img.floor_img;
	x = (data->x_begin + tile_old->x_pos) * data->img_width + 10;
	y = (data->y_begin + tile_old->y_pos) * data->img_height + 8;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img_old, x, y);
}

void	print_anim(t_mlx_data *data, int x_count, int y_count, void **anim)
{
	int		x;
	int		y;
	void	*img;
	t_map	*tile;
	int		tmp;

	tile = &data->map[y_count][x_count];
	if (tile->type != 'C')
		print_transition(data, tile, x_count, y_count);
	tmp = (data->state * (data->map_width + data->map_height));
	tile->frame += (tmp * data->map_width - 100000 * tile->frame) / 100000 % 2;
	tile->frame %= 4;
	x = (data->x_begin + x_count);
	x = x * data->img_width + tile->x_move * (tile->type != 'C') + 10;
	y = (data->y_begin + y_count);
	y = y * data->img_height + tile->y_move * (tile->type != 'C') + 8;
	if (tile->side == 'L')
		img = anim[tile->frame];
	else
		img = anim[tile->frame + 4];
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x, y);
	if (tile->x_move)
		tile->x_move -= (tile->x_move > 0) - (tile->x_move < 0);
	else if (tile->y_move)
		tile->y_move -= (tile->y_move > 0) - (tile->y_move < 0);
}

void	print_monster_death(t_mlx_data *data, int x_count, int y_count)
{
	int		x;
	int		y;
	void	*img;
	t_map	*tile;
	int		tmp;

	tile = &data->map[y_count][x_count];
	if (tile->frame != 7)
	{
		tmp = (data->state * (data->map_width + data->map_height));
		tmp = (tmp * data->map_width - 50000 * tile->frame) / 50000 % 2;
		tile->frame += tmp;
		tile->frame %= 8;
	}
	x = (data->x_begin + x_count) * data->img_width + 10;
	y = (data->y_begin + y_count) * data->img_height + 8;
	if (tile->side == 'L')
		img = data->img.m_death_l[tile->frame];
	else
		img = data->img.m_death_r[tile->frame];
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x, y);
}

void	print_img(t_mlx_data *data, void *img, t_map *tile)
{
	int	x;
	int	y;

	x = (data->x_begin + tile->x_pos) * data->img_width + 10;
	y = (data->y_begin + tile->y_pos) * data->img_height + 8;
	if (tile->x_move)
		tile->x_move -= (tile->x_move > 0) * 1 - (tile->x_move < 0) * 1;
	else if (tile->y_move)
		tile->y_move -= (tile->y_move > 0) * 1 - (tile->y_move < 0) * 1;
	else
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x, y);
}
