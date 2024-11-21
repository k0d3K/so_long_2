/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:50:44 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/21 13:21:22 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game_error(t_mlx_data *data)
{
	clear_data(data);
	exit(-1);
}

int	close_game_ok(t_mlx_data *data)
{
	clear_data(data);
	exit(0);
}

void	free_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}

void	clear_img(t_mlx_data *data, void **img, int anim)
{
	int	i;

	i = 0;
	if (anim)
	{
		while (i < 8)
		{
			if (img[i])
				mlx_destroy_image(data->mlx_ptr, img[i]);
			i++;
		}
	}
	else
		if (*img)
			mlx_destroy_image(data->mlx_ptr, *img);
}

void	clear_data(t_mlx_data *data)
{
	if (!data->map)
		return ;
	else
		free_tab((void **)data->map);
	if (data->mlx_ptr)
	{
		clear_img(data, data->img.hero_img, 1);
		clear_img(data, data->img.monster_img, 1);
		clear_img(data, data->img.potion_img, 1);
		clear_img(data, data->img.m_death_l, 1);
		clear_img(data, data->img.m_death_r, 1);
		clear_img(data, data->img.numbers_img, 1);
		clear_img(data, &data->img.numbers_img[8], 0);
		clear_img(data, &data->img.numbers_img[9], 0);
		clear_img(data, &data->img.floor_img, 0);
		clear_img(data, &data->img.wall_img, 0);
		clear_img(data, &data->img.exit_img, 0);
		clear_img(data, &data->img.score_img, 0);
		if (data->mlx_win)
			mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
