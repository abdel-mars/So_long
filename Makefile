# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 14:03:46 by abdel-ma          #+#    #+#              #
#    Updated: 2024/06/28 15:48:20 by abdel-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -L ./minilibx -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a
LIBFTDIR = ./libft
MINILIBX_PATH = ./minilibx
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
