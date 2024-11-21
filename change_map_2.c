/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:24:37 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/21 16:57:40 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	kill(t_map *tile)
{
	tile->type = 'D';
	tile->frame = 0;
}

void	set_move_x(t_mlx_data *data, t_map *tile, int *move_x)
{
	int	count;

	count = 0;
	while (count < *move_x
		&& data->map[tile->y_pos][tile->x_pos + count + 1].type != '1')
	{
		if (data->map[tile->y_pos][tile->x_pos + count + 1].type == 'M'
			&& *move_x > 1)
			kill(&data->map[tile->y_pos][tile->x_pos + count + 1]);
		count++;
	}
	while (count > *move_x
		&& data->map[tile->y_pos][tile->x_pos + count - 1].type != '1')
	{
		if (data->map[tile->y_pos][tile->x_pos + count - 1].type == 'M'
			&& *move_x < -1)
			kill(&data->map[tile->y_pos][tile->x_pos + count - 1]);
		count--;
	}
	*move_x = count;
}

void	set_move_y(t_mlx_data *data, t_map *tile, int *move_y)
{
	int	count;

	count = 0;
	while (count < *move_y
		&& data->map[tile->y_pos + count + 1][tile->x_pos].type != '1')
	{
		if (data->map[tile->y_pos + count + 1][tile->x_pos].type == 'M'
			&& *move_y > 1)
			kill(&data->map[tile->y_pos + count + 1][tile->x_pos]);
		count++;
	}
	while (count > *move_y
		&& data->map[tile->y_pos + count - 1][tile->x_pos].type != '1')
	{
		if (data->map[tile->y_pos + count - 1][tile->x_pos].type == 'M'
			&& *move_y < -1)
			kill(&data->map[tile->y_pos + count - 1][tile->x_pos]);
		count--;
	}
	*move_y = count;
}

void	set_transition(t_map *new_tile, t_map *old_tile, int x, int y)
{
	if (y > 0)
	{
		new_tile->y_move += -50;
		old_tile->y_move += -50;
	}
	else if (y < 0)
	{
		new_tile->y_move += 50;
		old_tile->y_move += 50;
	}
	if (x > 0)
	{
		new_tile->x_move += -50;
		old_tile->x_move += -50;
		new_tile->side = 'R';
	}
	else if (x < 0)
	{
		new_tile->x_move += 50;
		old_tile->x_move += 50;
		new_tile->side = 'L';
	}
	else
		new_tile->side = old_tile->side;
}
