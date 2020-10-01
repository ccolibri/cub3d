/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:15:16 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/20 20:16:00 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_img			init_side(t_all *all, t_ray ray, int *flag)
{
	*flag = 0;
	if (ray.is_vert)
	{
		if (ray.is_right)
			return (all->text.w);
		else
		{
			*flag = 1;
			return (all->text.e);
		}
	}
	else
	{
		if (ray.is_up)
			return (all->text.n);
		else
		{
			*flag = 1;
			return (all->text.s);
		}
	}
}

static t_render_utils	create_stripe(t_all *all, int i, t_img text)
{
	t_render_utils col;

	col.plane = (all->frame.w / 2.0) / tan(FOV / 2);
	all->ray[i].dist = all->ray[i].dist == 0 ? 1 : all->ray[i].dist;
	col.dist = all->ray[i].dist * cos(all->ray[i].angle - all->plr.angle);
	col.height = (all->map.pix / col.dist) * col.plane;
	col.top = all->frame.h / 2.0 - col.height / 2;
	if (all->ray[i].is_vert)
		col.t_x = remainder(all->ray[i].hit_y, all->map.pix) / \
					all->map.pix * text.width;
	else
		col.t_x = remainder(all->ray[i].hit_x, all->map.pix) / \
					all->map.pix * text.width;
	col.t_x = col.t_x & (unsigned int)(text.height - 1);
	col.step = text.height / col.height;
	col.text_pos = (col.top - all->frame.h / 2.0 + col.height / 2.0) * col.step;
	col.y = (int)col.top;
	return (col);
}

static void				rendering_walls(t_all *all)
{
	t_img				text;
	t_render_utils		c;
	int					i;
	int					flag;

	i = 0;
	while (i < all->frame.w)
	{
		text = init_side(all, all->ray[i], &flag);
		c = create_stripe(all, i, text);
		while (c.y < c.top + c.height)
		{
			c.t_y = (unsigned int)c.text_pos & ((unsigned int)text.height - 1);
			c.color = !flag ? text.addr + (c.t_y * text.len + c.t_x *
						(text.bpp / 8)) : text.addr + (c.t_y * text.len +
							((64 - c.t_x) % 64) * (text.bpp / 8));
			c.text_pos += c.step;
			if (c.y >= 0 && c.y < all->frame.h && i >= 0 && i < all->frame.w)
				my_mlx_pixel_put(&all->img, i, c.y, *(unsigned int *)c.color);
			c.y++;
		}
		i++;
	}
}

int						rendering(t_all *all)
{
	mlx_do_sync(all->frame.mlx);
	ft_floor_n_ceiling(0, 0, all);
	ft_floor_n_ceiling(0, all->frame.h / 2, all);
	plr_spot(all);
	raycast(all);
	rendering_walls(all);
	rendering_spr(all);
	return (1);
}
