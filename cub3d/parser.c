/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:44:46 by ccaptain          #+#    #+#             */
/*   Updated: 2020/08/11 18:26:24 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

void	make_map(t_list **map, int size)
{
	char **lst = ft_calloc(size + 1, sizeof(char *));
	t_list *tmp = *map;
	int i = -1;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = -1;
	while(lst[++i])
	{
		ft_putendl(lst[i]);
	}
}


int	main(void)
{
	char *line = NULL;
	int fd;
	t_list *map = NULL;

	fd = open("map.cub", O_RDONLY);
	while(get_next_line(fd, &line))
	{
		ft_lstadd_back(&map, ft_lstnew(line));
	}
	ft_lstadd_back(&map, ft_lstnew(line));
	make_map(&map, ft_lstsize(map));

}
