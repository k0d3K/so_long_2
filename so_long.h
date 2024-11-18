/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:58:45 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/18 12:49:19 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/evo_libft.h"

# include <X11/keysym.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	int		x_pos;
	int		y_pos;
	char	type;
	char	watch;
	char	block_on;
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
	void	*enemy_img[8];
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
	t_map		**map;
	t_textures	img;
	int			seed;
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
int		size_number(unsigned int n);

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
void	create_map(t_mlx_data *data, char *filename);

/*---change_map.c---*/
void	set_move(t_mlx_data *data, t_map *old_bloc, int *move_x, int *move_y);

void	move(t_mlx_data *data, t_map *old_bloc, int move_x, int move_y);

/*---print_map---*/
void	print_anim(t_mlx_data *data, int x_count, int y_count, void **anim);
void	print_img(t_mlx_data *data, int x_count, int y_count);
void	print_score(t_mlx_data *data, int x, int y);
int		print_map(t_mlx_data *data);

/*---ia_monster---*/
int		generate_move(int *seed);
void	ia_monster(t_mlx_data *data, t_map *bloc, int *x_move, int *y_move);
void	update_monster_position(t_mlx_data *data);

/*---cleanning.c---*/
int		close_game_error(t_mlx_data *data);
int		close_game_ok(t_mlx_data *data);
void	free_tab(char **tab);
void	free_map(t_map **tab);
void	clear_anim(t_mlx_data *data, void **img);
void	clear_data(t_mlx_data *data);

#endif