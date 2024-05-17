/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 22:46:03 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/05/17 01:25:45 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char **read_map(const char *filename, int *width, int *height)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0) return NULL;

    // First pass: determine the width and height of the map
    char *line = get_next_line(fd);
    if (!line) return NULL;
    *width = strlen(line) - 1; // Subtract 1 to ignore newline character
    *height = 0;
    while (line)
    {
        (*height)++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);

    // Allocate memory for the map
    char **map = malloc((*height) * sizeof(char *));
    if (!map) return NULL;

    // Second pass: read the map into the allocated memory
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        free(map);
        return NULL;
    }

    for (int i = 0; i < *height; i++)
    {
        line = get_next_line(fd);
        if (!line)
        {
            for (int j = 0; j < i; j++)
                free(map[j]);
            free(map);
            close(fd);
            return NULL;
        }
        map[i] = strdup(line);
        free(line);
    }
    close(fd);
    return map;
}

void render_map(t_data *data)
{
    int x, y;
    for (y = 0; y < data->map_height; y++)
    {
        for (x = 0; x < data->map_width; x++)
        {
            if (data->map[y][x] == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_wall, x * data->img_width, y * data->img_height);
            else if (data->map[y][x] == '0')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, x * data->img_width, y * data->img_height);
            else if (data->map[y][x] == 'C')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_collectible, x * data->img_width, y * data->img_height);
            else if (data->map[y][x] == 'P')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_player, x * data->img_width, y * data->img_height);
            else if (data->map[y][x] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_exit, x * data->img_width, y * data->img_height);
        }
    }
}
