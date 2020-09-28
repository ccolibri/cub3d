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

#include "../includes/cub3d.h"

void		import_text(char *path, t_img *text, t_all *all)
{
	if (text->img != NULL)
		exit_cub("Error\nMultiple texture files", all);
	text->img = mlx_xpm_file_to_image(all->frame.mlx, \
			path, &text->width, &text->height);
	if (text->img == NULL)
		exit_cub("Error\nInvalid texture file", all);
	text->addr = mlx_get_data_addr(text->img, \
				&text->bpp, &text->len, &text->endian);
	if (text->addr == NULL)
		exit_cub("Error\nInvalid texture file", all);
}

void		make_texture(char *str, t_all *all, char type)
{
	while (*str && ft_isspace(*str))
		str++;
	str = str + 2;
	while (*str && ft_isspace(*str))
		str++;
	if (type == 'N')
		import_text(str, &all->text.n, all);
	if (type == 'S')
		import_text(str, &all->text.s, all);
	if (type == 'W')
		import_text(str, &all->text.w, all);
	if (type == 'E')
		import_text(str, &all->text.e, all);
	if (type == 's')
		import_text(str, &all->text.spr, all);
}
