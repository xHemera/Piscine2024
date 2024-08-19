/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:45:46 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/19 15:26:32 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

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

int	ft_ultimate_range(int **range, int min, int max)
{
	if ((max - min) < 1)
	{
		*range = NULL;
		return (0);
	}
	else
	{
		*range = ft_range(min, max);
		if (!range)
		{
			return (-1);
		}
	}
	return (max - min);
}

/*int	main(void)
{
	int	*range;
	int	**ultimate_range;
	int	min;
	int	max;
	int size;
	int i;

	min = 5;
	max = 10;
	range = ft_range(min, max);
	if (range == NULL)
		printf("ft_range returned NULL\n");
	else
	{
		printf("ft_range(%d, %d) = ", min, max);
		for (i = 0; i < max - min; i++)
		{
			printf("%d ", range[i]);
		}
		printf("\n");
	}
	free(range);

	ultimate_range = (int **)malloc(sizeof(int *));
	size = ft_ultimate_range(ultimate_range, min, max);
	if (*ultimate_range == NULL)
		printf("ft_ultimate_range returned NULL, size = %d\n", size);
	else
	{
		printf("ft_ultimate_range(%d, %d) = ", min, max);
		for (i = 0; i < size; i++)
		{
			printf("%d ", (*ultimate_range)[i]);
		}
		printf("\n");
	}
	free(*ultimate_range);
	free(ultimate_range);

	return (0);
}*/
