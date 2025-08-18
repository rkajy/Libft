/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnoor <fnoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:28:30 by fnoor             #+#    #+#             */
/*   Updated: 2025/08/18 18:01:30 by fnoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char sep)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == sep)
			s++;
		if (*s && *s != sep)
		{
			count++;
			while (*s && *s != sep)
				s++;
		}
	}
	return (count);
}

static char	*dup_range(char const *start, char const *end)
{
	size_t	len;
	char	*out;

	len = (size_t)(end - start);
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	ft_memcpy(out, start, len);
	out[len] = '\0';
	return (out);
}

static void	free_all(char **arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
}

static int	push_word(char **out, size_t *idx, char const *beg, char const *end)
{
	out[*idx] = dup_range(beg, end);
	if (!out[*idx])
		return (0);
	(*idx)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**out;
	size_t		i;
	char const	*beg;

	if (!s)
		return (NULL);
	out = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		beg = s;
		while (*s && *s != c)
			s++;
		if (s > beg && !push_word(out, &i, beg, s))
		{
			free_all(out, i);
			return (NULL);
		}
	}
	out[i] = NULL;
	return (out);
}
