/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:22:50 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/21 19:14:27 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_only_one(char **map, char c)
{
	int	i;
	int	j;
	int	is_c;

	is_c = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
			{
				if (is_c)
					return (0);
				is_c = 1;
			}
			i++;
		}
		j++;
	}
	return (is_c);
}

int	map_is_closed(char **map)
{
	int	i;
	int	j;
	int	width;
	int	height;

	width = ft_strlen(map[0]) - 1;
	height = 0;
	while (map[height + 1])
		height++;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '1'
				&& (j == 0 || j == height || i == 0 || i == width))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	get_nb_collectibles(char **map)
{
	int	i;
	int	j;
	int	nb_c;

	nb_c = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				nb_c++;
			i++;
		}
		j++;
	}
	return (nb_c++);
}

int	map_is_rectangular(char **map)
{
	int	j;
	int	width;

	j = 0;
	width = ft_strlen(map[0]);
	while (map[j])
	{
		if ((int)ft_strlen(map[j]) != width)
			return (0);
		j++;
	}
	return (1);
}

int	parsing(char **map)
{
	if (!map)
		return (0);
	if (!map_is_rectangular(map))
		ft_printf(2, "Error\nThe map must be rectangular\n");
	else if (!check_characters(map))
		ft_printf(2, "Error\nThere is an invalid character in the map\n");
	else if (!check_only_one(map, 'P'))
		ft_printf(2, "Error\nThere must be one and only one player\n");
	else if (!check_only_one(map, 'E'))
		ft_printf(2, "Error\nThere must be one and only one exit\n");
	else if (!map_is_closed(map))
		ft_printf(2, "Error\nThere must be closed/surrounded by walls\n");
	else if (get_nb_collectibles(map) < 1)
		ft_printf(2, "Error\nThere must be at least one collectible\n");
	else if (!flood_fill(map))
		ft_printf(2, "Error\nThere is no valid path in the map\n");
	else
		return (1);
	return (0);
}
