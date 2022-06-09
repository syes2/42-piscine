/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:10:11 by cyun              #+#    #+#             */
/*   Updated: 2022/05/29 20:32:05 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_col_row(int board[4][4], int idx, int val);
int		check_col_up(int board[4][4], int args[16], int idx);
int		check_col_down(int board[4][4], int args[16], int idx);
int		check_row_left(int board[4][4], int args[16], int idx);
int		check_row_right(int board[4][4], int args[16], int idx);
void	init_colup(int board[4][4], int args[16]);
void	init_coldown(int board[4][4], int args[16]);
void	init_rowleft(int board[4][4], int args[16]);
void	init_rowright(int board[4][4], int args[16]);

int	check_case(int board[4][4], int args[16], int idx)
{
	if (!check_row_left(board, args, idx))
		return (0);
	if (!check_row_right(board, args, idx))
		return (0);
	if (!check_col_up(board, args, idx))
		return (0);
	if (!check_col_down(board, args, idx))
		return (0);
	return (1);
}

int	tracking_board(int board[4][4], int chk[4][4], int args[16], int idx)
{
	int	val;

	if (idx == 16)
		return (1);
	val = 0;
	if (chk[idx / 4][idx % 4] == 1)
		if (check_case(board, args, idx))
			if (tracking_board(board, chk, args, idx + 1))
				return (1);
	while (++val <= 4)
	{
		if (check_col_row(board, idx, val) && chk[idx / 4][idx % 4] == 0)
		{
			board[idx / 4][idx % 4] = val;
			if (check_case(board, args, idx))
			{
				if (tracking_board(board, chk, args, idx + 1))
					return (1);
			}
			else
				board[idx / 4][idx % 4] = 0;
		}
	}
	return (0);
}

int	fill_board(int board[4][4], int args[16], int chk[4][4])
{
	if (!tracking_board(board, chk, args, 0))
		return (0);
	return (1);
}

void	rush(int board[4][4], int args[16], int *check)
{
	int	chk[4][4];
	int	i;

	i = 0;
	init_colup(board, args);
	init_coldown(board, args);
	init_rowleft(board, args);
	init_rowright(board, args);
	while (i < 16)
	{
		if (board[i / 4][i % 4] != 0)
			chk[i / 4][i % 4] = 1;
		else
			chk[i / 4][i % 4] = 0;
		i++;
	}
	if (!fill_board(board, args, chk))
	{
		*check = 0;
		return ;
	}
	*check = 1;
}
