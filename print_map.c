/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:58:19 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/20 19:18:48 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_bloc(t_mlx_data *data, int x_count, int y_count)
{
	void	*img;
	t_map	*bloc;

	bloc = &data->map[y_count][x_count];
	if (bloc->type == 'P')
		print_anim(data, x_count, y_count, data->img.hero_img);
	if (bloc->type == 'M')
		print_anim(data, x_count, y_count, data->img.enemy_img);
	if (bloc->type == 'D')
		print_monster_death(data, x_count, y_count);
	if (bloc->type == 'C')
		print_anim(data, x_count, y_count, data->img.potion_img);
	if (bloc->type == 'E')
		img = data->img.exit_img;
	else if (bloc->type == '1')
		img = data->img.wall_img;
	else if (bloc->type == '0')
		img = data->img.floor_img;
	else
		return ;
	print_img(data, img, bloc);
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
				print_bloc(data, x_count, y_count);
			x_count++;
		}
		y_count++;
	}
	update_monster_position(data);
	data->state++;
	return (1);
}
