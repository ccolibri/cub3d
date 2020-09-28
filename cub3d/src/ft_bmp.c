/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:55:34 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/20 19:57:29 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_bmp_file_header		file_header(t_all *all)
{
	t_bmp_file_header	bf;

	bf.type = 0x4D42;
	bf.size = sizeof(t_bmp_file_header) + sizeof(t_bmp_info_header) + \
				all->frame.w * all->frame.h * 4;
	bf.reserved1 = 0;
	bf.reserved2 = 0;
	bf.off_bits = sizeof(t_bmp_file_header) + sizeof(t_bmp_info_header);
	return (bf);
}

t_bmp_info_header		info_header(t_all *all)
{
	t_bmp_info_header	bi;

	bi.size = 40;
	bi.w = all->frame.w;
	bi.h = (all->frame.h - 1) * (-1);
	bi.planes = 1;
	bi.bit_cnt = all->img.bpp;
	bi.compression = 0;
	bi.size_image = 0;
	bi.x_pels_per_meter = 0;
	bi.y_pels_per_meter = 0;
	bi.clr_used = 0;
	bi.clr_important = 0;
	return (bi);
}

void					ft_bmp(t_all *all)
{
	int					fd;
	t_bmp_file_header	bf;
	t_bmp_info_header	bi;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	bf = file_header(all);
	bi = info_header(all);
	if (!write(fd, &bf, sizeof(bf)))
		exit_cub("Error\nFH error", all);
	if (!write(fd, &bi, sizeof(bi)))
		exit_cub("Error\nIH error", all);
	if (!write(fd, all->img.addr, all->frame.w * all->frame.h * 4))
		exit_cub("Error\nBMP data error", all);
	close(fd);
	exit_cub("Screenshot has been saved", all);
}
