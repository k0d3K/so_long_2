/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:26:21 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/19 13:35:01 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all_collected(t_map **map, char c)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x].type)
		{
			if (map[y][x].type == c)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

char	**tab_join_free(char **tab, char *line)
{
	char	**res;
	int		i;
	int		size;

	i = 0;
	if (!tab)
		res = (char **)malloc(sizeof(char *) * 2);
	else
	{
		size = 0;
		while (tab[size])
			size++;
		res = (char **)malloc(sizeof(char *) * (size + 2));
	}
	if (!res)
	{
		free_tab((void **)tab);
		return (NULL);
	}
	while (tab && tab[i])
	{
		res[i] = tab[i];
		i++;
	}
	free(tab);
	res[i++] = line;
	res[i] = 0;
	return (res);
}

char	**tab_cpy(char **tab)
{
	int		i;
	int		j;
	int		height;
	char	**tab_cpy;

	height = 0;
	while (tab[height])
		height++;
	tab_cpy = (char **)malloc(sizeof(char *) * (height + 1));
	j = 0;
	while (tab[j])
	{
		i = 0;
		tab_cpy[j] = (char *)malloc(sizeof(char) * (ft_strlen(tab[j]) + 1));
		while (tab[j][i] && tab[j][i] != '\n')
		{
			tab_cpy[j][i] = tab[j][i];
			i++;
		}
		tab_cpy[j][i] = 0;
		j++;
	}
	tab_cpy[j] = 0;
	return (tab_cpy);
}

void	*create_img(t_mlx_data *data, void *p, char *path)
{
	int		*w;
	int		*h;
	void	*img;

	w = &data->img_width;
	h = &data->img_height;
	img = mlx_xpm_file_to_image(p, path, w, h);
	return (img);
}

int	size_number(unsigned int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}
