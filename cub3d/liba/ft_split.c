/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 12:38:32 by ccaptain          #+#    #+#             */
/*   Updated: 2020/05/13 00:45:35 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		cnt_words(char const *str, char c)
{
	char			start;
	size_t			n;

	start = 1;
	n = 0;
	while (*str)
	{
		if (*(str++) != c)
		{
			if (start)
				n++;
			start = 0;
		}
		else
			start = 1;
	}
	return (n);
}

static void			arr_free(char **arr)
{
	int				i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static size_t		str_len(char const *str, char c)
{
	size_t			i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static char			**str_cpy(char **arr, char const *str, char c)
{
	int				i;
	int				j;
	int				len;
	int				count;

	i = 0;
	count = cnt_words(str, c);
	while (i < count)
	{
		while (*str && *str == c)
			str++;
		len = str_len(str, c);
		if (!(arr[i] = (char *)malloc((len + 1) * sizeof(char))))
		{
			arr_free(arr);
			return (NULL);
		}
		j = 0;
		while (j < len)
			arr[i][j++] = *str++;
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char				**ft_split(char const *s, char c)
{
	char			**arr;

	if (!s)
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(char *) * (cnt_words(s, c) + 1))))
		return (NULL);
	return (str_cpy(arr, s, c));
}
