/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_monster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:22:14 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/19 23:39:09 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	generate_move(int *seed)
{
	*seed = *seed * 1664523 + 1013904224;
	if (*seed % 3 == 0 || *seed % 5 == 0 || *seed % 7 == 0)
		return (0);
	return (*seed % 2);
}

void	ia_monster(t_mlx_data *data, int *x_count, int *y_count)
{
	int		x_move;
	int		y_move;
	t_map	*bloc;

	if (data->state % 800 == 0)
	{
		bloc = &data->map[*y_count][*x_count];
		x_move = generate_move(&data->seed);
		y_move = generate_move(&data->seed);
		if (x_move != 0)
			y_move = 0;
		move(data, bloc, x_move, y_move);
		if (x_move > 0)
			*x_count += x_move;
		else if (y_move > 0)
			*y_count += y_move;
	}
}

void	update_monster_position(t_mlx_data *data)
{
	int	x_count;
	int	y_count;

	y_count = 0;
	x_count = 0;
	while (data->map[y_count])
	{
		x_count = 0;
		while (data->map[y_count][x_count].type)
		{
			if (data->map[y_count][x_count].type == 'M')
				ia_monster(data, &x_count, &y_count);
			x_count++;
		}
		y_count++;
	}
}
