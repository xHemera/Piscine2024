/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:14:18 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/18 15:14:21 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)(malloc(sizeof(char) * ft_strlen(src)));
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	if (result != NULL)
	{
		result[i] = '\0';
		return (result);
	}
	else
		return (0);
}

/*int	main()
{
	printf("%s", ft_strdup("Hello"));
	printf("%s", strdup("Hello"));
	return 0;
}*/
