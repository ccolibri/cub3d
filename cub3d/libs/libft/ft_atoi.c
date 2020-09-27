/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 23:03:59 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/27 20:29:59 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(char const *str)
{
	int				n;
	unsigned long	r;

	n = 1;
	r = 0;
	while (*str == '\t' || *str == '\v' ||
			*str == '\f' || *str == '\n' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		if ((r * 10 + (*str - '0')) < r)
			return ((n > 0) ? -1 : 0);
		if ((r) > 8000)
			return ((int)(r * n));
		r = r * 10 + (*str - '0');
		str++;
	}
	return ((int)(r * n));
}
