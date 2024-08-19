/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:38:44 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/18 23:38:54 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_erreur(void)
{
	write(1, "Erreur", 6);
}

void	ft_convert(char *str, char g_s[4][5])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			g_s[i][j] = str[i * 4 + j];
			j++;
		}
		g_s[i][4] = '\0';
		i++;
	}
}

int	ft_check(char g_s[4][5])
{
	int	i;
	int	j;
	int	a;

	a = 0;
	while (a < 4)
	{
		i = 0;
		while (i < 3)
		{
			j = i + 1;
			while (j < 4)
			{
				if (g_s[i][a] == g_s[j][a])
					return (0);
				j++;
			}
			i++;
		}
		a++;
	}
	return (1);
}

int	ft_check_line(int i, char *str, int ligne, char g_s[4][5])
{
	int	j;
	int	look;

	j = 0;
	look = 1;
	while (j < 3)
	{
		if (g_s[i][j] - '0' < g_s[i][j + 1] - '0')
			look++;
		if (g_s[i][j] - '0' == 4)
			break ;
		j++;
	}
	if (look != str[ligne] - '0')
		return (0);
	return (1);
}

int	ft_check_column(int i, char *str, int ligne, char g_s[4][5])
{
	int	j;
	int	look;

	j = 3;
	look = 1;
	while (j > 0)
	{
		if (g_s[j][i] - '0' < g_s[j - 1][i] - '0')
			look++;
		if (g_s[j][i] - '0' == 4)
			break ;
		j--;
	}
	if (look != str[ligne] - '0')
		return (0);
	return (1);
}

int	ft_respect(char *str, char g_s[4][5])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!ft_check_line(i, str, 16 + i * 2, g_s) ||
			!ft_check_column(i, str, i * 2, g_s) ||
			!ft_check_line(i, str, 24 + i * 2, g_s) ||
			!ft_check_column(i, str, 8 + i * 2, g_s))
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_result(char result[16])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 4 == 0 && i != 0)
			write(1, "\n", 1);
		write(1, &result[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_load(char *str)
{
	int		i[4];
	char	result[16];
	char	g_s[4][5];
	char	*look = "1234124313241342142314322134214323142341241324313124314232143241341234214123423143124321";

	i[0] = 0;
	while (i[0] < 23)
	{
		ft_convert(look + i[0] * 4, g_s);
		i[1] = 0;
		while (i[1] < 23)
		{
			ft_convert(look + i[1] * 4, g_s);
			i[2] = 0;
			while (i[2] < 23)
			{
				ft_convert(look + i[2] * 4, g_s);
				i[3] = 0;
				while (i[3] < 23)
				{
					ft_convert(look + i[3] * 4, g_s);
					if (ft_respect(str, g_s) && ft_check(g_s))
					{
						ft_print_result(look + i[0] * 4);
						return ;
					}
					i[3]++;
				}
				i[2]++;
			}
			i[1]++;
		}
		i[0]++;
	}
	ft_erreur();
}

void	ft_error(char *str)
{
	int	count;

	count = 0;
	while (count <= 22)
	{
		if ((str[count] - '0') + (str[count + 8] - '0') > 5)
		{
			ft_erreur();
			return ;
		}
		count += 2;
	}
	ft_load(str);
}

int	ft_size(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i % 2 == 1 && str[i] != ' ') ||
			(i % 2 == 0 && (str[i] < '1' || str[i] > '4')))
			return (0);
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	i1;

	if (argc != 2)
	{
		ft_erreur();
		return (0);
	}
	i1 = ft_size(argv[1]);
	if (i1 != 31)
	{
		ft_erreur();
		return (0);
	}
	ft_load(argv[1]);
	return (0);
}
