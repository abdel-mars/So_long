/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:31:06 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/05/17 01:41:11 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_C

# include "./mlx/mlx.h"
# include "libft/libft.h"

#include "mlx/mlx.h"
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_img
{
    void    *player;
    void    *wall;
    void    *collectibale;
    void    *floor;
    void    *exit;
}   t_img;


typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_wall;
    void *img_floor;
    void *img_collectible;
    void *img_player;
    void *img_exit;
    int img_width;
    int img_height;
    char **map;
    int map_width;
    int map_height;
}  t_data;

char **read_map(const char *filename, int *width, int *height);
void render_map(t_data *data);


#endif