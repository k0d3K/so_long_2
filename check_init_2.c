/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:33:02 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/19 21:21:40 by lguerbig         ###   ########.fr       */
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
