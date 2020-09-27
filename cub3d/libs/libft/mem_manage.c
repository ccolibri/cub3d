/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:36:55 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/27 20:37:55 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_mm(void *ptr)
{
	mem_manager(ptr, REMOVE);
}

void		*malloc_mm(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	mem_manager(ptr, ADD);
	return (ptr);
}

void		*calloc_mm(size_t nmem, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(nmem, size);
	mem_manager(ptr, ADD);
	return (ptr);
}
