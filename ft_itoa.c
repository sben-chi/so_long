/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-chi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:45:49 by sben-chi          #+#    #+#             */
/*   Updated: 2022/04/26 14:43:21 by sben-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	len_nbr(int n)
{
	int	nbn;
	int	len;

	len = 0;
	nbn = n;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (nbn)
	{
		nbn /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*t;
	unsigned int	a;

	len = len_nbr(n);
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (!t)
		return (NULL);
	t[len] = '\0';
	if (n == 0)
		t[--len] = n + 48;
	else if (n < 0)
	{
		n *= -1;
		t[0] = '-';
	}
	a = n;
	while (len > 0 && a > 0)
	{
		t[--len] = a % 10 + 48;
		a /= 10;
	}
	return (t);
}
