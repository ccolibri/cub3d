/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:07:17 by ccaptain          #+#    #+#             */
/*   Updated: 2020/05/11 21:49:20 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int n)
{
	int		i;
	char	*a;

	i = 0;
	while (str[i] != '\0' && str[i] != n)
		i++;
	if (str[i] == n)
	{
		a = (char *)&str[i];
		return (a);
	}
	if (str[i] == '\0' && !n)
	{
		a = (char *)&str[i];
		return (a);
	}
	return (NULL);
}
