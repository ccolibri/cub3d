/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:07:25 by ccaptain          #+#    #+#             */
/*   Updated: 2020/05/13 14:46:31 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*ncont;

	if (!lst || !f)
		return (NULL);
	if (!(ncont = ft_lstnew(f(lst->content))))
		return (NULL);
	nlst = ncont;
	lst = lst->next;
	while (lst)
	{
		if (!(ncont = ft_lstnew(f(lst->content))))
			ft_lstclear(&nlst, del);
		lst = lst->next;
		ft_lstadd_back(&nlst, ncont);
	}
	return (nlst);
}
