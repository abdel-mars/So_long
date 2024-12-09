# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 14:03:46 by abdel-ma          #+#    #+#              #
#    Updated: 2024/07/04 22:20:46 by abdel-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra

# Update the path to libmlx and add correct include paths for X11
MLXFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -I./minilibx-linux

LIBFT = ./libft/libft.a
LIBFTDIR = ./libft

# Correct path to MiniLibX library
MINILIBX_PATH = ./minilibx-linux
MINILIBX = $(MINILIBX_PATH)/libmlx.a

SRC =	src/so_long.c \
	src/game_end.c \
	src/map_init.c \
	src/moves.c \
	src/validate_path.c \
	src/validate_game.c \
	src/render_img.c \
	src/map_size.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MINILIBX_PATH)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(FLAGS) -lm $(SRC) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "[Success] ./so_long created."

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -rf $(OBJ)
	@echo "[Deleting] object files deleted."

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -rf $(NAME) $(OBJ)
	@echo "[Deleting] .a deleted."

re: fclean all

.PHONY: all clean fclean re
