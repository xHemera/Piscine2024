/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:29:23 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/26 14:30:37 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
	}
}

void	ft_putnbr(int nb)
{
	int	mod;
	int	div;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		mod = nb % 10;
		div = nb / 10;
		ft_putnbr(div);
	}
	if (nb > 9)
		ft_putchar(mod + '0');
	else
		ft_putchar(nb + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		i++;
	}
}

/*int	main(void)
{
	char				*strs[] = {"Hello", "World", "42", "hehe"};
	int					size = 4;
	struct s_stock_str	*tab;
	tab = ft_strs_to_tab(size, strs);
	ft_show_tab(tab);
	for (int i = 0; i < size; i++)
	{
		free(tab[i].copy);
	}
	free(tab);
	return 0;
}*/
