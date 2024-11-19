/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:02:57 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/19 13:23:23 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_move(t_mlx_data *data, t_map *old_bloc, int *move_x, int *move_y)
{
	int	count;

	count = 0;
	while (count < *move_x
		&& data->map[old_bloc->y_pos][old_bloc->x_pos + count + 1].type != '1')
	{
		if (data->map[old_bloc->y_pos][old_bloc->x_pos + count + 1].type == 'M' && *move_x > 1)
			data->map[old_bloc->y_pos][old_bloc->x_pos + count + 1].type = '0';
		count++;
	}
	while (count > *move_x
		&& data->map[old_bloc->y_pos][old_bloc->x_pos + count - 1].type != '1')
	{
		if (data->map[old_bloc->y_pos][old_bloc->x_pos + count - 1].type == 'M' && *move_x < -1)
			data->map[old_bloc->y_pos][old_bloc->x_pos + count - 1].type = '0';
		count--;
	}
	*move_x = count;
	count = 0;
	while (count < *move_y
		&& data->map[old_bloc->y_pos + count + 1][old_bloc->x_pos].type != '1')
	{
		if (data->map[old_bloc->y_pos + count + 1][old_bloc->x_pos].type == 'M' && *move_y > 1)
			data->map[old_bloc->y_pos + count + 1][old_bloc->x_pos].type = '0';
		count++;
	}
	while (count > *move_y
		&& data->map[old_bloc->y_pos + count - 1][old_bloc->x_pos].type != '1')
	{
		if (data->map[old_bloc->y_pos + count - 1][old_bloc->x_pos].type == 'M'  && *move_y < -1)
			data->map[old_bloc->y_pos + count - 1][old_bloc->x_pos].type = '0';
		count--;
	}
	*move_y = count;
}

void	move_hero(t_mlx_data *data, t_map *new_bloc)
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

int	move_monster(t_mlx_data *data, t_map *new_bloc)
{
	if (new_bloc->type == 'P')
	{
		ft_printf(1, "Game Over !\n");
		close_game_ok(data);
	}
	if (new_bloc->type == 'M')
		return (0);
	return (1);
}

void	move(t_mlx_data *data, t_map *old_bloc, int move_x, int move_y)
{
	t_map	*new_bloc;

	set_move(data, old_bloc, &move_x, &move_y);
	if (!move_x && !move_y)
		return ;
	new_bloc = &data->map[old_bloc->y_pos + move_y][old_bloc->x_pos + move_x];
	if (old_bloc->type == 'P')
		move_hero(data, new_bloc);
	if (old_bloc->type == 'M')
		if(!move_monster(data, new_bloc))
			return ;
	new_bloc->block_on = new_bloc->type;
	if (new_bloc->type == 'C' && old_bloc->type == 'P')
		new_bloc->block_on = '0';
	new_bloc->type = old_bloc->type;
	old_bloc->type = old_bloc->block_on;
	if (move_y > 0)
	{
		new_bloc->y_move += -50;
		old_bloc->y_move += -50;
		new_bloc->x_move = 0;
		old_bloc->x_move = 0;
	}
	else if (move_y < 0)
	{
		new_bloc->y_move += 50;
		old_bloc->y_move += 50;
		new_bloc->x_move = 0;
		old_bloc->x_move = 0;
	}
	if (move_x > 0)
	{
		new_bloc->x_move += -50;
		old_bloc->x_move += -50;
		new_bloc->y_move = 0;
		old_bloc->y_move = 0;
		new_bloc->watch = 'R';
	}
	else if (move_x < 0)
	{
		new_bloc->x_move += 50;
		old_bloc->x_move += 50;
		new_bloc->y_move = 0;
		old_bloc->y_move = 0;
		new_bloc->watch = 'L';
	}
	else
		new_bloc->watch = old_bloc->watch;
}
