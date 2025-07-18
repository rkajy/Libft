/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:22:23 by radandri          #+#    #+#             */
/*   Updated: 2025/07/18 02:19:54 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_int_len(int n)
{
	int isneg;
	int len;

	isneg = 0;
	len = 0;
	if (n < 0)
	{
		isneg = 1;
		n = n * -1;
		len++;
	}
	if (n == 0 )
		len++;
	while (n > 0)
	{
		n = n/10;
		len++;
	}
	return len;
}
#include <stdio.h>
char	*ft_itoa(int n)
{
	int n_len;
	char *res;
	int	isneg;

	if (n == -2147483648)
		return "-2147483648";
	
	n_len = ft_int_len(n);
	isneg = 0;
	if (n < 0)
	{		
		isneg = 1;
		n = n * -1;
	}
	res = malloc((n_len + 1)*sizeof(char));
	if (!res)
		return (NULL);
	res[n_len] = '\0';
	while (n_len != 0)
	{
		res[n_len-1] = (n % 10) + '0';
		n = n / 10;
		n_len--;
	}
	if (isneg)
		res[n_len] = '-';
	return res;
}
