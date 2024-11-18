/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:02:57 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/18 09:58:13 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_move(t_mlx_data *data, t_map *old_bloc, int *move_x, int *move_y)
{
	int	count;

	count = 0;
	while (count < *move_x
		&& data->map[old_bloc->y_pos][old_bloc->x_pos + count + 1].type != '1')
		count++;
	while (count > *move_x
		&& data->map[old_bloc->y_pos][old_bloc->x_pos + count - 1].type != '1')
		count--;
	*move_x = count;
	count = 0;
	while (count < *move_y
		&& data->map[old_bloc->y_pos + count + 1][old_bloc->x_pos].type != '1')
		count++;
	while (count > *move_y
		&& data->map[old_bloc->y_pos + count - 1][old_bloc->x_pos].type != '1')
		count--;
	*move_y = count;
}

void	move(t_mlx_data *data, t_map *old_bloc, int move_x, int move_y)
{
	t_map *new_bloc;

	set_move(data, old_bloc, &move_x, &move_y);
	if (!move_x && !move_y)
		return ;
	new_bloc = &data->map[old_bloc->y_pos + move_y][old_bloc->x_pos + move_x];
	if (old_bloc->type == 'P')
	{
		data->x_pos = new_bloc->x_pos;
		data->y_pos = new_bloc->y_pos;
		data->score++;
		ft_printf(1, "%d\n", data->score);
		if (new_bloc->type == 'M')
		{
			ft_printf(1, "Game Over !\n");
			close_game_ok(data);
		}
		if (new_bloc->type == 'E'
			&& all_collected(data->map, 'C'))
		{
			ft_printf(1, "Succes !\n");
			close_game_ok(data);
		}
	}
	if (old_bloc->type == 'M')
	{
		if (new_bloc->type == 'P')
		{
			ft_printf(1, "Game Over !\n");
			close_game_ok(data);
		}
		if (new_bloc->type == 'M')
			return ;
	}
	new_bloc->block_on = new_bloc->type;
	if (new_bloc->type == 'C' && old_bloc->type == 'P')
		new_bloc->block_on = '0';
	new_bloc->type = old_bloc->type;
	old_bloc->type = old_bloc->block_on;
	if (move_x > 0)
		new_bloc->watch = 'R';
	else if (move_x < 0)
		new_bloc->watch = 'L';
	else
		new_bloc->watch = old_bloc->watch;
}

int generate_move(int *seed)
{
	*seed = *seed  * 1664523 + 1013904224;
	if (*seed % 3 == 0 || *seed % 5 == 0 || *seed % 7 == 0)
		return (0);
	return (*seed % 2);
}

void	ia_monster(t_mlx_data *data, int *x_move, int *y_move)
{
	*x_move = generate_move(&data->seed);
	*y_move = generate_move(&data->seed);
	if (*x_move != 0)
		y_move = 0;
}

 void	update_monster_position(t_mlx_data *data)
{
	int	x_count;
	int	y_count;
	int	x_move;
	int	y_move;
	static int	slow;

	y_count = 0;
	x_count = 0;
	while (data->map[y_count])
	{
		x_count = 0;
		while (data->map[y_count][x_count].type)
		{
			if (data->map[y_count][x_count].type == 'M')
			{
				y_move = 0;
				x_move = 0;
				if (data->map[y_count][x_count].frame == 0)
					slow++;
				if (slow == 50)
				{
					ia_monster(data, &x_move, &y_move);
					move(data, &data->map[y_count][x_count], x_move, y_move);
					slow = 0;
				}
			}
			x_count++;
		}
		y_count++;
	}
}
