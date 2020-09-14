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
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (ft_strlen(s2) > 0)
	{
		while (s1[i] != '\0')
		{
			if (s1[i] == s2[j] && i < length)
			{
				if ((ft_strncmp(&s1[i], &s2[j], ft_strlen(s2)) == 0))
				{
					if ((i + ft_strlen(s2)) > length)
						return (NULL);
					return ((char *)&s1[i]);
				}
			}
			i++;
		}
		return (NULL);
	}
	return ((char *)s1);
}
