/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbae <seungbae@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:54:08 by seungbae          #+#    #+#             */
/*   Updated: 2022/05/21 16:20:42 by seungbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	n[2];

	n[0] = 0;
	n[1] = 0;
	while (n[0] < 100)
	{
		n[1] = n[0] + 1;
		while (n[1] < 100)
		{
			ft_putchar(n[0] / 10 + '0');
			ft_putchar(n[0] % 10 + '0');
			write(1, " ", 1);
			ft_putchar(n[1] / 10 + '0');
			ft_putchar(n[1] % 10 + '0');
			if (n[0] != 98)
				write(1, ", ", 2);
			n[1]++;
		}
		n[0]++;
	}
}
