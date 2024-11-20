/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:24:37 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/20 10:06:38 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	kill(t_map *bloc, int count)
{
	bloc->type = 'D';
	bloc->frame = -count;
}

void	set_move_x(t_mlx_data *data, t_map *bloc, int *move_x)
{
	int	count;

	count = 0;
	while (count < *move_x
		&& data->map[bloc->y_pos][bloc->x_pos + count + 1].type != '1')
	{
		if (data->map[bloc->y_pos][bloc->x_pos + count + 1].type == 'M'
			&& *move_x > 1)
			kill(&data->map[bloc->y_pos][bloc->x_pos + count + 1], count);
		count++;
	}
	while (count > *move_x
		&& data->map[bloc->y_pos][bloc->x_pos + count - 1].type != '1')
	{
		if (data->map[bloc->y_pos][bloc->x_pos + count - 1].type == 'M'
			&& *move_x < -1)
			kill(&data->map[bloc->y_pos][bloc->x_pos + count - 1], count);
		count--;
	}
	*move_x = count;
}

void	set_move_y(t_mlx_data *data, t_map *bloc, int *move_y)
{
	int	count;

	count = 0;
	while (count < *move_y
		&& data->map[bloc->y_pos + count + 1][bloc->x_pos].type != '1')
	{
		if (data->map[bloc->y_pos + count + 1][bloc->x_pos].type == 'M'
			&& *move_y > 1)
			kill(&data->map[bloc->y_pos + count + 1][bloc->x_pos], count);
		count++;
	}
	while (count > *move_y
		&& data->map[bloc->y_pos + count - 1][bloc->x_pos].type != '1')
	{
		if (data->map[bloc->y_pos + count - 1][bloc->x_pos].type == 'M'
			&& *move_y < -1)
			kill(&data->map[bloc->y_pos + count - 1][bloc->x_pos], count);
		count--;
	}
	*move_y = count;
}

void	set_transition(t_map *new_bloc, t_map *old_bloc, int x, int y)
{
	if (y > 0)
	{
		new_bloc->y_move += -50;
		old_bloc->y_move += -50;
	}
	else if (y < 0)
	{
		new_bloc->y_move += 50;
		old_bloc->y_move += 50;
	}
	if (x > 0)
	{
		new_bloc->x_move += -50;
		old_bloc->x_move += -50;
		new_bloc->side = 'R';
	}
	else if (x < 0)
	{
		new_bloc->x_move += 50;
		old_bloc->x_move += 50;
		new_bloc->side = 'L';
	}
	else
		new_bloc->side = old_bloc->side;
}
