/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:48:13 by ccaptain          #+#    #+#             */
/*   Updated: 2020/05/04 16:01:54 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t length)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*substr;

	str = (char *)s1;
	substr = (char *)s2;
	if (!*s2)
		return (str);
	i = 0;
	while (str[i] && i < length)
	{
		j = 0;
		while (str[i + j] == substr[j] && str[i + j] && \
		substr[j] && i + j <= length)
		{
			j++;
			if (substr[j] == '\0')
				return (str + i);
		}
		i++;
	}
	return (NULL);
}