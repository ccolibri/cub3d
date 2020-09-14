/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 13:48:27 by ccaptain          #+#    #+#             */
/*   Updated: 2020/08/11 17:58:35 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char *s1, char const *s2)
{
	char	*arr;
	size_t	length;
	int		i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	if (!(arr = malloc((sizeof(char) * (length + 1)))))
		return (NULL);
	while (s1 && *s1 != '\0')
		arr[i++] = *s1++;
	free(s1 - i);
	while (s2 && *s2 != '\0')
		arr[i++] = *s2++;
	arr[i] = '\0';
	return (arr);

	}
