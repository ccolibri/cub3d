/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:00:03 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/23 15:47:50 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int			close_me(t_all *all)
{
	exit_cub("Exit from cub.", all);
	return (0);
}

static void	close_mlx(t_all *all)
{
	if (all->frame.mlx == NULL)
		return ;
	if (all->frame.win)
		mlx_destroy_window(all->frame.mlx, all->frame.win);
	if (all->text.e.img)
		mlx_destroy_image(all->frame.mlx, all->text.e.img);
	if (all->text.n.img)
		mlx_destroy_image(all->frame.mlx, all->text.n.img);
	if (all->text.s.img)
		mlx_destroy_image(all->frame.mlx, all->text.s.img);
	if (all->text.w.img)
		mlx_destroy_image(all->frame.mlx, all->text.w.img);
	if (all->text.spr.img)
		mlx_destroy_image(all->frame.mlx, all->text.spr.img);
	if (all->img.img)
		mlx_destroy_image(all->frame.mlx, all->img.img);
	if (all->frame.mlx)
		free(all->frame.mlx);
}

void		exit_cub(char *error, t_all *all)
{
	if (errno != 0 && errno != 11)
		perror(error);
	else
		ft_putendl(error);
	close_mlx(all);
	free_mm(NULL);
	errno = errno == 11 ? 0 : errno;
	kill(all->frame.pid, SIGTERM);
	exit(errno);
}
