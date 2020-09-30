/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:13:34 by ccaptain          #+#    #+#             */
/*   Updated: 2020/05/13 14:34:20 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *list;
	t_list *tmp;

	if (!lst)
		return ;
	if (!del)
		return ;
	list = *lst;
	while (list)
	{
		del(list->content);
		tmp = list;
		list = list->next;
		free(tmp);
	}
	*lst = NULL;
}
