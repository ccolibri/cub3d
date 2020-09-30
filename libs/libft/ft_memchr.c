/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:47:50 by ccaptain          #+#    #+#             */
/*   Updated: 2020/05/11 21:56:31 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*arr;
	unsigned char	sym;

	arr = (unsigned char *)s;
	sym = (unsigned char)c;
	while (n--)
	{
		if (*arr == sym)
			return (arr);
		arr++;
	}
	return (NULL);
}
