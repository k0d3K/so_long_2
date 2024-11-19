/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:56:39 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/19 13:08:00 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_tab(int fd)
{
	char	**tab;
	char	*line;

	tab = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tab = tab_join_free(tab, line);
		if (!tab)
		{
			free(line);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	if (tab)
	{
		tab = tab_join_free(tab, line);
		if (!tab)
		{
			free(line);
			return (NULL);
		}
	}
	return (tab);
}

char	**create_tab_map(char *filename)
{
	char	**map;
	char	**map_cpy;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(2, "Error\nThe given map doesn't exist\n");
		return (NULL);
	}
	map = read_tab(fd);
	if (!map)
		return (NULL);
	close(fd);
	map_cpy = tab_cpy(map);
	if (!parsing(map_cpy))
	{
		free_tab((void **)map);
		free_tab((void **)map_cpy);
		exit(-1);
	}
	free_tab((void **)map_cpy);
	map_cpy = tab_cpy(map);
	free_tab((void **)map);
	return (map_cpy);
}

void	set_bloc(t_mlx_data *data, char **map, int i, int j)
{
	data->map[j][i].to_print = 1;
	data->map[j][i].type = map[j][i];
	data->map[j][i].frame = 0;
	data->map[j][i].block_on = '0';
	data->map[j][i].watch = 'L';
	data->map[j][i].x_pos = i;
	data->map[j][i].y_pos = j;
	data->map[j][i].x_move = 0;
	data->map[j][i].y_move = 0;
	if (map[j][i] == 'P')
	{
		data->x_pos = i;
		data->y_pos = j; 
	}
	if (map[j][i] == 'M')
		data->map[j][i].watch = 'R';
}

int	set_map(t_mlx_data *data, char **map)
{
	int	i;
	int	j;

	data->map = (t_map **)malloc(sizeof(t_map*) * (data->map_height + 1));
	if (!data->map)
		return (0);
	j = 0;
	while (map[j])
	{
		i = 0;
		data->map[j] = (t_map *)malloc(sizeof(t_map) * (data->map_width + 1));
		if (!data->map[j])
			return (0);
		while (map[j][i] && map[j][i] != '\n')
		{
			set_bloc(data, map, i, j);
			i++;
		}
		data->map[j][i].type = 0;
		j++;
	}
	data->map[j] = 0;
	return (1);
}

void	create_map(t_mlx_data *data, char *filename)
{
	char	**map;

	map = create_tab_map(filename);
	if (!map)
		close_game_error(data);
	data->map_width = ft_strlen(map[0]);
	data->map_height = 0;
	while (map[data->map_height])
		data->map_height++;
	if (!set_map(data, map))
	{
		free_tab((void **)map);
		close_game_error(data);
	}
	free_tab((void **)map);
	data->img_width = 50;
	data->img_height = 50;
	if (data->map_width > 38 || data->map_height > 21)
	{
		free_tab((void **)data->map);
		ft_printf(2, "Error\nThe map is too big to be print on this screen\n");
		exit(-1);
	}
}
