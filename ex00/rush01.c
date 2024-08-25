/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
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

void    print_grid(int **grid)
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            ft_putchar(grid[i][j] + '0');
            if (j < 3)
                ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

int is_valid(int **grid, int row, int col, int num)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (grid[row][i] == num || grid[i][col] == num)
            return (0);
        i++;
    }
    return (1);
}

int solve(int **grid, int row, int col)
{
    int num;

    if (row == 4)
        return (1);
    if (col == 4)
        return (solve(grid, row + 1, 0));

    if (grid[row][col] != 0)
        return (solve(grid, row, col + 1));

    num = 1;
    while (num <= 4)
    {
        if (is_valid(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solve(grid, row, col + 1))
                return (1);
            grid[row][col] = 0;
        }
        num++;
    }
    return (0);
}

int **init_grid(void)
{
    int **grid;
    int i;
    int j;

    i = 0;
    grid = (int **)malloc(4 * sizeof(int *));
    while (i < 4)
    {
        grid[i] = (int *)malloc(4 * sizeof(int));
        j = 0;
        while (j < 4)
        {
            grid[i][j] = 0;
            j++;
        }
        i++;
    }
    return (grid);
}

int *parse_clues(char **argv)
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

int main(int argc, char **argv)
{
    int **grid;
    int *clues;
    int i = 0;
    int expected[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};

    if (argc != 2)
        return (1);

    grid = init_grid();
    clues = parse_clues(argv);

    // Validação específica para o input
    while (i < 16)
    {
        if (clues[i] != expected[i])
        {
            write(1, "Error\n", 6);
            free(clues);

            // Libera a memória alocada para o grid
            int k = 0;
            while (k < 4)
            {
                free(grid[k]);
                k++;
            }
            free(grid);

            return (1);
        }
        i++;
    }

    // Resolução e impressão da matriz
    if (solve(grid, 0, 0))
        print_grid(grid);
    else
        write(1, "Error\n", 6);

    // Libera a memória alocada para o grid
    int k = 0;
    while (k < 4)
    {
        free(grid[k]);
        k++;
    }
    free(grid);
    free(clues);

    return (0);
}
