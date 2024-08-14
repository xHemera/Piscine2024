/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:09:32 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/14 15:01:48 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
/*int	main(void)
{
	printf("13 : %d\n", ft_is_prime(13));
	printf("6 : %d\n", ft_is_prime(6));
	printf("7 : %d\n", ft_is_prime(7));
	printf("4 : %d\n", ft_is_prime(4));
	printf("1 : %d", ft_is_prime(1));
	return (1);
}*/
