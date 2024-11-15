/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:58:45 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/15 18:57:42 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/evo_libft.h"

# include <X11/keysym.h>
# include <stdlib.h>
# include <fcntl.h>

// typedef struct s_hero
// {
// 	void	*img_ptr[8];
// 	int		pos_x;
// 	int		pos_y;
// 	char	wach;
// 	char	type;
// 	char	block_on;
// }				t_hero;

// typedef struct s_img
// {
// 	void	*img_ptr[8];
// 	int		pos_x;
// 	int		pos_y;
// 	char	type;
// 	char	**wach;
// 	char	**block_on;
// }				t_img;

typedef struct s_map
{
	char	type;
	char	watch;
	char	block_on;
}				t_map;

typedef struct s_textures
{
	void	*floor_img;
	void	*wall_img;
	void	*exit_img;
	void	*hero_img[8];
	void	*potion_img[8];
	void	*enemy_img[8];
}				t_textures;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			x_begin;
	int			y_begin;
	int			img_width;
	int			img_height;
	int			win_width;
	int			win_height;
	int			map_width;
	int			map_height;
	int			x_pos;
	int			y_pos;
	t_map		**map;
	t_textures	img;
	int			state;
	int			score;
}				t_mlx_data;

/*---parsing.c---*/
int		check_only_one(char **map, char c);
int		map_is_closed(char **map);
int		get_nb_collectibles(char **map);
int		map_is_rectangular(char **map);
int		parsing(char **map);

/*---parsing_path.c---*/
void	find_player(char **map, int *x, int *y);
int		check_valid_path(char **map, int x, int y);

/*---so_long_utils.c---*/
int		all_collected(t_map **map, char c);
char	**tab_join_free(char **tab, char *line);
char	**tab_cpy(char **tab);
void	*create_img(t_mlx_data *data, void *p, char *path);

/*---init_data.c---*/
void	init_hero(t_mlx_data *data);
void	init_potion(t_mlx_data *data);
void	init_map(t_mlx_data *data);
void	init_data(t_mlx_data *data);

/*---check_init---*/
void	check_hero_init(t_mlx_data *data, int *error);
void	check_potion_init(t_mlx_data *data, int *error);
void	check_img_init(t_mlx_data *data);

/*---create_map.c---*/
char	**read_tab(int fd);
char	**create_tab_map(char *filename);
int		set_map(t_mlx_data *data, char **map);
void	create_map(t_mlx_data *data, char *filname);
void	set_pos_img(t_mlx_data *data);

/*---change_map.c---*/
void	set_orientation(t_map *bloc, int move);
void	set_new_position(t_mlx_data *data, int move_x, int move_y);
void	move_hero(t_mlx_data *data, int move_x, int move_y);

/*---print_map---*/
void	print_anim(t_mlx_data *data, int x_count, int y_count, void **anim);
void	print_img(t_mlx_data *data, int x_count, int y_count);
int		print_map(t_mlx_data *data);

/*---cleanning.c---*/
int		close_game_error(t_mlx_data *data);
int		close_game_ok(t_mlx_data *data);
void	free_tab(char **tab);
void	free_map(t_map **tab);
void	clear_img(t_mlx_data *data, void **img);
void	clear_data(t_mlx_data *data);

#endif