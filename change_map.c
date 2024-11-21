/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:02:57 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/21 12:18:31 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_hero(t_mlx_data *data, t_map *new_tile)
{
	data->x_pos = new_tile->x_pos;
	data->y_pos = new_tile->y_pos;
	data->score++;
	ft_printf(1, "%d\n", data->score);
	if (new_tile->type == 'M')
	{
		ft_printf(1, "Game Over !\n");
		close_game_ok(data);
	}
	if (new_tile->type == 'E'
		&& all_collected(data->map, 'C'))
	{
		ft_printf(1, "Succes !\n");
		close_game_ok(data);
	}
}

int	move_monster(t_mlx_data *data, t_map *new_tile)
{
	if (new_tile->type == 'P')
	{
		ft_printf(1, "Game Over !\n");
		close_game_ok(data);
	}
	if (new_tile->type == 'M')
		return (0);
	return (1);
}

void	move(t_mlx_data *data, t_map *old_tile, int move_x, int move_y)
{
	t_map	*new_tile;

	set_move_x(data, old_tile, &move_x);
	set_move_y(data, old_tile, &move_y);
	if (!move_x && !move_y)
		return ;
	new_tile = &data->map[old_tile->y_pos + move_y][old_tile->x_pos + move_x];
	if (old_tile->type == 'P')
		move_hero(data, new_tile);
	if (old_tile->type == 'M')
		if (!move_monster(data, new_tile))
			return ;
	new_tile->last_type = new_tile->type;
	if (new_tile->type == 'C' && old_tile->type == 'P')
		new_tile->last_type = '0';
	if (new_tile->type == 'D' && old_tile->type == 'P')
	{
		new_tile->last_type = '0';
		data->score -= 5;
		data->score = (data->score > 0) * data->score;
	}
	new_tile->type = old_tile->type;
	old_tile->type = old_tile->last_type;
	set_transition(new_tile, old_tile, move_x, move_y);
}
