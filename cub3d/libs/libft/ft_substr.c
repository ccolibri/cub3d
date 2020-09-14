/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:10:54 by ccaptain          #+#    #+#             */
/*   Updated: 2020/05/13 14:25:55 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*arr;
	size_t			i;
	size_t			size;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s) - start;
	if (size < len)
		len = size;
	if (!(arr = (char *)malloc((sizeof(char) * (len + 1)))))
		return (NULL);
	while (i < len && s[start])
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
