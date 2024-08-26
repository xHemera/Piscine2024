/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:33:07 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/26 14:34:06 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
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
	char	*copy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	copy = (char *)malloc(sizeof(src) * i);
	i = 0;
	if (copy == NULL)
		return (0);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int argc, char **argv)
{
	t_stock_str	*tab;
	int			i;

	i = 0;
	tab = malloc(sizeof(t_stock_str) * (argc + 1));
	if (!tab)
		return (NULL);
	while (i < argc)
	{
		tab[i].size = ft_strlen(argv[i]);
		tab[i].str = argv[i];
		tab[i].copy = ft_strdup(argv[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}

/*int	main(int argc, char **argv)
{
	t_stock_str	*tab;
	int	i;

	i = 0;
	tab = ft_strs_to_tab(argc, argv);
	while (i < argc)
	{
		printf("%s\n", tab[i].str);
		printf("%d\n", tab[i].size);
		printf("%s\n", tab[i].copy);
		i++;
	}
	return (0);
}*/
