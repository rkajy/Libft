/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnoor <fnoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:53:49 by fnoor             #+#    #+#             */
/*   Updated: 2025/08/18 16:28:10 by fnoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t buffer_size)
{
	const char	*src_ptr;
	char		*dst_ptr;
	size_t		dst_len;
	size_t		src_len;
	size_t		remaining_space;

	src_ptr = src;
	dst_ptr = dst;
	src_len = ft_strlen(src);
	remaining_space = buffer_size;
	while (remaining_space && *dst_ptr)
	{
		dst_ptr++;
		remaining_space--;
	}
	dst_len = dst_ptr - dst;
	if (remaining_space == 0)
		return (dst_len + src_len);
	while (*src_ptr && remaining_space > 1)
	{
		*dst_ptr++ = *src_ptr++;
		remaining_space--;
	}
	*dst_ptr = '\0';
	return (dst_len + src_len);
}
