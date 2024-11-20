/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:50:44 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/20 19:42:11 by lguerbig         ###   ########.fr       */
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

void	clear_anim(t_mlx_data *data, void **img)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (img[i])
			mlx_destroy_image(data->mlx_ptr, img[i]);
		i++;
	}
}

void	clear_data(t_mlx_data *data)
{
	if (!data->map)
		return ;
	else
		free_tab((void **)data->map);
	if (data->mlx_ptr)
	{
		if (data->mlx_win)
		{
			clear_anim(data, data->img.hero_img);
			clear_anim(data, data->img.monster_img);
			clear_anim(data, data->img.potion_img);
			clear_anim(data, data->img.numbers_img);
			clear_anim(data, data->img.m_death_l);
			clear_anim(data, data->img.m_death_r);
			mlx_destroy_image(data->mlx_ptr, data->img.numbers_img[8]);
			mlx_destroy_image(data->mlx_ptr, data->img.numbers_img[9]);
			mlx_destroy_image(data->mlx_ptr, data->img.floor_img);
			mlx_destroy_image(data->mlx_ptr, data->img.wall_img);
			mlx_destroy_image(data->mlx_ptr, data->img.exit_img);
			mlx_destroy_image(data->mlx_ptr, data->img.score_img);
			mlx_destroy_window(data->mlx_ptr, data->mlx_win);
			mlx_destroy_display(data->mlx_ptr);
		}
		free(data->mlx_ptr);
	}
}
