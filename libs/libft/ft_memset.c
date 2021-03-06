/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:05:09 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/27 20:32:56 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)dest;
	while (n--)
		*str++ = (unsigned char)c;
	return (dest);
}
