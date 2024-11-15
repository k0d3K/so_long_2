/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:02:57 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/15 20:40:28 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_orientation(t_map *bloc, int move)
{
	if (move > 0)
		bloc->watch = 'R';
	else if (move < 0)
		bloc->watch = 'L';
}

void	set_new_position(t_mlx_data *data, int move_x, int move_y)
{
	int	count;

	count = 0;
	while (count < move_x
		&& data->map[data->y_pos][data->x_pos + count + 1].type != '1')
		count++;
	while (count > move_x
		&& data->map[data->y_pos][data->x_pos + count - 1].type != '1')
		count--;
	data->x_pos += count;
	count = 0;
	while (count < move_y
		&& data->map[data->y_pos + count + 1][data->x_pos].type != '1')
		count++;
	while (count > move_y
		&& data->map[data->y_pos + count - 1][data->x_pos].type != '1')
		count--;
	data->y_pos += count;
}

void	move_hero(t_mlx_data *data, int move_x, int move_y)
{
	t_map *old_bloc;
	t_map *new_bloc;

	old_bloc = &data->map[data->y_pos][data->x_pos];
	set_new_position(data, move_x, move_y);
	new_bloc = &data->map[data->y_pos][data->x_pos];
	if (new_bloc->type == 'E'
		&& all_collected(data->map, 'C'))
		close_game_ok(data);
	new_bloc->block_on = new_bloc->type;
	if (new_bloc->type == 'C')
		new_bloc->block_on = '0';
	new_bloc->type = old_bloc->type;
	old_bloc->type = old_bloc->block_on;
	set_orientation(new_bloc, move_x);
	data->score++;
	ft_printf(1, "%d\n", data->score);
}
