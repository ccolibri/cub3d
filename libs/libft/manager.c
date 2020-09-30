/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:38:20 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/27 20:38:47 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		mm_lstclear(t_list **lst)
{
	t_list *ptr;
	t_list *tmp;

	if (lst && *lst)
	{
		ptr = *lst;
		while (ptr)
		{
			tmp = ptr;
			ptr = ptr->next;
			free(tmp->content);
			free(tmp);
		}
		*lst = NULL;
	}
}

static t_list	*mm_lstnew(void *content)
{
	t_list *elem;

	if (!(elem = malloc(sizeof(t_list))))
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

static void		mm_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL)
	{
		del(lst->content);
		free(lst);
	}
}

static void		mm_lstremove(t_list **root, void *data)
{
	t_list	*node;
	t_list	*tmp;
	int		i;

	while (data == (*root)->content)
	{
		tmp = (*root)->next;
		mm_lstdelone(*root, free);
		(*root) = tmp;
	}
	node = *root;
	tmp = *root;
	i = 0;
	while (node != NULL)
	{
		if (data == node->content)
		{
			tmp->next = node->next;
			mm_lstdelone(node, free);
			node = tmp;
			i = 0;
		}
		tmp = i++ > 0 ? tmp->next : tmp;
		node = node != NULL ? node->next : node;
	}
}

void			mem_manager(void *ptr, int action)
{
	static t_list *collector = NULL;

	if (ptr == NULL)
		mm_lstclear(&collector);
	else if (action == ADD)
		ft_lstadd_front(&collector, mm_lstnew(ptr));
	else if (action == REMOVE)
		mm_lstremove(&collector, ptr);
}
