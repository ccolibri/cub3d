/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:15:45 by ccaptain          #+#    #+#             */
/*   Updated: 2020/05/12 20:20:51 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*dest;

	if (!(dest = (char *)malloc_mm((ft_strlen(str) + 1) * sizeof(char))))
		return (NULL);
	dest = ft_strcpy(dest, str);
	return (dest);
}
