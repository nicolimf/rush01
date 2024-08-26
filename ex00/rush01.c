/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassem <cassem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:44:41 by nicomart          #+#    #+#             */
/*   Updated: 2024/08/25 20:20:12 by cassem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	is_valid(int **table, int row, int col, int num)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (table[row][i] == num || table[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int **table, int row, int col)
{
	int		num;

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

int	*check_clues(char **argv)
{
	int	*clues;
	int	i;

	i = 0;
	clues = (int *)malloc(16 * sizeof(int));
	while (i < 16)
	{
		clues[i] = argv[1][2 * i] - '0';
		i++;
	}
	return (clues);
}
