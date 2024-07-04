/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:06:38 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/07/04 21:19:19 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_images(t_game *game)
{
	int	len;

	len = 64;
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &len, &len);
	game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &len, &len);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &len, &len);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &len, &len);
	game->img.collectible = mlx_xpm_file_to_image
		(game->mlx, COLLECTIBLE, &len, &len);
	game->img.on_box = mlx_xpm_file_to_image(game->mlx, ONBOX, &len, &len);
}

void	put_map(int x, int y, char c, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, x * 64, y * 64);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.floor, x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player, x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.collectible, x * 64, y * 64);
	if (c == 'B')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.on_box, x * 64, y * 64);
}

int	collectible_counter(t_game *game)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	c = 0;
	while (x < game->line)
	{
		while (y < game->col)
		{
			if (game->map[x][y] == 'C')
			{
				c++;
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (c);
}

void	player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->line)
	{
		while (y < game->col)
		{
			if (game->map[x][y] == 'P')
			{
				game->player_x = y;
				game->player_y = x;
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void	start_validations(t_game *game, int fd)
{
	ft_printf("Init validations...\n");
	check_map(game);
	valid_map(game);
	valid_path(game, fd);
}
