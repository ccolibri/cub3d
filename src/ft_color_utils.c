/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:58:19 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/20 19:59:43 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		create_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		create_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		create_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		create_b(int trgb)
{
	return (trgb & 0xFF);
}
