/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnoor <fnoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:10:16 by fnoor             #+#    #+#             */
/*   Updated: 2025/08/18 14:47:27 by fnoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp = src;

	dst_tmp = dst;
	if (!dst && !src)
	{
		return (NULL);
	}
	if (dst_tmp < src_tmp)
	{
		while (n--)
			*dst_tmp++ = *src_tmp++;
	}
	else if (dst_tmp > src_tmp)
	{
		dst_tmp += n;
		src_tmp += n;
		while (n--)
			*--dst_tmp = *--src_tmp;
	}
	return (dst);
}
