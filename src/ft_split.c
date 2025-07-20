/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:10:22 by radandri          #+#    #+#             */
/*   Updated: 2025/07/20 14:52:23 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

 static int	word_count(const char *s, char c)
{
    int	i;
	int	k;
	int	word;
	
	i = 0;
	k = 0;
	word = 0;
	while (s[i])
	{
		//printf("before i = %d, k = %d, word = %d, s[i=%d] = %c\n", i, k, word, i, s[i]);
		if (s[i] != c && !k)
		{
			k = 1;
			word++;
		}
		else if (s[i] == c)
		{
			k = 0;
		}		
		i++;
	}
	return word;
}

static void	fill_words(char const *s, char c, char **words, int m)
{
    int	i;
	int	k;
	int	first;
	size_t	len;
	
	i = 0;
	k = 0;
	first = 0;
	while (s[i])
	{
		first = i;
		if (s[i] != c && !k)
		{
			k = 1;

		}
		else if (s[i] == c)
		{
			k = 0;
			len = i;
			words[m]= ft_substr(s, first, len-first);
		}		
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int	words_numbers;
	int	i;

	words_numbers = word_count(s, c);
	result = malloc(sizeof(char*) * (words_numbers+1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words_numbers)
	{
		result[i] = malloc(sizeof(char*) * 15+1);
		if (!result[i])
			return (NULL);
		//strcpy(&result[i][0], "q\0");
		fill_words(s,c,result,i);
		i++;
	}
	
	return (result);
}
