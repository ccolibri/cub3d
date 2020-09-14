#include "cub3d.h"

void ft_floor_n_ceiling(int x, int y, t_all *all)
{
    int i;
    int j;
    int w;
    int h;
    int clr;

    i = x;
    w = all->frame.w;
    h = all->frame.h / 2;
    clr = y == 0 ? all->map.c_clr : all->map.f_clr;
    while (i <= x + width)
    {
        j = y;
        while (j <= y + h)
        {
            mlx_pixel_put(&all->img, i, j, clr);
            j++;
        }
        i++;
    }
}