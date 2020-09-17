/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 00:15:24 by ccaptain          #+#    #+#             */
/*   Updated: 2020/05/11 15:20:39 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*arr;

	if (num != 0 && size != 0 && size * num / num != size)
		return (NULL);
	if (!(arr = (void *)malloc_mm(num * size)))
		return(NULL);
	ft_bzero(arr, num * size);
	return (arr);
}
