/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:09:39 by radandri          #+#    #+#             */
/*   Updated: 2025/07/12 16:34:10 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	int				i;

	temp_dest = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	i = 0;
	if (temp_dest == NULL && temp_src == NULL)
	{
		return (dst);
	}
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dst);
}
