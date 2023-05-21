/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myurduse <myurduse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:18:41 by myurduse          #+#    #+#             */
/*   Updated: 2023/05/21 19:18:43 by myurduse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

int	count1(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	x;

	x = n;
	len = count1(x);
	s = (char *)malloc(len + 1);
	if (!s)
		return (0);
	s[len] = '\0';
	if (x < 0)
	{
		s[0] = '-';
		x = -x;
	}
	while (x != 0)
	{
		s[--len] = x % 10 + 48;
		x = x / 10;
	}
	return (s);
}
