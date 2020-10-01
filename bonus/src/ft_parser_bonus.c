/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:44:46 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/28 19:00:08 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int		cnt_comma(char *str)
{
	int			cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == ',')
		{
			cnt++;
			str++;
		}
		else
			str++;
	}
	return (cnt);
}

static void		make_color(char *str, t_all *all, char color)
{
	char		**clr;
	int			rgb[3];
	int			i;

	while (*str && ft_isspace(*str))
		str++;
	str++;
	(cnt_comma(str) == 2) ? validate_clr(str, color, all) :
				exit_cub("Error\nInvalid color configuration", all);
	if (!(clr = ft_split(str, ',')))
		exit_cub("Error\nMalloc failed", all);
	i = 0;
	while (clr && clr[i] != NULL)
	{
		if ((rgb[i] = ft_atoi(clr[i])) > 255 || clr[i] < 0 || i > 2)
			exit_cub("Error\nInvalid color configutation", all);
		free_mm(clr[i]);
		i++;
	}
	free_mm(clr);
	if (color == 'C')
		all->map.c_clr = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	else if (color == 'F')
		all->map.f_clr = create_trgb(0, rgb[0], rgb[1], rgb[2]);
}

static void		make_res(char *str, t_all *all)
{
	int		width;
	int		height;

	mlx_get_screen_size(all->frame.mlx, &width, &height);
	if (all->frame.w != -1 || all->frame.h != -1)
		exit_cub("Error\nMultiple resolution", all);
	str = ft_strchr(str, 'R');
	str++;
	all->frame.w = ft_atoi(str);
	while (*str && ft_isspace(*str))
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	all->frame.h = ft_atoi(str);
	while (*str && ft_isspace(*str))
		str++;
	while (*str)
	{
		if (ft_isspace(*str++) || ft_isalpha(*str++))
			exit_cub("Error\nInvalid resolution string", all);
	}
	if (all->frame.w <= 0 || all->frame.h <= 0)
		exit_cub("Error\nInvalid resolution", all);
	all->frame.w = all->frame.w > width ? width : all->frame.w;
	all->frame.h = all->frame.h > height ? height : all->frame.h;
}

static void		parse_params(t_list *list, t_all *all)
{
	size_t		len;

	while (list)
	{
		len = ft_strlen(list->content);
		if (ft_strnstr(list->content, "R ", len))
			make_res(list->content, all);
		else if (ft_strnstr(list->content, "NO ", len))
			make_texture(list->content, all, 'N');
		else if (ft_strnstr(list->content, "SO ", len))
			make_texture(list->content, all, 'S');
		else if (ft_strnstr(list->content, "WE ", len))
			make_texture(list->content, all, 'W');
		else if (ft_strnstr(list->content, "EA ", len))
			make_texture(list->content, all, 'E');
		else if (ft_strnstr(list->content, "S ", len))
			make_texture(list->content, all, 's');
		else if (ft_strnstr(list->content, "F ", len))
			make_color(list->content, all, 'F');
		else if (ft_strnstr(list->content, "C ", len))
			make_color(list->content, all, 'C');
		else
			validate_line(list->content, all);
		list = list->next;
	}
}

void			parser(char *map, t_all *all)
{
	int			fd;
	char		*line;
	t_list		*params;
	t_list		*ptr;
	int			gnl;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_cub("Error\nInvalid config file", all);
	params = NULL;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (!(ptr = ft_lstnew(line)))
			exit_cub("Error\nMalloc failed", all);
		ft_lstadd_back(&params, ptr);
	}
	if (gnl == -1)
		exit_cub("Error\nGNL failed", all);
	if (!(ptr = ft_lstnew(line)))
		exit_cub("Error\nMalloc failed", all);
	ft_lstadd_back(&params, ptr);
	close(fd);
	parse_params(params, all);
	validate_params(all);
	parse_map(all, params);
}
