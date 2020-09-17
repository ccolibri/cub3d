#include "../includes/cub3d.h"

static void spr_params(t_all *all)
{
    int i;

    i = 0;
    while (i < all->map.sprites)
    {
        all->sprite[i].angle = atan2(all->sprite[i].y - all->plr.y, \
                            all->sprite[i].x - all->plr.x);
        while (all->sprite[i].angle - all->plr.angle > M_PI)
            all->sprite[i].angle -= 2.0 * M_PI;
        while (all->sprite[i].angle - all->plr.angle < -M_PI)
            all->sprite[i].angle += 2.0 * M_PI;
        all->sprite[i].angle -= all->plr.angle;
        all->sprite[i].dist = sqrt(pow(all->sprite[i].x - all->plr.x, 2) + \
                                pow(all->sprite[i].y - all->plr.y, 2));
        all->sprite[i].size = (all->map.pix / all->sprite[i].dist) * \
                                (all->frame.w / 2) / tan(FOV / 2);
        all->sprite[i].x_ff = all->frame.w / (FOV * (180 / M_PI)) * \
            ((180 / M_PI * all->sprite[i].angle) + 30) - all->sprite[i].size / 2;
        all->sprite[i].y_ff = all->frame.h / 2 - all->sprite[i].size / 2;
        all->sprite[i].step = all->text.spr.height / all->sprite[i].size;
        all->sprite[i].tex_pos = 0;
        i++;
    }
}

static void sort_spr(t_all *all)
{
    int i;
    int j;
    t_sprite tmp;

    i = 0;
    while (i < all->map.sprites)
    {
        j = 0;
        while (j < all->map.sprites - 1)
        {
            if (all->sprite[j].dist < all->sprite[j + 1].dist)
            {
                tmp = all->sprite[j];
                all->sprite[j] = all->sprite[j + 1];
                all->sprite[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

static void ft_sprite(t_all *all, t_sprite spr)
{
    int     i;
    int     j;
    int     text_y;
    int     text_x;

    i = -1;
    while (++i < spr.size)
    {
        if (spr.x_ff + i > all->frame.w || spr.x_ff + i < 0 || \
                    all->ray[i + (int)spr.x_ff].dist < spr.dist)
            continue;
        text_x = i / spr.size * all->text.spr.width;
        spr.tex_pos = 0;
        j = -1;
        while (++j < spr.size)
        {
            text_y = (unsigned int)spr.tex_pos & (all->text.spr.height - 1);
            spr.clr = (unsigned int *)(all->text.spr.addr + \
                        (text_y * all->text.spr.len + text_x * (all->text.spr.bpp / 8)));
            spr.tex_pos += spr.step;
            if (spr.y_ff + j > all->frame.h || spr.y_ff + i < 0 || *spr.clr == 0x0)
                continue;
            my_mlx_pixel_put(&all->img, spr.x_ff + i, spr.y_ff + j, *spr.clr);
        }
    }
}



void    rendering_spr(t_all *all)
{
    int i;

    i = 0;
    spr_params(all);
    sort_spr(all);
    while (i < all->map.sprites)
    {
        ft_sprite(all, all->sprite[i]);
        i++;
    }
}