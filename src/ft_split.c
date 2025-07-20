/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:10:22 by radandri          #+#    #+#             */
/*   Updated: 2025/07/20 23:43:10 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c);
static char	**fill_words(char const *s, char c, char **words);

static int	word_count(const char *s, char c)
{
	int	i;
	int	in_word;
	int	word;

	i = 0;
	in_word = 0;
	word = 0;
	while (s[i])
	{
			if (s[i] != c && !in_word)
			{
				in_word = 1;
				word++;
			}
			else if (s[i] == c)
			{
				in_word = 0;
			}
			i++;
	}
	return (word);
}
#include <stdio.h>

static char	**fill_words(char const *s, char delimiter, char **words)
{
	int		i;
	int		in_word;
	int		start;
	int	idx;

	i = 0;
	in_word = 0;
	start = 0;
	idx = 0;
	while (s[i])
	{
		if (s[i] != delimiter && in_word == 0)
		{
			start = i;
			in_word = 1;
		}
		else if (s[i] == delimiter && in_word == 1)
		{
			in_word = 0;
			words[idx++] = ft_substr(s, start, i - start);
		}
		i++;
	}
	if (in_word == 1)
		words[idx++] = ft_substr(s, start, i - start);
	words[idx] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;

	if (!s)
		return (NULL);
	
	count = word_count(s, c);
	result = malloc(sizeof(char *) * count + 1);
	if (!result)
		return (NULL);
	if (count == 0) // <- ici le cas du test "      "
	{
		result[0] = NULL;
		return (result);
	}
	return (fill_words(s, c, result));
}

// int	main(void)
// {
// 	char	**res;

// 	res = ft_split("hello world test", ' ');
// 	for (int i = 0; res[i]; i++)
// 		printf("[%s]\n", res[i]);
// 	// Pense à free ici si nécessaire
// 	return (0);
// }
