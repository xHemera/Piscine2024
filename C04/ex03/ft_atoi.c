/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:19:00 by tobesnar          #+#    #+#             */
/*   Updated: 2024/08/12 15:35:46 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int    ft_atoi(char *str)
{
    int    i;
    int    sign;
    int    result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
    {
        i++;
    }
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
        {
            sign = -sign;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (sign * result);
}

int main( int argc, char * argv[] ) {

    /*
     * Doit-on afficher l'usage de la commande.
     */
    if ( argc == 1 ) {
        printf( "Usage: %s intValue ...\n", argv[0] );
        exit( EXIT_SUCCESS );
    }

    /*
     * On passe le nom de l'exécutable qui est
     * en première position dans les arguments.
     */
    argc--;   argv++;

    int sum = 0;

    /*
     * On somme toutes les valeurs passées en arguments du programme.
     * Pour ce faire on déplace le pointeur argv pour scanner tous les arguments.
     */
    while ( argc != 0 ) {

        sum += ft_atoi( *argv++ );
        argc--;

    }

    /*
     * Et on affiche le résultat
     */
    printf( "La somme des valeurs saisies est de %d.\n", sum );

    return EXIT_SUCCESS;
}
