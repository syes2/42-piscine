/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:10:19 by cyun              #+#    #+#             */
/*   Updated: 2022/05/29 20:32:27 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	is_space_null(char c)
{
	if (c == ' ' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

int	is_valid_args(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if ((str[i] >= '1' && str[i] <= '4') && is_space_null(str[i + 1]))
			cnt++;
		else if (str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	if (cnt != 16)
		return (0);
	return (1);
}

void	set_args(char *argv, int args[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i] >= '1' && argv[i] <= '4')
		{
			args[j] = argv[i] - '0';
			j++;
		}
		i++;
	}
}

void	set_board(int board[4][4])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		board[i / 4][i % 4] = 0;
		i++;
	}
}

void	print_board(int board[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(board[i][j] + '0');
			if (j != 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
