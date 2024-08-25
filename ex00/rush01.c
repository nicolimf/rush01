/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicomart <nicomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:44:41 by nicomart          #+#    #+#             */
/*   Updated: 2024/08/25 17:06:09 by nicomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    print_table(int **table)
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            ft_putchar(table[i][j] + '0');
            if (j < 3)
                ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

int is_valid(int **table, int row, int col, int num)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (table[row][i] == num || table[i][col] == num)
            return (0);
        i++;
    }
    return (1);
}

int solve(int **table, int row, int col)
{
    int num;

    if (col == 4)
        return (solve(table, row + 1, 0));
    if (row == 4)
        return (1);

    if (table[row][col] != 0)
        return (solve(table, row, col + 1));

    num = 1;
    while (num <= 4)
    {
        if (is_valid(table, row, col, num))
        {
            table[row][col] = num;
            if (solve(table, row, col + 1))
                return (1);
            table[row][col] = 0;
        }
        num++;
    }
    return (0);
}

int **init_table(void)
{
    int **table;
    int i;
    int j;

    i = 0;
    table = (int **)malloc(4 * sizeof(int *));
    while (i < 4)
    {
        table[i] = (int *)malloc(4 * sizeof(int));
        j = 0;
        while (j < 4)
        {
            table[i][j] = 0;
            j++;
        }
        i++;
    }
    return (table);
}

int *check_clues(char **argv)
{
    int *clues;
    int i;
    
    i = 0;
    clues = (int *)malloc(16 * sizeof(int));
    while (i < 16)
    {
        clues[i] = argv[1][2 * i] - '0';
        i++;
    }
    return (clues);
}
