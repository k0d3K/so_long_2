/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:33:02 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/21 13:16:10 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_m_death_init(t_mlx_data *data, int *error)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!data->img.m_death_l[i])
		{
			if (i < 8)
				ft_printf(2, "Cannot find m_death/left_%d.xpm\n", i + 1);
			*error = 1;
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (!data->img.m_death_r[i])
		{
			if (i < 8)
				ft_printf(2, "Cannot find m_death/right_%d.xpm\n", i + 1);
			*error = 1;
		}
		i++;
	}
}
void	check_map_init(t_mlx_data *data, int *error)
{
	if (!data->img.floor_img)
	{
		ft_printf(2, "Cannot find floor.xpm\n");
		*error = 1;
	}
	if (!data->img.wall_img)
	{
		ft_printf(2, "Cannot find wall.xpm\n");
		*error = 1;
	}
	if (!data->img.exit_img)
	{
		ft_printf(2, "Cannot find exit.xpm\n");
		*error = 1;
	}
	if (!data->img.score_img)
	{
		ft_printf(2, "Cannot find score.xpm\n");
		*error = 1;
	}
}
