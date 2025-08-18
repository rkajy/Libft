/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnoor <fnoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:57:44 by fnoor             #+#    #+#             */
/*   Updated: 2025/08/18 16:17:29 by fnoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		len;
	char		*dst_tmp;
	const char	*src_tmp;

	src_tmp = src;
	len = ft_strlen(src);
	if (dstsize)
	{
		dst_tmp = dst;
		while (--dstsize && *src_tmp)
			*dst_tmp++ = *src_tmp++;
		*dst_tmp = '\0';
	}
	return (len);
}
