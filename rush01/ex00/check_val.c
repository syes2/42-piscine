/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:09:55 by cyun              #+#    #+#             */
/*   Updated: 2022/05/29 20:30:18 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_row(int board[4][4], int idx, int val)
{
	int	i;

	i = -1;
	while (++i < idx / 4)
		if (board[i][idx % 4] == val)
			return (0);
	i = -1;
	while (++i < idx % 4)
		if (board[idx / 4][i] == val)
			return (0);
	return (1);
}

int	check_col_up(int board[4][4], int args[16], int idx)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (idx / 4 == 3)
	{
		while (i < 4)
		{
			if (board[i][idx % 4] > max)
			{
				max = board[i][idx % 4];
				count++;
			}
			i++;
		}
		if (args[idx % 4] != count)
			return (0);
	}
	return (1);
}

int	check_col_down(int board[4][4], int args[16], int idx)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	if (idx / 4 == 3)
	{
		while (i >= 0)
		{
			if (board[i][idx % 4] > max)
			{
				max = board[i][idx % 4];
				count++;
			}
			i--;
		}
		if (args[4 + idx % 4] != count)
			return (0);
	}
	return (1);
}

int	check_row_left(int board[4][4], int args[16], int idx)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (idx % 4 == 3)
	{
		while (i < 4)
		{
			if (board[idx / 4][i] > max)
			{
				max = board[idx / 4][i];
				count++;
			}
			i++;
		}
		if (args[8 + idx / 4] != count)
			return (0);
	}
	return (1);
}

int	check_row_right(int board[4][4], int args[16], int idx)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	if (idx % 4 == 3)
	{
		while (i >= 0)
		{
			if (board[idx / 4][i] > max)
			{
				max = board[idx / 4][i];
				count++;
			}
			i--;
		}
		if (args[12 + idx / 4] != count)
			return (0);
	}
	return (1);
}
