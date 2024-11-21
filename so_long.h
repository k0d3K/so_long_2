/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:58:45 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/21 13:23:30 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/evo_libft.h"

# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	int		x_pos;
	int		y_pos;
	char	type;
	char	side;
	char	x_move;
	int		y_move;
	char	last_type;
	int		frame;
}				t_map;

typedef struct s_textures
{
	void	*floor_img;
	void	*wall_img;
	void	*exit_img;
	void	*score_img;
	void	*hero_img[8];
	void	*potion_img[8];
	void	*monster_img[8];
	void	*m_death_l[8];
	void	*m_death_r[8];
	void	*numbers_img[10];
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
	int			dash_on;
	t_map		**map;
	t_textures	img;
	int			seed;
	int			state;
	int			score;
}				t_mlx_data;

/*---so_long.c---*/
int		reset_dash(int keysym, t_mlx_data *data);
int		handle_input(int keysym, t_mlx_data *data);
void	pre_parsing(int argc, char **argv);

/*---so_long_utils.c---*/
int		all_collected(t_map **map, char c);
int		size_number(unsigned int n);
int		size_tab(char **tab);

/*---parsing.c---*/
int		check_only_one(char **map, char c);
int		map_is_closed(char **map);
int		get_nb_collectibles(char **map);
int		map_is_rectangular(char **map);
int		parsing(char **map);

/*---parsing_2.c---*/
void	find_player(char **map, int *x, int *y);
int		check_valid_path(char **map, int x, int y);
int		check_characters(char **map);

/*---init_data.c---*/
void	init_hero(t_mlx_data *data);
void	init_monster(t_mlx_data *data);
void	init_potion(t_mlx_data *data);
void	init_map(t_mlx_data *data);
void	init_data(t_mlx_data *data);

/*---init_data_2.c---*/
void	init_monster_death(t_mlx_data *data);
void	*create_img(t_mlx_data *data, void *p, char *path);

/*---check_init.c---*/
void	check_hero_init(t_mlx_data *data, int *error);
void	check_potion_init(t_mlx_data *data, int *error);
void	check_monster_init(t_mlx_data *data, int *error);
void	check_numbers_init(t_mlx_data *data, int *error);
void	check_img_init(t_mlx_data *data);

/*---check_init_2.c---*/
void	check_m_death_init(t_mlx_data *data, int *error);
void	check_map_init(t_mlx_data *data, int *error);

/*---create_map.c---*/
char	**read_tab(int fd);
char	**create_tab_map(char *filename);
int		set_map(t_mlx_data *data, char **map);
void	create_map(t_mlx_data *data, char *filename);

/*---create_map_2.c---*/
char	**tab_join_free(char **tab, char *line);
char	*str_cpy_nl(char *str);
char	**tab_cpy(char **tab);

/*---change_map.c---*/
void	move_hero(t_mlx_data *data, t_map *new_tile);
int		move_monster(t_mlx_data *data, t_map *new_tile);
void	move(t_mlx_data *data, t_map *old_tile, int move_x, int move_y);

/*---change_map_2.c---*/
void	kill(t_map *tile);
void	set_move_x(t_mlx_data *data, t_map *old_tile, int *move_x);
void	set_move_y(t_mlx_data *data, t_map *old_tile, int *move_y);
void	set_transition(t_map *new_tile, t_map *old_tile, int x, int y);

/*---print_map.c---*/
void	print_tile(t_mlx_data *data, int x_count, int y_count);
void	print_score(t_mlx_data *data, int x, int y);
int		print_map(t_mlx_data *data);

/*---print_map_2.c---*/
void	print_transition(t_mlx_data *data, t_map *tile, int x, int y);
void	print_anim(t_mlx_data *data, int x_count, int y_count, void **anim);
void	print_monster_death(t_mlx_data *data, int x_count, int y_count);
void	print_img(t_mlx_data *data, void *img, t_map *tile);

/*---ia_monster---*/
int		generate_move(int *seed);
void	ia_monster(t_mlx_data *data, int *x_count, int *y_count);
void	update_monster_position(t_mlx_data *data);

/*---cleanning.c---*/
int		close_game_error(t_mlx_data *data);
int		close_game_ok(t_mlx_data *data);
void	free_tab(void **tab);
void	clear_img(t_mlx_data *data, void **img, int anim);
void	clear_data(t_mlx_data *data);

#endif