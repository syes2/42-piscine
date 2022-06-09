/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:35:09 by sechung           #+#    #+#             */
/*   Updated: 2022/05/22 19:52:49 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char x);

void	define_print(int x, int y, int temp_x, int temp_y)
{
	if ((temp_x == 1 || temp_x == x) && (temp_y == 1 || temp_y == y))
	{
		ft_putchar('o');
	}
	else if (temp_x == 1 || temp_x == x)
	{
		ft_putchar('|');
	}
	else if (temp_y == 1 || temp_y == y)
		ft_putchar('-');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int		temp_x;
	int		temp_y;

	temp_x = 1;
	temp_y = 1;
	while (temp_y <= y && x > 0)
	{
		define_print(x, y, temp_x, temp_y);
		temp_x++;
		if (temp_x > x)
		{
			temp_x = 1;
			temp_y++;
			ft_putchar('\n');
		}
	}
}
