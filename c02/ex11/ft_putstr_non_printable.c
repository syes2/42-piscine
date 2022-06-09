/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbae <seungbae@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:08:09 by seungbae          #+#    #+#             */
/*   Updated: 2022/05/24 13:02:48 by seungbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;
	char			*hex;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char) str[i];
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			write(1, &hex[c / 16], 1);
			write(1, &hex[c % 16], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
