/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_monster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:22:14 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/18 12:42:22 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int generate_move(int *seed)
{
	*seed = *seed  * 1664523 + 1013904224;
	if (*seed % 3 == 0 || *seed % 5 == 0 || *seed % 7 == 0)
		return (0);
	return (*seed % 2);
}

void	ia_monster(t_mlx_data *data, t_map *bloc, int *x_move, int *y_move)
{
	static int	slow;

	*y_move = 0;
	*x_move = 0;
	if (bloc->frame == 0)
		slow++;
	if (slow == 30)
	{
		*x_move = generate_move(&data->seed);
		*y_move = generate_move(&data->seed);
		if (*x_move != 0)
			*y_move = 0;
		move(data, bloc, *x_move, *y_move);
		slow = 0;
	}
}

 void	update_monster_position(t_mlx_data *data)
{
	int	x_count;
	int	y_count;
	int	x_move;
	int	y_move;

	y_count = 0;
	x_count = 0;
	while (data->map[y_count])
	{
		x_count = 0;
		while (data->map[y_count][x_count].type)
		{
			if (data->map[y_count][x_count].type == 'M')
				ia_monster(data, &data->map[y_count][x_count], &x_move, &y_move);
			x_count++;
		}
		y_count++;
	}
}
