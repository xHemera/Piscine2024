/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:11:39 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/15 13:39:44 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 0)
	{
		i = 1;
		while (argv[argc - i] && argc != i)
		{
			write(1, argv[argc - i], ft_strlen(argv[argc - i]));
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
