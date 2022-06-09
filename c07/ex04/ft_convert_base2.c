/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbae <seungbae@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:53:05 by seungbae          #+#    #+#             */
/*   Updated: 2022/06/06 17:27:39 by seungbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_nb(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	base_length(long long nbr, int radix)
{
	int				length;

	length = 1;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		length++;
		nbr *= -1;
	}
	while (nbr / radix > 0)
	{	
		nbr /= radix;
		length++;
	}
	return (length);
}
