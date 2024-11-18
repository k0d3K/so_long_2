/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:58:19 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/18 17:29:19 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_anim(t_mlx_data *data, int x_count, int y_count, void **anim)
{
	int		x;
	int		y;
	void	*img;
	int		*frame;
	int		tmp_frame;

	frame = &data->map[y_count][x_count].frame;
	tmp_frame = (data->state * (data->map_width + data->map_height));
	*frame += (tmp_frame * data->map_width - 100000 * *frame) / 100000 % 2;
	*frame %= 4;
	x = (data->x_begin + x_count) * data->img_width;
	y = (data->y_begin + y_count) * data->img_height;
	if (data->map[y_count][x_count].watch == 'L')
		img = anim[*frame];
	else
		img = anim[*frame + 4];
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x, y);
}

void	print_img(t_mlx_data *data, int x_count, int y_count)
{
	int		x;
	int		y;
	void	*img;

	if (data->map[y_count][x_count].type == 'P')
		print_anim(data, x_count, y_count, data->img.hero_img);
	if (data->map[y_count][x_count].type == 'M')
		print_anim(data, x_count, y_count, data->img.enemy_img);
	if (data->map[y_count][x_count].type == 'C')
		print_anim(data, x_count, y_count, data->img.potion_img);
	if (data->map[y_count][x_count].type == 'E')
		img = data->img.exit_img;
	else if (data->map[y_count][x_count].type == '1')
		img = data->img.wall_img;
	else if (data->map[y_count][x_count].type == '0')
		img = data->img.floor_img;
	else
		return ;
	x = (data->x_begin + x_count) * data->img_width;
	y = (data->y_begin + y_count) * data->img_height;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x, y);
}

void	print_score(t_mlx_data *data, int x_count, int y_count)
{
	int	x;
	int	y;
	int	score;

	x = (data->x_begin + x_count) * data->img_width;
	y = (data->y_begin + y_count) * data->img_height;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.score_img, x, y);
	x = (data->x_begin + data->map_width - 1) * data->img_width;
	score = data->score;
	if (!score)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.numbers_img[0], x, y);
	while (score > 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.numbers_img[score % 10], x, y);	
		score /= 10;
		x -= data->img_width;
	}
}

int	print_map(t_mlx_data *data)
{
	int	x_count;
	int	y_count;
	int exit;
	
	y_count = 0;
	exit = data->map_width - 4 - size_number(data->score);
	update_monster_position(data);
	while (data->map[y_count])
	{
		x_count = 0;
		while (data->map[y_count][x_count].type)
		{
			if (y_count == data->map_height - 1 && x_count == exit)
				print_score(data, x_count, y_count);
			else if (y_count != data->map_height - 1 || x_count < exit)
				print_img(data, x_count, y_count);
			x_count++;
		}
		y_count++;
	}
	data->state++;
	return (1);
}
