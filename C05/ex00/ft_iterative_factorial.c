/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:06:43 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/18 15:56:20 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	nb_ret;

	if (nb < 0)
		return (0);
	nb_ret = 1;
	while (nb > 1)
		nb_ret *= nb--;
	return (nb_ret);
}

/*#include <stdio.h>
int main()
{
	printf("%i", ft_iterative_factorial(-8));
}*/
