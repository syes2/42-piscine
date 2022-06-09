/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:55:57 by sechung           #+#    #+#             */
/*   Updated: 2022/05/22 23:36:00 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	check_int(int x)
{
	if (x <= 0 || x > 0x7fffffff)
	{
		return (0);
	}
	return (x);
}

int	ft_atoi(char *data)
{
	int		result;
	int		len;

	len = 1;
	result = 0;
	while (*data)
	{
		if (len == 1 && *data == '+')
			result = 0;
		else if (*data >= '0' && *data <= '9')
			result = result * 10 + *data - '0';
		else
			return (-1);
		data++;
		len++;
	}
	result = check_int(result);
	return (result);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	}
	return (0);
}
