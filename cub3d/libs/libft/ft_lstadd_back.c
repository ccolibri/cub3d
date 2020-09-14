/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:09:45 by ccaptain          #+#    #+#             */
/*   Updated: 2020/05/11 19:33:38 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!lst)
		return ;
	list = *lst;
	if (!list)
		*lst = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
