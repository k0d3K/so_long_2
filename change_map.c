/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:02:57 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/20 18:09:14 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	set_move_x(data, old_bloc, &move_x);
	set_move_y(data, old_bloc, &move_y);
	if (!move_x && !move_y)
		return ;
	new_bloc = &data->map[old_bloc->y_pos + move_y][old_bloc->x_pos + move_x];
	if (old_bloc->type == 'P')
		move_hero(data, new_bloc);
	if (old_bloc->type == 'M')
		if (!move_monster(data, new_bloc))
			return ;
	new_bloc->last_type = new_bloc->type;
	if (new_bloc->type == 'C' && old_bloc->type == 'P')
		new_bloc->last_type = '0';
	if (new_bloc->type == 'D' && old_bloc->type == 'P')
	{
		new_bloc->last_type = '0';
		data->score -= 5;
		data->score = (data->score > 0) * data->score;
	}
	new_bloc->type = old_bloc->type;
	old_bloc->type = old_bloc->last_type;
	set_transition(new_bloc, old_bloc, move_x, move_y);
}
