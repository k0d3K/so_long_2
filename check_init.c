/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:22:35 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/18 12:39:22 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_hero_init(t_mlx_data *data, int *error)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!data->img.hero_img[i])
		{
			if (i < 4)
				ft_printf(2, "Cannot find hero/left_%d.xpm\n", i + 1);
			else
				ft_printf(2, "Cannot find hero/right_%d.xpm\n", i - 4 + 1);
			*error = 1;
		}
		i++;
	}
}

void	check_potion_init(t_mlx_data *data, int *error)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!data->img.potion_img[i])
		{
			ft_printf(2, "Cannot find potion_%d.xpm\n", i + 1);
			*error = 1;
		}
		i++;
	}
}

void	check_enemy_init(t_mlx_data *data, int *error)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!data->img.enemy_img[i])
		{
			if (i < 4)
				ft_printf(2, "Cannot find enemy/left_%d.xpm\n", i + 1);
			else
				ft_printf(2, "Cannot find enemy/right_%d.xpm\n", i - 4 + 1);
			*error = 1;
		}
		i++;
	}
}

void	check_numbers_init(t_mlx_data *data, int *error)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (!data->img.enemy_img[i])
		{
			ft_printf(2, "Cannot find numbers/%d.xpm\n", i);
			*error = 1;
		}
		i++;
	}
}

void	check_img_init(t_mlx_data *data)
{
	int	error;

	error = 1;
	if (!data->img.floor_img)
		ft_printf(2, "Cannot find floor.xpm\n");
	else if (!data->img.wall_img)
		ft_printf(2, "Cannot find wall.xpm\n");
	else if (!data->img.exit_img)
		ft_printf(2, "Cannot find exit.xpm\n");
	else if (!data->img.score_img)
		ft_printf(2, "Cannot find exit.xpm\n");
	else
		error = 0;
	check_hero_init(data, &error);
	check_potion_init(data, &error);
	check_enemy_init(data, &error);
	check_numbers_init(data, &error);
	if (error)
		close_game_error(data);
}
