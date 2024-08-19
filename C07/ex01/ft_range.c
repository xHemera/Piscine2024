/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:20:51 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/18 17:20:53 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int i;

	i = 0;
	result = (int *)(malloc(sizeof(int) * (max - min)));
	if (min >= max)
			return (NULL);
	if ((max - min) < 1)
			result = NULL;
	while (i < (max - min))
	{
		result[i] = (min + i);
		i++;
	}
	return (result);
}


/*int main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("%p", ft_range(atoi(argv[1]), atoi(argv[2])));
	}
}*/
