/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:27:54 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/25 15:25:33 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		validate_line(char *line, t_all *all)
{
	while (ft_isblank(*line) && *line)
		line++;
	if (*line != '1' && *line != '\0')
		exit_cub("Error : Invalid configuration instruction", all);
}

void		validate_clr(char *line, char clr, t_all *all)
{
	int		i;

	i = 1;
	if (clr == 'F' && all->map.f_clr != -1)
		exit_cub("Error : Multiple floor color instruction", all);
	if (clr == 'C' && all->map.c_clr != -1)
		exit_cub("Error : Multiple ceiling color instruction", all);
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ',')
			exit_cub("Error : Invalid color configuration", all);
		i++;
	}
}

int			validate_args(int argc, char **argv, t_all *all)
{
	int		bmp;
	int		len;

	bmp = FALSE;
	all->frame.mlx = NULL;
	if (argc == 1)
		exit_cub("Error : Invalid first argument", all);
	if (argc >= 2)
	{
		len = ft_strlen(argv[1]) - 4;
		if (len <= 0 || ft_memcmp(argv[1] + len, ".cub\0", 5) != 0)
			exit_cub("Error : Invalid first argument", all);
	}
	if (argc == 3)
	{
		if (ft_memcmp(argv[2], "--save\0", 7) == 0)
			bmp = TRUE;
		else
			exit_cub("Error : Invalid second argument", all);
	}
	if (argc > 3)
		exit_cub("Error : Invalid number of arguments", all);
	return (bmp);
}

void		validate_params(t_all *all)
{
	if (all->frame.w == -1 || all->frame.h == -1)
		exit_cub("Error : No resolution", all);
	if (all->text.s.img == NULL)
		exit_cub("Error : No south texture", all);
	if (all->text.n.img == NULL)
		exit_cub("Error : No north texture", all);
	if (all->text.e.img == NULL)
		exit_cub("Error : No east texture", all);
	if (all->text.w.img == NULL)
		exit_cub("Error : No west texture", all);
	if (all->text.s.img == NULL)
		exit_cub("Error : No sprite texture", all);
	if (all->map.c_clr == -1)
		exit_cub("Error : No ceiling color", all);
	if (all->map.f_clr == -1)
		exit_cub("Error : No floor color", all);
}

void		validate_map(t_all *all, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (j == 0 || j == all->map.x - 1)
					exit_cub("Error : Invalid map", all);
				if (i == 0 || i == all->map.y - 1)
					exit_cub("Error : Invalid map", all);
				if (j + 1 < all->map.x && map[i][j + 1] == ' ')
					exit_cub("Error : Invalid map", all);
				if (map[i][j - 1] == ' ' || map[i - 1][j] == ' ')
					exit_cub("Error : Invalid map", all);
				if (i + 1 < all->map.y && map[i + 1][j] == ' ')
					exit_cub("Error : Invalid map", all);
			}
		}
	}
}
