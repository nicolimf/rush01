/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicomart <nicomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:12:27 by nicomart          #+#    #+#             */
/*   Updated: 2024/08/25 18:12:34 by nicomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
#define RUSH01_H

int **init_table(void);
int *check_clues(char **argv);
int solve(int **grid, int row, int col);
void print_table(int **grid);
void free_clues_and_grid(int *clues, int **grid);

#endif
