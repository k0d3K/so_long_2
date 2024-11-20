/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:22:00 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/19 21:43:48 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_monster_death(t_mlx_data *data)
{
	void	*p;

	p = data->mlx_ptr;
	data->img.m_death_l[0] = create_img(data, p, "img/m_death/left_1.xpm");
	data->img.m_death_l[1] = create_img(data, p, "img/m_death/left_2.xpm");
	data->img.m_death_l[2] = create_img(data, p, "img/m_death/left_3.xpm");
	data->img.m_death_l[3] = create_img(data, p, "img/m_death/left_4.xpm");
	data->img.m_death_l[4] = create_img(data, p, "img/m_death/left_5.xpm");
	data->img.m_death_l[5] = create_img(data, p, "img/m_death/left_6.xpm");
	data->img.m_death_l[6] = create_img(data, p, "img/m_death/left_7.xpm");
	data->img.m_death_l[7] = create_img(data, p, "img/m_death/left_8.xpm");
	data->img.m_death_r[0] = create_img(data, p, "img/m_death/right_1.xpm");
	data->img.m_death_r[1] = create_img(data, p, "img/m_death/right_2.xpm");
	data->img.m_death_r[2] = create_img(data, p, "img/m_death/right_3.xpm");
	data->img.m_death_r[3] = create_img(data, p, "img/m_death/right_4.xpm");
	data->img.m_death_r[4] = create_img(data, p, "img/m_death/right_5.xpm");
	data->img.m_death_r[5] = create_img(data, p, "img/m_death/right_6.xpm");
	data->img.m_death_r[6] = create_img(data, p, "img/m_death/right_7.xpm");
	data->img.m_death_r[7] = create_img(data, p, "img/m_death/right_8.xpm");
}
