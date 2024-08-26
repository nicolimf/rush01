/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassem <cassem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:17:10 by cassem            #+#    #+#             */
/*   Updated: 2024/08/25 20:19:16 by cassem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_table(int **table)
{
	int		i;
	int		j;

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

int	**init_table(void)
{
	int	**table;
	int	i;
	int	j;

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