/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:44:46 by ccaptain          #+#    #+#             */
/*   Updated: 2020/08/11 18:56:56 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		make_texture(char *str, t_all *all, char type)
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

static void		make_color(char *str, t_all *all, char color)
{
	char	**clr;
	int		rgb[3];
	int		i;

	while (*str && ft_isspace(*str))
		str++;
	str++;
	validate_clr(str, color, all);
	if (!(clr = ft_split(str, ',')))
		ft_errors(-11);
	i = 0;
	while (clr && clr[i] != NULL)
	{
		if ((rgb[i] = ft_atoi(clr[i])) > 255 || clr[i] < 0 || i > 2)
			ft_errors(-6);
		i++;
	}
	if (color == 'C')
		all->map.c_clr = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	else if (color == 'F')
		all->map.f_clr = create_trgb(0, rgb[0], rgb[1], rgb[2]);
}

static void		make_res(char *str, t_all *all)
{
	int 	width = 0;
	int		height = 0;

	mlx_get_screen_size(all->frame.mlx, &width, &height);
	if (all->frame.w != -1 || all->frame.h != -1)
		ft_errors(-3);
	str = ft_strchr(str, 'R');
	str++;
	all->frame.w = ft_atoi(str);
	while (*str && ft_isspace(*str))
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	all->frame.h = ft_atoi(str);
	if (all->frame.w <= 0 || all->frame.h <= 0)
		ft_errors(-4);
	all->frame.w = all->frame.w > width ? width : all->frame.w;
	all->frame.h = all->frame.h > height ? height : all->frame.h;
}

static void		parse_params(t_list	*list, t_all *all)
{
	size_t		len;
	char *op;

	while (list)
	{
		len = ft_strlen(list->content);
		if (ft_strnstr(list->content, "R ", len))
			make_res(list->content, all);
		else if ((op = ft_strnstr(list->content, "NO ", len)))
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

void	parser(char *map, t_all *all)
{
	int	fd;
	char	*line;
	t_list	*params;
	t_list	*ptr;
	int		gnl;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_errors(-1);
	params = NULL;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (!(ptr = ft_lstnew(line)))
			ft_errors(-11);
		ft_lstadd_back(&params, ptr);
	}
	if (gnl == -1)
		ft_errors(-2);
	if (!(ptr = ft_lstnew(line)))
		ft_errors(-11);
	ft_lstadd_back(&params, ptr);
	close(fd);
	parse_params(params, all);
	validate_params(all);
	parse_map(all, params);
}
