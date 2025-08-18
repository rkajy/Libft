/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnoor <fnoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:50:36 by fnoor             #+#    #+#             */
/*   Updated: 2025/08/18 17:50:41 by fnoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*out;

	nb = n;
	len = int_len(n);
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	out[len] = '\0';
	if (nb < 0)
	{
		out[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		out[0] = '0';
	while (nb)
	{
		out[--len] = (char)('0' + (nb % 10));
		nb /= 10;
	}
	return (out);
}
