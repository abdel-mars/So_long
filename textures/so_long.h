
#ifndef SO_LONG_H
# define SO_LONG_H

# define PLAYER "./textures/player.xpm"
# define COLLECTIBLE "./textures/collectible.xpm"
# define EXIT "./textures/exit.xpm"
# define WALL "./textures/wall.xpm"
# define FLOOR "./textures/floor.xpm"
# define ONBOX "./textures/on_box.xpm"

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

# include "./minilibx/mlx.h"
# include "libft/libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_img
{
	void	*collectible;
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*on_box;
}	t_img;

typedef struct s_game
{
	t_img	img;
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_floodfill;
	char	temp;
	int		line;
	int		col;
	int		exit;
	int		score;
	int		player;
	int		player_on_box;
	int		player_y;
	int		player_x;
	int		end_game;
	int		move;
}	t_game;

void	check_args(t_game *game, int argc, char **argv);
void	check_map(t_game *game);
void	valid_map(t_game *game);
void	valid_path(t_game *game, int fd);
void	start_validations(t_game *game, int fd);
int		key_handler(int x, t_game *game);
void	get_maps(t_game *game, int fd);
void	put_images(t_game *game);
void	put_map(int x, int y, char c, t_game *game);
int		get_col_size(t_game *game, int fd);
int		get_line_size(t_game *game, int fd);
int		render_img(t_game *game);
int		collectible_counter(t_game *game);
void	player_position(t_game *game);
void	free_map(t_game *game);
void	free_map_floodfill(t_game *game);
void	free_img(t_game *game);
void	ft_exit(char *s, t_game *game);
int		close_window(t_game *game);

// Function declarations for reachability checks
void check_player_reachability(t_game *game);
void check_collectible_reachability(t_game *game);
void check_exit_reachability(t_game *game);

#endif
