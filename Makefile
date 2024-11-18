NAME		=	so_long
FLAGS		=	-Wall -Wextra -Werror -g
LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
MLX_DIR		=	minilibx-linux
MLX			=	$(MXL_DIR)/libmlx.a

SRC			=	so_long.c parsing.c parsing_path.c so_long_utils.c init_data.c create_map.c print_map.c cleanning.c change_map.c check_init.c ia_monster.c
OBJ			=	$(SRC:.c=.o)

# Variables
Color_Off:=\033[0m
Green:=\033[0;32m
Yellow:=\033[0;33m
Purple:=\033[0;35m
clean_done:=0

# Rules
ifndef VERBOSE
.SILENT:
endif

all			:	$(NAME)

$(MLX)		:
			make -C $(MLX_DIR) --no-print-directory >/dev/null 2>/dev/null
			echo "$(Purple)👷---- minilibx built -----👷$(Color_Off)"

$(LIBFT)	:
			make -C $(LIBFT_DIR) --no-print-directory --silent
			echo "$(Purple)👷------ libft built ------👷$(Color_Off)"

$(NAME)		:	$(MLX) $(LIBFT) $(OBJ)
			cc $(FLAGS) $(OBJ) $(LIBFT) -Lminilibx-linux -lmlx -lX11 -lXext -o $(NAME)
			echo "$(Green)✅️----- $(NAME) ready -----✅️$(Color_Off)"

.c.o		:
			cc $(FLAGS) -c $< -o $@

clean		:
			rm -f $(OBJ)
			if [ $(clean_done) -eq 0 ];\
			then $(MAKE) -C $(LIBFT_DIR) $@ --no-print-directory --silent;\
			echo "$(Yellow)🧹✨---- sweeping up ----✨🧹$(Color_Off)";\
			fi

fclean		:
			make clean_done=1 clean --no-print-directory
			rm -f $(NAME)
			$(MAKE) -C $(LIBFT_DIR) $@ --no-print-directory --silent
			$(MAKE) -C $(MLX_DIR) clean --no-print-directory >/dev/null
			echo "$(Yellow)🚨----- hard cleaning -----🚨$(Color_Off)"

re			:	fclean all

.PHONY	=	all clean fclean re