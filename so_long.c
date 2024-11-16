/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:22:38 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/16 11:18:53 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		close_game_ok(data);
	if (keysym == XK_Right || keysym == XK_d)
		move_hero(data, 1, 0);
	if (keysym == XK_Left || keysym == XK_a)
		move_hero(data, -1, 0);
	if (keysym == XK_Up || keysym == XK_w)
		move_hero(data, 0, -1);
	if (keysym == XK_Down || keysym == XK_s)
		move_hero(data, 0, 1);
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
	set_pos_img(&data);
	mlx_key_hook(data.mlx_win, handle_input, &data);
	mlx_hook(data.mlx_win, 17, 1L << 1, close_game_ok, &data);
	mlx_loop_hook(data.mlx_ptr, print_map, &data);
	mlx_loop(data.mlx_ptr);
}
