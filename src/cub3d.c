/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:51:38 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/23 13:55:19 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_wall(double x, double y, t_all *all)
{
	int		m_x;
	int		m_y;

	if (x < 0 || x > all->map.pix * all->map.x || y < 0
			|| y > all->map.pix * all->map.y)
		return (OUTSIDE);
	m_x = (int)((x / all->map.pix));
	m_y = (int)((y / all->map.pix));
	if (m_x < 0 || m_x >= all->map.x || m_y < 0 || m_y >= all->map.y)
		return (OUTSIDE);
	if (all->map.tab[m_y][m_x] == '2')
		return (SPRITE);
	if (all->map.tab[m_y][m_x] == ' ')
		return (1);
	return (all->map.tab[m_y][m_x] == '1');
}

void		plr_spot(t_all *all)
{
	double	x;
	double	y;
	double	step;
	double	sideways;

	sideways = all->plr.sideways ? M_PI / 2 * all->plr.walk_dir : 0;
	step = all->plr.walk_dir * all->plr.walk_speed;
	step = all->plr.sideways && step < 0 ? -step : step;
	all->plr.angle += all->plr.turn_dir * all->plr.turn_speed;
	x = all->plr.x + cos(all->plr.angle - sideways) * step * 2;
	y = all->plr.y + sin(all->plr.angle - sideways) * step * 2;
	if (!ft_wall(x, y, all))
	{
		all->plr.x = all->plr.x + cos(all->plr.angle - sideways) * step;
		all->plr.y = all->plr.y + sin(all->plr.angle - sideways) * step;
	}
	all->plr.turn_dir = 0;
	all->plr.walk_dir = 0;
	all->plr.sideways = 0;
}

int			key_p(int keycode, t_all *all)
{
	if (keycode == ESC)
		close_me(all);
	if (keycode == LEFT)
		all->plr.turn_dir = -1;
	else if (keycode == RIGHT)
		all->plr.turn_dir = 1;
	else if (keycode == W)
		all->plr.walk_dir = 1;
	else if (keycode == S)
		all->plr.walk_dir = -1;
	else if (keycode == D)
	{
		all->plr.walk_dir = -1;
		all->plr.sideways = TRUE;
	}
	else if (keycode == A)
	{
		all->plr.walk_dir = 1;
		all->plr.sideways = TRUE;
	}
	rendering(all);
	mlx_put_image_to_window(all->frame.mlx, all->frame.win, all->img.img, 0, 0);
	return (1);
}

int			key_r(int keycode, t_all *all)
{
	if (keycode == LEFT)
		all->plr.turn_dir = 0;
	else if (keycode == RIGHT)
		all->plr.turn_dir = 0;
	else if (keycode == W)
		all->plr.walk_dir = 0;
	else if (keycode == S)
		all->plr.walk_dir = 0;
	else if (keycode == D)
	{
		all->plr.walk_dir = 0;
		all->plr.sideways = FALSE;
	}
	else if (keycode == A)
	{
		all->plr.walk_dir = 0;
		all->plr.sideways = FALSE;
	}
	mlx_put_image_to_window(all->frame.mlx, all->frame.win, all->img.img, 0, 0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_all	all;
	int		bmp;

	bmp = validate_args(argc, argv, &all);
	preparing_cub(&all, argv[1], bmp);
	mlx_hook(all.frame.win, 17, 0, close_me, &all);
	mlx_hook(all.frame.win, 2, 0, key_p, &all);
	mlx_hook(all.frame.win, 3, 0, key_r, &all);
	mlx_loop(all.frame.mlx);
	return (0);
}
