/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 20:51:52 by ccaptain          #+#    #+#             */
/*   Updated: 2020/05/11 15:25:05 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_numb(int n)
{
	int	cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	if (n < 0)
		cnt++;
	while (n != 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		cnt;
	long	nn;

	nn = n;
	cnt = cnt_numb(n);
	str = (char *)malloc((cnt + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[cnt] = '\0';
	if (nn < 0)
	{
		str[0] = '-';
		nn = -nn;
	}
	else if (nn == 0)
		str[0] = '0';
	while (nn > 0)
	{
		str[--cnt] = '0' + nn % 10;
		nn /= 10;
	}
	return (str);
}
