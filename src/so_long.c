/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 01:24:41 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/05/17 01:24:42 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int handle_input(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        printf("the %d key (ESC) has been pressd \n\n", keysym);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
    printf("the %d key has been pressed\n\n", keysym);
    return (0);

}


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s map_file.ber\n", argv[0]);
        return 1;
    }

    t_data data;
    int width, height;

    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (free(data.mlx_ptr), 1);

    // Read the map
    data.map = read_map(argv[1], &width, &height);
    if (!data.map)
    {
        fprintf(stderr, "Error reading map\n");
        return 1;
    }
    data.map_width = width;
    data.map_height = height;

    data.win_ptr = mlx_new_window(data.mlx_ptr, data.map_width * 64, data.map_height * 64, "So_long");
    if (!data.win_ptr)
    {
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (1);
    }

    data.img_wall = mlx_xpm_file_to_image(data.mlx_ptr, "path/to/wall.xpm", &data.img_width, &data.img_height);
    data.img_floor = mlx_xpm_file_to_image(data.mlx_ptr, "path/to/floor.xpm", &data.img_width, &data.img_height);
    data.img_collectible = mlx_xpm_file_to_image(data.mlx_ptr, "path/to/collectible.xpm", &data.img_width, &data.img_height);
    data.img_player = mlx_xpm_file_to_image(data.mlx_ptr, "path/to/player.xpm", &data.img_width, &data.img_height);
    data.img_exit = mlx_xpm_file_to_image(data.mlx_ptr, "path/to/exit.xpm", &data.img_width, &data.img_height);

    if (!data.img_wall || !data.img_floor || !data.img_collectible || !data.img_player || !data.img_exit)
    {
        if (data.img_wall) mlx_destroy_image(data.mlx_ptr, data.img_wall);
        if (data.img_floor) mlx_destroy_image(data.mlx_ptr, data.img_floor);
        if (data.img_collectible) mlx_destroy_image(data.mlx_ptr, data.img_collectible);
        if (data.img_player) mlx_destroy_image(data.mlx_ptr, data.img_player);
        if (data.img_exit) mlx_destroy_image(data.mlx_ptr, data.img_exit);
        mlx_destroy_window(data.mlx_ptr, data.win_ptr);
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (1);
    }

    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_input, &data);

    render_map(&data);

    mlx_loop(data.mlx_ptr);

    for (int i = 0; i < data.map_height; i++)
        free(data.map[i]);
    free(data.map);
    mlx_destroy_image(data.mlx_ptr, data.img_wall);
    mlx_destroy_image(data.mlx_ptr, data.img_floor);
    mlx_destroy_image(data.mlx_ptr, data.img_collectible);
    mlx_destroy_image(data.mlx_ptr, data.img_player);
    mlx_destroy_image(data.mlx_ptr, data.img_exit);
    mlx_destroy_window(data.mlx_ptr, data.win_ptr);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);

    return 0;
}
