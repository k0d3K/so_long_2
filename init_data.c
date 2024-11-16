/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:44:23 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/16 10:57:40 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_hero(t_mlx_data *data)
{
	void	*p;

	p = data->mlx_ptr;
	data->img.hero_img[0] = create_img(data, p, "textures/hero/left_1.xpm");
	data->img.hero_img[1] = create_img(data, p, "textures/hero/left_2.xpm");
	data->img.hero_img[2] = create_img(data, p, "textures/hero/left_3.xpm");
	data->img.hero_img[3] = create_img(data, p, "textures/hero/left_4.xpm");
	data->img.hero_img[4] = create_img(data, p, "textures/hero/right_1.xpm");
	data->img.hero_img[5] = create_img(data, p, "textures/hero/right_2.xpm");
	data->img.hero_img[6] = create_img(data, p, "textures/hero/right_3.xpm");
	data->img.hero_img[7] = create_img(data, p, "textures/hero/right_4.xpm");
}

void	init_enemy(t_mlx_data *data)
{
	void	*p;
	
	p = data->mlx_ptr;
	data->img.enemy_img[0] = create_img(data, p, "textures/enemy/left_1.xpm");
	data->img.enemy_img[1] = create_img(data, p, "textures/enemy/left_2.xpm");
	data->img.enemy_img[2] = create_img(data, p, "textures/enemy/left_3.xpm");
	data->img.enemy_img[3] = create_img(data, p, "textures/enemy/left_4.xpm");
	data->img.enemy_img[4] = create_img(data, p, "textures/enemy/right_1.xpm");
	data->img.enemy_img[5] = create_img(data, p, "textures/enemy/right_2.xpm");
	data->img.enemy_img[6] = create_img(data, p, "textures/enemy/right_3.xpm");
	data->img.enemy_img[7] = create_img(data, p, "textures/enemy/right_4.xpm");
}

void	init_potion(t_mlx_data *data)
{
	t_textures	*img;
	void	*p;

	p = data->mlx_ptr;
	img = &data->img;
	img->potion_img[0] = create_img(data, p, "textures/potion/potion_1.xpm");
	img->potion_img[1] = create_img(data, p, "textures/potion/potion_2.xpm");
	img->potion_img[2] = create_img(data, p, "textures/potion/potion_3.xpm");
	img->potion_img[3] = create_img(data, p, "textures/potion/potion_4.xpm");
	img->potion_img[4] = create_img(data, p, "textures/potion/potion_1.xpm");
	img->potion_img[5] = create_img(data, p, "textures/potion/potion_2.xpm");
	img->potion_img[6] = create_img(data, p, "textures/potion/potion_3.xpm");
	img->potion_img[7] = create_img(data, p, "textures/potion/potion_4.xpm");
}

void	init_map(t_mlx_data *data)
{
	void	*p;

	p = data->mlx_ptr;
	data->img.floor_img = create_img(data, p, "textures/floor.xpm");
	data->img.wall_img = create_img(data, p, "textures/wall.xpm");
	data->img.exit_img = create_img(data, p, "textures/exit.xpm");
}

void	init_data(t_mlx_data *data)
{
	int		x;
	int		y;

	init_hero(data);
	init_enemy(data);
	init_potion(data);
	init_map(data);
	x = (data->win_width / data->img_width - data->map_width + 1) / 2;
	y = (data->win_height / data->img_height - data->map_height + 1) / 2;
	data->x_begin = x;
	data->y_begin = y;
	data->state = 0;
	data->score = 0;
}
