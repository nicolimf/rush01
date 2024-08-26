/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicomart <nicomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:39:04 by nicomart          #+#    #+#             */
/*   Updated: 2024/08/25 21:55:00 by nicomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rush01.h"
#include "utils.h"

void	handle_error(int **table, int *clues)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		free(table[k]);
		k++;
	}
	free(table);
	free(clues);
	write(1, "Error\n", 6);
}

int	get_expected_input(int i)
{
	static int	input[16];

	input[0] = 4;
	input[1] = 3;
	input[2] = 2;
	input[3] = 1;
	input[4] = 1;
	input[5] = 2;
	input[6] = 2;
	input[7] = 2;
	input[8] = 4;
	input[9] = 3;
	input[10] = 2;
	input[11] = 1;
	input[12] = 1;
	input[13] = 2;
	input[14] = 2;
	input[15] = 2;
	if (i >= 0 && i < 16)
		return (input[i]);
	return (-1);
}

int	check_clues_against_input(int *clues)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (clues[i] != get_expected_input(i))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	**table;
	int	*clues;

	if (argc != 2)
		return (1);
	table = init_table();
	clues = check_clues(argv);
	if (!check_clues_against_input(clues))
	{
		handle_error(table, clues);
		return (1);
	}
	if (solve(table, 0, 0))
		print_table(table);
	else
		handle_error(table, clues);
	return (0);
}
