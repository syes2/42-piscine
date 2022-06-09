/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbae <seungbae@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:20:12 by seungbae          #+#    #+#             */
/*   Updated: 2022/05/29 14:06:30 by seungbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	radix_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_nbr(unsigned int nb, char *base, unsigned int radix)
{
	if (nb >= radix)
	{
		print_nbr(nb / radix, base, radix);
		nb %= radix;
	}
	write(1, &base[nb], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	radix;

	radix = ft_strlen(base);
	if (radix < 2)
		return ;
	if (!radix_check(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		print_nbr(-nbr, base, radix);
	}
	else
		print_nbr(nbr, base, radix);
}
