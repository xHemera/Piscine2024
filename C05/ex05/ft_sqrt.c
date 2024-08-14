/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:14:11 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/14 14:04:48 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i < nb && i < 46341)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}
/*int	main(void)
{
	printf ("%d\n", ft_sqrt(0));
	printf ("%d\n", ft_sqrt(45));
	printf ("%d\n", ft_sqrt(3));
	return (0);
}*/
