/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:56:39 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/15 19:43:17 by lguerbig         ###   ########.fr       */
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
			return (NULL);
		line = get_next_line(fd);
	}
	if (tab)
	{
		tab = tab_join_free(tab, line);
		if (!tab)
			return (NULL);
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
	if (!map_cpy)
		return (NULL);
	if (!parsing(map_cpy))
	{
		free_tab(map);
		free_tab(map_cpy);
		exit(-1);
	}
	free_tab(map_cpy);
	return (map);
}

int	set_map(t_mlx_data *data, char **map)
{
	int	i;
	int	j;

	data->map_width = ft_strlen(map[0]);
	data->map_height = 0;
	while (map[data->map_height])
		data->map_height++;
	data->map = (t_map **)malloc(sizeof(t_map*) * (data->map_height + 1));
	if (!data->map)
		return (0);
	j = 0;
	while (map[j])
	{
		i = 0;
		data->map[j] = (t_map *)malloc(sizeof(t_map) * (data->map_width + 1));
		if (!data->map[j])
		{
			free_map(data->map);
			return (0);
		}
		while (map[j][i] && map[j][i] != '\n')
		{
			data->map[j][i].type = map[j][i];
			i++;
		}
		data->map[j][i].type = 0;
		j++;
	}
	data->map[j] = 0;
	return (1);
}

void	create_map(t_mlx_data *data, char *filname)
{
	char	**tmp_map;

	tmp_map = create_tab_map(filname);
	if (!tmp_map)
		close_game_error(data);
	if (!set_map(data, tmp_map))
	{
		free_tab(tmp_map);
		close_game_error(data);
	}
	data->img_width = 50;
	data->img_height = 50;
	if (data->map_width > 38 || data->map_height > 21)
	{
		free_map(data->map);
		ft_printf(2, "Error\nThe map is too big to be print on this screen\n");
		exit(-1);
	}
}

void	set_pos_img(t_mlx_data *data)
{
	int	x_count;
	int	y_count;

	y_count = 0;
	while (data->map[y_count])
	{
		x_count = 0;
		while (data->map[y_count][x_count].type)
		{
			if (data->map[y_count][x_count].type == 'P')
			{
				data->x_pos = x_count;
				data->y_begin = y_count;
				data->map[y_count][x_count].block_on = '0';
				data->map[y_count][x_count].watch = 'L';
			}
			if (data->map[y_count][x_count].type == 'M')
			{
				data->map[y_count][x_count].block_on = '0';
				data->map[y_count][x_count].watch = 'R';
			}
			x_count++;
		}
		y_count++;
	}
}