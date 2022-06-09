/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbae <seungbae@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:17:24 by seungbae          #+#    #+#             */
/*   Updated: 2022/05/31 19:51:45 by seungbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(int *board, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (board[i] == board[j])
			return (0);
		if (board[i] - board[j] == i - j)
			return (0);
		if (board[j] - board[i] == i - j)
			return (0);
		j++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ten_queens(int *board, int index, int *count)
{
	int	i;

	i = 0;
	if (index == 10)
	{
		while (i < 10)
		{
			ft_putchar(board[i] + '0');
			i++;
		}
		ft_putchar('\n');
		(*count)++;
		return ;
	}
	i = 0;
	while (i < 10)
	{
		board[index] = i;
		if (is_valid(board, index))
			ten_queens(board, index + 1, count);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{	
	int	board[10];
	int	count;
	int	i;

	i = 0;
	while (i < 10)
	{
		board[i] = 0;
		i++;
	}
	count = 0;
	ten_queens(board, 0, &count);
	return (count);
}
