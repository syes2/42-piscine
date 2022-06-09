/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbae <seungbae@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:05:10 by seungbae          #+#    #+#             */
/*   Updated: 2022/05/21 11:31:38 by seungbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_recur(int n, int index, int prev, char value[])
{
	int	i;
	int	cur;

	i = 0;
	cur = prev + 1;
	if (index == n)
	{
		while (i < n)
		{
			write(1, &(value[i++]), 1);
		}
		if (value[0] != '0' + 10 - n)
		{
			write(1, ", ", 2);
		}
		return ;
	}
	while (cur <= 9)
	{
		value[index] = cur + '0';
		ft_recur(n, index + 1, cur, value);
		cur++;
	}
}

void	ft_print_combn(int n)
{
	char	value[10];

	ft_recur(n, 0, -1, value);
}
