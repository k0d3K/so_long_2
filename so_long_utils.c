/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:26:21 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/20 02:06:17 by lguerbig         ###   ########.fr       */
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
	int	size;

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

int	size_tab(char **tab)
{
	int	size;

	size = 0;
	while (tab && tab[size])
		size++;
	return (size);
}
