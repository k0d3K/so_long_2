/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:31:45 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/21 19:33:00 by lguerbig         ###   ########.fr       */
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

int	flood_fill(char **map)
{
	int i;
	int j;
	
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
	if (check_valid_path(map, i, j))
		return (1);
	return (0);
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

int	check_characters(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != 'C' && map[j][i] != 'E'
				&& map[j][i] != 'P' && map[j][i] != 'M'
				&& map[j][i] != '0' && map[j][i] != '1')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
