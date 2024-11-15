/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:50:44 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/15 18:56:57 by lguerbig         ###   ########.fr       */
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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_map(t_map **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}

void	clear_img(t_mlx_data *data, void **img)
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
		free_map(data->map);
	clear_img(data, data->img.hero_img);
	clear_img(data, data->img.enemy_img);
	clear_img(data, data->img.potion_img);
	clear_img(data, data->img.floor_img);
	clear_img(data, data->img.wall_img);
	clear_img(data, data->img.exit_img);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->map);
	free(data->mlx_ptr);
}
