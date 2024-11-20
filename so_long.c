/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:22:38 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/20 11:51:15 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	reset_dash(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Shift_L)
		data->dash_on = 0;
	return (1);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	int	nb_move;

	if (keysym == XK_Shift_L)
		data->dash_on = 1;
	if (data->dash_on)
		nb_move = 3;
	else
		nb_move = 1;
	if (keysym == XK_Escape)
		close_game_ok(data);
	if (keysym == XK_Right || keysym == XK_d)
		move(data, &data->map[data->y_pos][data->x_pos], nb_move, 0);
	if (keysym == XK_Left || keysym == XK_a)
		move(data, &data->map[data->y_pos][data->x_pos], -nb_move, 0);
	if (keysym == XK_Up || keysym == XK_w)
		move(data, &data->map[data->y_pos][data->x_pos], 0, -nb_move);
	if (keysym == XK_Down || keysym == XK_s)
		move(data, &data->map[data->y_pos][data->x_pos], 0, nb_move);
	return (1);
}

void	pre_parsing(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		ft_printf(2, "Error\nThe program need only and only one argument\n");
		exit(-1);
	}
	i = ft_strlen(argv[1]) - 1;
	if (argv[1][i] != 'r' || argv[1][i - 1] != 'e'
		|| argv[1][i - 2] != 'b' || argv[1][i - 3] != '.')
	{
		ft_printf(2, "Error\n");
		ft_printf(2, "The program need as an argument a .ber format map\n");
		exit(-1);
	}
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	pre_parsing(argc, argv);
	create_map(&data, argv[1]);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		close_game_error(&data);
	data.win_width = 1920;
	data.win_height = 1080;
	data.mlx_win = mlx_new_window(data.mlx_ptr, 1920, 1080, "so_long");
	if (!data.mlx_win)
		close_game_error(&data);
	init_data(&data);
	check_img_init(&data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, handle_input, &data);
	mlx_hook(data.mlx_win, KeyRelease, KeyRelease, reset_dash, &data);
	mlx_hook(data.mlx_win, DestroyNotify, KeyPressMask, close_game_ok, &data);
	mlx_loop_hook(data.mlx_ptr, print_map, &data);
	mlx_loop(data.mlx_ptr);
}
