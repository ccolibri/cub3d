/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:16:32 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/23 16:37:05 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void			spr_params(t_all *all)
{
	int				i;

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

static void			sort_spr(t_all *all)
{
	int				i;
	int				j;
	t_sprite		tmp;

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

static void			ft_sprite(t_all *all, t_sprite sp)
{
	int				i;
	int				j;
	int				tex_y;
	int				tex_x;

	i = -1;
	while (++i < sp.size)
	{
		if (sp.x_ff + i > all->frame.w || sp.x_ff + i < 0 || \
					all->ray[i + (int)sp.x_ff].dist < sp.dist)
			continue;
		tex_x = i / sp.size * all->text.spr.width;
		sp.tex_pos = 0;
		j = -1;
		while (++j < sp.size)
		{
			tex_y = (unsigned int)sp.tex_pos & (all->text.spr.height - 1);
			sp.clr = (unsigned int *)(all->text.spr.addr + \
				(tex_y * all->text.spr.len + tex_x * (all->text.spr.bpp / 8)));
			sp.tex_pos += sp.step;
			if (sp.y_ff + j > all->frame.h || sp.y_ff + i < 0 || *sp.clr == 0x0)
				continue;
			my_mlx_pixel_put(&all->img, sp.x_ff + i, sp.y_ff + j, *sp.clr);
		}
	}
}

void				rendering_spr(t_all *all)
{
	int				i;

	i = 0;
	spr_params(all);
	sort_spr(all);
	while (i < all->map.sprites)
	{
		ft_sprite(all, all->sprite[i]);
		i++;
	}
}
