/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:25:33 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/21 15:25:39 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include <unistd.h>

typedef int	t_bool;
#define EVEN(nbr) (nbr % 2 == 0)

#define TRUE 1
#define FALSE 0

#define SUCCESS 0

#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"
