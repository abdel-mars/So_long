#include "so_long.h"
#include "texture.h"

typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
}t_data;

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


int main()
{
    t_data data;

    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (free(data.mlx_ptr), 1);

    data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "So_long");
    if (!data.win_ptr)
    {
        mlx_destroy_display(data.mlx_ptr);
        free (data.mlx_ptr);
        return (1);
    }
    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_input, &data);
    mlx_loop(data.mlx_ptr);
    
    
    return (0);
}
