/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:08:09 by ccaptain          #+#    #+#             */
/*   Updated: 2020/08/11 18:04:51 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					memory_free(char **s, char **s2)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
	if (*s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (-1);
}

char				*chk_ost(char *ost, char **line)
{
	char			*nline;

	nline = NULL;
	if (ost)
	{
		if ((nline = ft_strchr(ost, '\n')))
		{
			*nline = '\0';
			*line = ft_strdup(ost);
			nline++;
			ft_strcpy(ost, nline);
		}
		else
			*line = ft_strdup(ost);
	}
	else
		*line = ft_strdup("");
	return (nline);
}

void				do_if(char **buf, char **nline, char **ost)
{
	if ((*nline = ft_strchr(*buf, '\n')))
	{
		**nline = '\0';
		(*nline)++;
		free(*ost);
		*ost = ft_strdup(*nline);
	}
}

int					get_next_line(int fd, char **line)
{
	static char		*ost;
	char			*buf;
	char			*nline;
	int				n;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	n = 1;
	nline = chk_ost(ost, line);
	if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (memory_free(&buf, line));
	while (!nline && (n = read(fd, buf, BUFFER_SIZE)))
	{
		if (n < 0)
		{
			return (memory_free(&ost, &buf));
		}
		buf[n] = '\0';
		do_if(&buf, &nline, &ost);
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
	if (n == 0 && ost != 0)
		memory_free(&ost, &ost);
	return (n || nline) ? 1 : 0;
}
