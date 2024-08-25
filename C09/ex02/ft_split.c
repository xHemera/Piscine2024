/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:01:00 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/25 15:02:13 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			count++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	return (count);
}

char	*alloc_word(char *str, char *charset)
{
	int		len;
	char	*word;

	len = 0;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	len = 0;
	while (str[len] && !is_sep(str[len], charset))
	{
		word[len] = str[len];
		len++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		words;

	words = word_count(str, charset);
	i = 0;
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			split[i] = alloc_word(str, charset);
			if (!split[i++])
				return (NULL);
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	split[i] = 0;
	return (split);
}
/*int	main(void)
{
	char	**result;
	char	str[] = "Hello,,world! I Love,,Mimikyu!";
	char	charset[] = ", !";
	int		i = 0;

	result = ft_split(str, charset);

	if (!result)
	{
		printf("Memory allocation failed\n");
		return (1);
	}

	while (result[i])
	{
		printf("Word %d: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}

	free(result);

	return (0);
}*/
