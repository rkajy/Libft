/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnoor <fnoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:51:50 by fnoor             #+#    #+#             */
/*   Updated: 2025/08/18 17:17:09 by fnoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_tmp;
	char const	*src_tmp;

	if (!dst && !src)
	{
		return (NULL);
	}
	dst_tmp = dst;
	src_tmp = src;
	while (n--)
	{
		*dst_tmp++ = *src_tmp++;
	}
	return (dst);
}
