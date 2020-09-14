/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:18:26 by ccaptain          #+#    #+#             */
/*   Updated: 2020/05/11 15:49:18 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	front_search(char const *str, char const *set)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (str[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static size_t	back_search(char const *str, char const *set)
{
	size_t		i;
	size_t		j;

	i = ft_strlen(str) - 1;
	j = 0;
	while (set[j])
	{
		if (str[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char			*ft_strtrim(char const *str, char const *set)
{
	size_t		i;
	size_t		front;
	size_t		back;
	char		*newstr;

	if (str == NULL)
		return (NULL);
	front = front_search(str, set);
	if (front == ft_strlen(str))
		return ((char *)malloc((sizeof(char) * 1)));
	back = back_search(str, set);
	if (!(newstr = (char *)malloc((back - front + 2) * sizeof(char))))
		return (NULL);
	i = 0;
	while (front <= back)
	{
		newstr[i] = str[front];
		i++;
		front++;
	}
	newstr[i] = '\0';
	return (newstr);
}
