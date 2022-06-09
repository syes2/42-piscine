/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbae <seungbae@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:12:57 by seungbae          #+#    #+#             */
/*   Updated: 2022/06/06 17:28:02 by seungbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	get_nb(char c, char *base);
int	base_length(long long nbr, int radix);

int	check_base(char *base)
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
		if ((base[i] > 8 && base[i] < 14) || base[i] == ' ')
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

int	ft_atoi_base(char *str, char *base, int *sign)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	while (str[i] && (get_nb(str[i], base) != -1))
	{
		result = (result * ft_strlen(base)) + *sign * (get_nb(str[i], base));
		i++;
	}
	return (result);
}

char	*ft_itoa_base(long long nbr, char *base, int *sign)
{
	int		radix;
	int		index;
	int		size;
	char	*result;

	index = -1;
	radix = ft_strlen(base);
	size = base_length(nbr, radix);
	result = (char *)malloc(size + 1);
	if (!result)
		return (0);
	if (*sign == -1)
	{
		result[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		result[0] = base[0];
	while (index++ < size && (*sign != -1 || (size - index -1) != 0))
	{
		result[size - index - 1] = base[nbr % radix];
		nbr /= radix;
	}
	result[size] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			sign;
	long long	result;

	sign = 1;
	if (!check_base(base_from) || !check_base(base_to))
		return (0);
	if (ft_strlen(base_from) < 2 || ft_strlen(base_to) < 2)
		return (0);
	result = ft_atoi_base(nbr, base_from, &sign);
	return (ft_itoa_base(result, base_to, &sign));
}
