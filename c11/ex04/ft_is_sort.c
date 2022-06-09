/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbae <seungbae@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:02:37 by seungbae          #+#    #+#             */
/*   Updated: 2022/06/09 16:08:48 by seungbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sorted;

	i = 0;
	sorted = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			sorted += 1;
		if (f(tab[i], tab[i + 1]) < 0)
			sorted -= 1;
		i++;
	}
	if (sorted == length - 1 || sorted == 1 - length)
		return (1);
	return (0);
}
