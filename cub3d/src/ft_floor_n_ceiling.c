#include "../includes/cub3d.h"

void    my_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
    char *dst;
    
    dst = img->addr + (y * img->len + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
}

void ft_floor_n_ceiling(int x, int y, t_all *all)
{
    int i;
    int j;
    int width;
    int height;
    int color;

    i = x;
    width = all->frame.w;
    height = all->frame.h / 2;
    color = y == 0 ? all->map.c_clr : all->map.f_clr;
    while (i <= x + width)
    {
        j = y;
        while (j <= y + height)
        {
            my_mlx_pixel_put(&all->img, i, j, color);
            j++;
        }
        i++;
    }
}