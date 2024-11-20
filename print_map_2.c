/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:24:02 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/20 11:11:19 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_transition(t_mlx_data *data, t_map *bloc, int x, int y)
{
	void	*img_old;
	t_map	*bloc_old;

	y += (bloc->y_move > 0) - (bloc->y_move < 0);
	x += (bloc->x_move > 0) - (bloc->x_move < 0);
	bloc_old = &data->map[y][x];
	if (bloc_old->type == 'E')
		img_old = data->img.exit_img;
	else
		img_old = data->img.floor_img;
	x = (data->x_begin + bloc_old->x_pos) * data->img_width;
	y = (data->y_begin + bloc_old->y_pos) * data->img_height;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img_old, x, y);
}

void	print_anim(t_mlx_data *data, int x_count, int y_count, void **anim)
{
	int		x;
	int		y;
	void	*img;
	t_map	*bloc;
	int		tmp;

	bloc = &data->map[y_count][x_count];
	if (bloc->type != 'C')
		print_transition(data, bloc, x_count, y_count);
	tmp = (data->state * (data->map_width + data->map_height));
	bloc->frame += (tmp * data->map_width - 100000 * bloc->frame) / 100000 % 2;
	bloc->frame %= 4;
	x = (data->x_begin + x_count);
	x = x * data->img_width + bloc->x_move * (bloc->type != 'C');
	y = (data->y_begin + y_count);
	y = y * data->img_height + bloc->y_move * (bloc->type != 'C');
	if (bloc->side == 'L')
		img = anim[bloc->frame];
	else
		img = anim[bloc->frame + 4];
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x, y);
	if (bloc->x_move)
		bloc->x_move -= (bloc->x_move > 0) - (bloc->x_move < 0);
	else if (bloc->y_move)
		bloc->y_move -= (bloc->y_move > 0) - (bloc->y_move < 0);
}

void	print_monster_death(t_mlx_data *data, int x_count, int y_count)
{
	int		x;
	int		y;
	void	*img;
	t_map	*bloc;
	int		tmp;

	bloc = &data->map[y_count][x_count];
	if (bloc->frame != 7)
	{
		tmp = (data->state * (data->map_width + data->map_height));
		tmp = (tmp * data->map_width - 50000 * bloc->frame) / 50000 % 2;
		bloc->frame += tmp;
		bloc->frame %= 8;
	}
	x = (data->x_begin + x_count) * data->img_width;
	y = (data->y_begin + y_count) * data->img_height;
	if (bloc->side == 'L')
		img = data->img.m_death_l[bloc->frame];
	else
		img = data->img.m_death_r[bloc->frame];
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x, y);
}

void	print_img(t_mlx_data *data, void *img, t_map *bloc)
{
	int	x;
	int	y;

	x = (data->x_begin + bloc->x_pos) * data->img_width;
	y = (data->y_begin + bloc->y_pos) * data->img_height;
	if (bloc->x_move)
		bloc->x_move -= (bloc->x_move > 0) * 1 - (bloc->x_move < 0) * 1;
	else if (bloc->y_move)
		bloc->y_move -= (bloc->y_move > 0) * 1 - (bloc->y_move < 0) * 1;
	else
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x, y);
}
