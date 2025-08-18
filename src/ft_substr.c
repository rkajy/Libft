/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnoor <fnoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:27:51 by fnoor             #+#    #+#             */
/*   Updated: 2025/08/18 17:31:14 by fnoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	maxcopy;
	char	*out;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		out = (char *)malloc(1);
		if (!out)
			return (NULL);
		out[0] = '\0';
		return (out);
	}
	maxcopy = slen - start;
	if (len < maxcopy)
		maxcopy = len;
	out = (char *)malloc(maxcopy + 1);
	if (!out)
		return (NULL);
	ft_strlcpy(out, s + start, maxcopy + 1);
	return (out);
}
