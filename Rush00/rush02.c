/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:10:31 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/10 11:51:14 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char *c)
{
	write(1, &c, 1);
}

void	print_vert(int	x)
{
	ft_putchar("A");
	if (x >= 3)
	{
		x -= 2;
		while (x != 0)
		{
			ft_putchar("B");
			x--;
		}
		ft_putchar("A");
	}
	if (x == 2)
		ft_putchar("A");
}

int	main(void)
{
	int a = 44;

	print_vert(a);
	return 0;
}
