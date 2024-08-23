/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:14:23 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/22 18:14:25 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"

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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = malloc((ac + 1) * sizeof(t_stock_str));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = '\0';
	return (tab);
}

/*int	main(void)
{
	char				*strs[] = {"Hello", "World", "42", "hehe"};
	int					size = 4;
	struct s_stock_str	*tab;
	int					i = 0;
 	tab = ft_strs_to_tab(size, strs);
	while (tab[i].str != 0)
	{
		printf("Taille: %d\n", tab[i].size);
		printf("String: %s\n", tab[i].str);
		printf("Copy: %s\n", tab[i].copy);
		printf("\n");
		i++;
	}
	for (int i = 0; i < size; i++)
 	{
 		free(tab[i].copy);
 	}
 	free(tab);
 	return 0;
}*/
