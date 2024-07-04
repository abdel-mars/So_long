/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:05:00 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/07/04 22:14:24 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_img(t_game *game)
{
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.on_box)
		mlx_destroy_image(game->mlx, game->img.on_box);
	mlx_destroy_display(game->mlx);
	free_map(game);
	free(game->mlx);
	exit(0);
}

void	ft_exit(char *s, t_game *game)
{
	ft_printf("Error\nSomething is wrong!\n%s\n", s);
	if (game->map && game->map[0])
		free_map(game);
	exit(0);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_map_floodfill(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_floodfill[i])
	{
		free(game->map_floodfill[i]);
		i++;
	}
	free(game->map_floodfill);
}

int	close_window(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_img(game);
	free_map(game);
	free (game->mlx);
	free (game);
	exit (0);
}
