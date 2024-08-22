/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:23:32 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/08 13:07:58 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isnt_alphanum(int n)
{
	if (n <= 47 || (n >= 58 && n <= 64) || (n >= 92 && n <= 96) || n >= 123)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	last_c_isnt_alphanum;

	i = 0;
	last_c_isnt_alphanum = 1;
	while (str[i])
	{
		if (!last_c_isnt_alphanum && (str[i] >= 65 && str[i] <= 90))
			str[i] += 32;
		else
			if (last_c_isnt_alphanum && (str[i] >= 97 && str[i] <= 122))
				str[i] -= 32;
		if (isnt_alphanum(str[i]) == 1)
			last_c_isnt_alphanum = 1;
		else
			last_c_isnt_alphanum = 0;
		i++;
	}
	return (str);
}
