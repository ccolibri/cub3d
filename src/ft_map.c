/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:03:54 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/20 20:07:58 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		init_player(char wall, int x, int y, t_all *all)
{
	if (all->plr.angle != -1 || all->plr.x != 0 || all->plr.y != 0)
		exit_cub("Error\nMultiple player", all);
	all->plr.x = x + 0.5;
	all->plr.y = y + 0.5;
	if (wall == 'N')
		all->plr.angle = 3 * M_PI / 2;
	else if (wall == 'S')
		all->plr.angle = M_PI / 2;
	else if (wall == 'W')
		all->plr.angle = M_PI;
	else if (wall == 'E')
		all->plr.angle = 0;
}

static void		ft_align(t_all *all, int max)
{
	int			i;
	char		*tmp;

	i = 0;
	while (all->map.tab[i] != NULL)
	{
		tmp = all->map.tab[i];
		all->map.tab[i] = malloc_mm(sizeof(char) * max + 1);
		ft_memset(all->map.tab[i], ' ', max);
		all->map.tab[i][max] = '\0';
		ft_memcpy(all->map.tab[i], tmp, ft_strlen(tmp));
		free_mm(tmp);
		i++;
	}
	all->map.x = max;
	all->map.y = i;
}

static void		draw_sprite(t_all *all)
{
	int			i;
	int			x;
	int			y;

	y = 0;
	i = 0;
	all->sprite = malloc_mm(sizeof(t_sprite) * (all->map.sprites));
	if (all->sprite == NULL)
		exit_cub("Error\nMalloc for sprite failed", all);
	while (all->map.tab[y])
	{
		x = 0;
		while (all->map.tab[y][x])
		{
			if (all->map.tab[y][x] == '2')
			{
				all->sprite[i].x = (x + 0.5) * all->map.pix;
				all->sprite[i].y = (y + 0.5) * all->map.pix;
				i++;
			}
			x++;
		}
		y++;
	}
}

static void		parse_line(char *str, int y, t_all *all)
{
	int			x;

	x = 0;
	if (!(ft_strchr(str, '1')))
		exit_cub("Error\nEmpty string after map", all);
	while (str[x] != '\0')
	{
		if (str[x] == 'N' || str[x] == 'S' || str[x] == 'W' || str[x] == 'E')
		{
			all->plr.pos = 1;
			init_player(str[x], x, y, all);
		}
		else if (str[x] == '2')
			all->map.sprites++;
		else if (str[x] != '0' && str[x] != '1' && str[x] != ' ')
			exit_cub("Error\nInvalid symbols in the map", all);
		x++;
	}
}

void			parse_map(t_all *all, t_list *params)
{
	size_t		i;
	size_t		m;

	i = 0;
	m = 0;
	while (params && ft_atoi(params->content) == 0)
		params = params->next;
	if (!(all->map.tab = malloc_mm(sizeof(char *) * (ft_lstsize(params) + 1))))
		exit_cub("Error\nMalloc for map failed", all);
	while (params)
	{
		parse_line(params->content, i, all);
		all->map.tab[i++] = params->content;
		m = m < ft_strlen(params->content) ? ft_strlen(params->content) : m;
		params = params->next;
	}
	all->map.tab[i] = NULL;
	ft_align(all, m);
	check_parser(all);
	m = m < i ? i : m;
	all->map.pix = all->frame.h > all->frame.w \
				? all->frame.h / m : all->frame.w / m;
	all->plr.x *= all->map.pix;
	all->plr.y *= all->map.pix;
	draw_sprite(all);
}
