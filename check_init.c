/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:22:35 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/21 13:17:29 by lguerbig         ###   ########.fr       */
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

void	check_monster_init(t_mlx_data *data, int *error)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!data->img.monster_img[i])
		{
			if (i < 4)
				ft_printf(2, "Cannot find monster/left_%d.xpm\n", i + 1);
			else
				ft_printf(2, "Cannot find monster/right_%d.xpm\n", i - 4 + 1);
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
		if (!data->img.monster_img[i])
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

	error = 0;
	check_map_init(data, &error);
	check_hero_init(data, &error);
	check_potion_init(data, &error);
	check_monster_init(data, &error);
	check_m_death_init(data, &error);
	check_numbers_init(data, &error);
	if (error)
		close_game_error(data);
}
