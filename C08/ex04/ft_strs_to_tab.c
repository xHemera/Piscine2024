#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>

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

struct	s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int	i;
	t_stock_str *tab;

	i = 0;
	tab = malloc((ac + 1) * sizeof(struct	s_stock_str));
	if (!tab)
		return (NULL);
	while (i < ac)
	{

		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = NULL;
	if (!tab[i].copy)
		free(tab[i].copy);
	free(tab);
	return(tab);
}




void	ft_putstr(char *str)
{
	int	length;

	length = ft_strlen(str);
	write(1, str, length);
}

void	ft_putnbr(int nb)
{
	char	c;

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
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
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



int	main(void)
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
}
