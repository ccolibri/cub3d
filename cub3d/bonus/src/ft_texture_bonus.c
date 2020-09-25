/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:27:24 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/20 20:27:37 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	import_text(char *path, t_img *text, t_all *all)
{
	if (text->img != NULL)
		exit_cub("Error : Multiple texture files", all);
	text->img = mlx_xpm_file_to_image(all->frame.mlx, \
			path, &text->width, &text->height);
	if (text->img == NULL)
		exit_cub("Error : Invalid texture file", all);
	text->addr = mlx_get_data_addr(text->img, \
				&text->bpp, &text->len, &text->endian);
	if (text->addr == NULL)
		exit_cub("Error : Invalid texture file", all);
}
