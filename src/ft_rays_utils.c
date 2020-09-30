/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:12:37 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/20 20:14:46 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static double		ft_angle(double angle)
{
	angle = remainder(angle, M_PI * 2);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

static double		distance(double x1, double x2, double y1, double y2)
{
	double			result;

	result = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (result);
}

static t_ray_utils	vertical(t_all *all, t_ray *ray)
{
	t_ray_utils		v;

	v.dist = INT_MAX;
	v.x = floor(all->plr.x / all->map.pix) * all->map.pix;
	v.x += ray->is_right ? all->map.pix : 0;
	v.y = all->plr.y + (v.x - all->plr.x) * tan(ray->angle);
	if (v.y < 0 || v.y > all->map.pix * all->map.y)
		return (v);
	v.x_step = all->map.pix;
	v.x_step *= ray->is_left ? -1 : 1;
	v.y_step = all->map.pix * tan(ray->angle);
	v.y_step *= (ray->is_up && v.y_step > 0) ? -1 : 1;
	v.y_step *= (ray->is_down && v.y_step < 0) ? -1 : 1;
	while (v.x >= 0 && v.x < all->map.pix * (all->map.x) &&
		v.y >= 0 && v.y < all->map.pix * all->map.y)
	{
		if (ft_wall(v.x - (ray->is_left ? 1 : 0), v.y, all) == TRUE)
		{
			v.dist = distance(all->plr.x, v.x, all->plr.y, v.y);
			return (v);
		}
		v.x += v.x_step;
		v.y += v.y_step;
	}
	return (v);
}

static t_ray_utils	horisontal(t_all *all, t_ray *ray)
{
	t_ray_utils		h;

	h.dist = INT_MAX;
	h.y = floor(all->plr.y / all->map.pix) * all->map.pix;
	h.y += ray->is_down ? all->map.pix : 0;
	h.x = all->plr.x + (h.y - all->plr.y) / tan(ray->angle);
	if (h.y < 0 || h.y > all->map.pix * all->map.y)
		return (h);
	h.y_step = all->map.pix;
	h.y_step *= ray->is_up ? -1 : 1;
	h.x_step = all->map.pix / tan(ray->angle);
	h.x_step *= (ray->is_left && h.x_step > 0) ? -1 : 1;
	h.x_step *= (ray->is_right && h.x_step < 0) ? -1 : 1;
	while (h.x >= 0 && h.x < all->map.pix * all->map.x && h.y >= 0
			&& h.y < all->map.pix * all->map.y)
	{
		if (ft_wall(h.x, h.y - (ray->is_up ? 1 : 0), all) == TRUE)
		{
			h.dist = distance(all->plr.x, h.x, all->plr.y, h.y);
			return (h);
		}
		h.x += h.x_step;
		h.y += h.y_step;
	}
	return (h);
}

void				raycast(t_all *all)
{
	int				i;
	double			angle;
	t_ray_utils		h;
	t_ray_utils		v;

	i = 0;
	angle = all->plr.angle - FOV / 2;
	while (i < all->frame.w)
	{
		angle = ft_angle(angle);
		all->ray[i].angle = angle;
		all->ray[i].is_down = angle > 0 && angle < M_PI;
		all->ray[i].is_up = !all->ray[i].is_down;
		all->ray[i].is_right = angle < (M_PI / 2) || angle > (M_PI * 1.5);
		all->ray[i].is_left = !all->ray[i].is_right;
		v = vertical(all, &all->ray[i]);
		h = horisontal(all, &all->ray[i]);
		all->ray[i].dist = v.dist > h.dist ? h.dist : v.dist;
		all->ray[i].hit_x = v.dist > h.dist ? h.x : v.x;
		all->ray[i].hit_y = v.dist > h.dist ? h.y : v.y;
		all->ray[i].is_vert = v.dist > h.dist ? FALSE : TRUE;
		angle += FOV / all->frame.w;
		i++;
	}
}
