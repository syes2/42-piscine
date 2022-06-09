/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:09:50 by cyun              #+#    #+#             */
/*   Updated: 2022/05/29 20:33:27 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	ft_putstr(char *str);
int		is_valid_args(char *str);
void	set_args(char *argv, int args[16]);
void	rush(int board[4][4], int args[16], int *check);
void	print_board(int board[4][4]);
void	set_board(int board[4][4]);

int	main(int argc, char *argv[])
{
	int	(*board)[4];
	int	args[16];
	int	check;

	board = (int (*)[4])malloc(4 * 4 * sizeof(int));
	if (!board)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (argc != 2 || !is_valid_args(argv[1]))
		ft_putstr("Error\n");
	else
	{
		set_args(argv[1], args);
		set_board(board);
		rush(board, args, &check);
		if (check)
			print_board(board);
		else
			ft_putstr("Error\n");
	}
	free(board);
	return (0);
}
