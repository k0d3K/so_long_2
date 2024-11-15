/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:31:45 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/15 19:05:12 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all_collected_char(char **map, char c)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[j][i] != 'P')
	{
		while (map[j][i] && map[j][i] != 'P')
			i++;
		if (map[j][i] != 'P')
		{
			j++;
			i = 0;
		}
	}
	*x = i;
	*y = j;
}

int	check_valid_path(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return (0);
	map[y][x] = '1';
	if (all_collected_char(map, 'E') && all_collected_char(map, 'C'))
		return (1);
	if (check_valid_path(map, x, y - 1))
		return (1);
	if (check_valid_path(map, x + 1, y))
		return (1);
	if (check_valid_path(map, x, y + 1))
		return (1);
	if (check_valid_path(map, x - 1, y))
		return (1);
	return (0);
}
