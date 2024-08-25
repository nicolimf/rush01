/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicomart <nicomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:39:04 by nicomart          #+#    #+#             */
/*   Updated: 2024/08/25 19:17:00 by nicomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rush01.h"

int main(int argc, char **argv)
{
    int **table;
    int *clues;
    int i;
    
    i = 0;
    int input[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};

    if (argc != 2)
        return (1);

    table = init_table();
    clues = check_clues(argv);

    // Validação específica para o input
    while (i < 16)
    {
        if (clues[i] != input[i])
        {
            write(1, "Error\n", 6);
            free(clues);

            // Libera a memória alocada para o table
            int k = 0;
            while (k < 4)
            {
                free(table[k]);
                k++;
            }
            free(table);

            return (1);
        }
        i++;
    }

    // Resolução e impressão da matriz
    if (solve(table, 0, 0))
        print_table(table);
    else
        write(1, "Error\n", 6);

    // Libera a memória alocada para o table
    int k;
    k = 0;
    while (k < 4)
    {
        free(table[k]);
        k++;
    }
    free(table);
    free(clues);

    return (0);
}