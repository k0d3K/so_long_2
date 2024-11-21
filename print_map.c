/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:58:19 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/21 13:01:05 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_tile(t_mlx_data *data, int x_count, int y_count)
{
	void	*img;
	t_map	*tile;

	tile = &data->map[y_count][x_count];
	if (tile->type == 'P')
		print_anim(data, x_count, y_count, data->img.hero_img);
	if (tile->type == 'M')
		print_anim(data, x_count, y_count, data->img.monster_img);
	if (tile->type == 'D')
		print_monster_death(data, x_count, y_count);
	if (tile->type == 'C')
		print_anim(data, x_count, y_count, data->img.potion_img);
	if (tile->type == 'E')
		img = data->img.exit_img;
	else if (tile->type == '1')
		img = data->img.wall_img;
	else if (tile->type == '0')
		img = data->img.floor_img;
	else
		return ;
	print_img(data, img, tile);
}

void	print_score(t_mlx_data *data, int x_count, int y_count)
{
	int		x;
	int		y;
	int		score;
	void	*img;

	x = (data->x_begin + x_count) * data->img_width + 10;
	y = (data->y_begin + y_count) * data->img_height + 8;
	img = data->img.score_img;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x, y);
	x = (data->x_begin + data->map_width - 1) * data->img_width + 10;
	score = data->score;
	img = data->img.numbers_img[0];
	if (!score)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x, y);
	while (score > 0)
	{
		img = data->img.numbers_img[score % 10];
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x, y);
		score /= 10;
		x -= data->img_width;
	}
}

int	print_map(t_mlx_data *data)
{
	int	x_count;
	int	y_count;
	int	exit;

	y_count = 0;
	exit = data->map_width - 4 - size_number(data->score);
	while (data->map[y_count])
	{
		x_count = 0;
		while (data->map[y_count][x_count].type)
		{
			if (y_count == data->map_height - 1 && x_count == exit)
				print_score(data, x_count, y_count);
			else if (y_count != data->map_height - 1 || x_count < exit)
				print_tile(data, x_count, y_count);
			x_count++;
		}
		y_count++;
	}
	update_monster_position(data);
	data->state++;
	return (1);
}
