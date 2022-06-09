/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:10:02 by cyun              #+#    #+#             */
/*   Updated: 2022/05/29 20:30:28 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_colup(int board[4][4], int args[16])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		if (args[i] == 1)
			board[0][i] = 4;
		else if (args[i] == 4)
		{
			j = -1;
			while (++j < 4)
				board[j][i] = j + 1;
		}
		else if (args[i] == 2 && args[i + 4] == 3)
			board[1][i] = 4;
		else if (args[i] == 1 && args[i + 4] == 2)
			board[3][i] = 3;
	}
}

void	init_coldown(int board[4][4], int args[16])
{
	int	i;
	int	j;
	int	k;

	i = 3;
	k = 4;
	while (++i < 8)
	{
		if (args[i] == 1)
			board[3][i - 4] = 4;
		else if (args[i] == 4)
		{
			j = -1;
			while (++j < 4)
			{
				board[j][i - 4] = k;
				k--;
			}
		}
		else if (args[i] == 2 && args[i - 4] == 3)
			board[2][i - 4] = 4;
		else if (args[i] == 1 && args[i - 4] == 2)
			board[0][i - 4] = 3;
	}
}

void	init_rowleft(int board[4][4], int args[16])
{
	int	i;
	int	j;

	i = 7;
	while (++i < 12)
	{
		if (args[i] == 1)
			board[i - 8][0] = 4;
		else if (args[i] == 4)
		{
			j = -1;
			while (++j < 4)
				board[i - 8][j] = j + 1;
		}
		else if (args[i] == 2 && args[i + 4] == 3)
			board[i - 8][1] = 4;
		else if (args[i] == 1 && args[i + 4] == 2)
			board[i - 8][3] = 3;
	}
}

void	init_rowright(int board[4][4], int args[16])
{
	int	i;
	int	j;
	int	k;

	i = 11;
	k = 4;
	while (++i < 16)
	{
		if (args[i] == 1)
			board[i - 12][3] = 4;
		else if (args[i] == 4)
		{
			j = -1;
			while (++j < 4)
			{
				board[i - 12][j] = k;
				k--;
			}
		}
		else if (args[i] == 2 && args[i - 4] == 3)
			board[i - 12][2] = 4;
		else if (args[i] == 1 && args[i - 4] == 2)
			board[i - 12][0] = 3;
	}
}
