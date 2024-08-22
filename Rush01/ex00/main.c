/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:44:17 by tle-goff          #+#    #+#             */
/*   Updated: 2024/08/18 18:49:03 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_erreur(void)
{
	write(1, "Erreur", 6);
	return ;
}

char	g_s[4][5];

void	ft_convert(char *str)
{
	g_s[0][0] = str[0];
	g_s[0][1] = str[1];
	g_s[0][2] = str[2];
	g_s[0][3] = str[3];
	g_s[0][4] = '\0';
	g_s[1][0] = str[4];
	g_s[1][1] = str[5];
	g_s[1][2] = str[6];
	g_s[1][3] = str[7];
	g_s[1][4] = '\0';
	g_s[2][0] = str[8];
	g_s[2][1] = str[9];
	g_s[2][2] = str[10];
	g_s[2][3] = str[11];
	g_s[2][4] = '\0';
	g_s[3][0] = str[12];
	g_s[3][1] = str[13];
	g_s[3][2] = str[14];
	g_s[3][3] = str[15];
	g_s[3][4] = '\0';
	return ;
}

int	ft_check(void)
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

int	ft_respect(char *str)
{
	int	i;
	int	j;
	int	look;
	int	ligne;

	i = 0;
	ligne = 16;
	while (i < 4)
	{
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
		{
			return (0);
		}
		ligne += 2;
		i++;
	}
	i = 0;
	ligne = 0;
	while (i < 4)
	{
		j = 0;
		look = 1;
		while (j < 3)
		{
			if (g_s[j][i] - '0' < g_s[j + 1][i] - '0')
				look++;
			if (g_s[j][i] - '0' == 4)
				break ;
			j++;
		}
		if (look != str[ligne] - '0')
		{
			return (0);
		}
		ligne += 2;
		i++;
	}
	i = 0;
	ligne = 24;
	while (i < 4)
	{
		j = 3;
		look = 1;
		while (j > 0)
		{
			if (g_s[i][j] - '0' < g_s[i][j - 1] - '0')
				look++;
			if (g_s[i][j] - '0' == 4)
				break ;
			j--;
		}
		if (look != str[ligne] - '0')
		{
			return (0);
		}
		ligne += 2;
		i++;
	}
	i = 0;
	ligne = 8;
	while (i < 4)
	{
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
		{
			return (0);
		}
		ligne += 2;
		i++;
	}
	return (1);
}

void	ft_load(char *str)
{
	int	i1;
	int	i2;
	int	i3;
	int	i4;
	int	i;
	char	*look = "1234124313241342142314322134214323142341241324313124314232143241341234214123423143124321";
	char	result[20];

	i1 = 0;
	while (i1 < 23)
	{
		result[0] = look[(i1 * 4)];
		result[1] = look[(i1 * 4)+1];
		result[2] = look[(i1 * 4)+2];
		result[3] = look[(i1 * 4)+3];
		i2 = 0;
		while (i2 < 23)
		{
			result[4] = look[(i2 * 4)];
			result[5] = look[(i2 * 4)+1];
			result[6] = look[(i2 * 4)+2];
			result[7] = look[(i2 * 4)+3];
			i3 = 0;
			while (i3 < 23)
			{
				result[8] = look[(i3 * 4)];
				result[9] = look[(i3 * 4)+1];
				result[10] = look[(i3 * 4)+2];
				result[11] = look[(i3 * 4)+3];
				i4 = 0;
				while (i4 < 23)
				{
					result[12] = look[(i4 * 4)];
					result[13] = look[(i4 * 4)+1];
					result[14] = look[(i4 * 4)+2];
					result[15] = look[(i4 * 4)+3];
					ft_convert(result);
					ft_respect(str);
					if (ft_respect(str) && ft_check() == 1)
					{
						i = 0;
						while (i < 16)
						{
							if (i == 4 || i == 8 || i == 12)
								write(1, &"\n", 1);
							write(1, &result[i], 1);
							i++;
						}
						write(1, &"\n", 1);
						return ;
					}
					i4++;
				}
				i3++;
			}
			i2++;
		}
		i1++;
	}
	ft_erreur();
}

void	ft_error(char *str)
{
	int	count;
	int	repeat;

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
	repeat = 0;
	ft_load(str);
	return ;
}

int	ft_size(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i%2 == 1) && str[i] != 32)
			return (0);
		if ((i%2 == 0) && (str[i] < '1' || str[i] > '4'))
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
