/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbae <seungbae@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:49:36 by seungbae          #+#    #+#             */
/*   Updated: 2022/06/04 23:43:00 by seungbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;

	i = 0;
	while (src[i])
		i++;
	result = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	if (result == NULL)
		return (NULL);
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	int			i;

	result = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < ac)
	{
		result[i].str = av[i];
		result[i].copy = ft_strdup(av[i]);
		result[i].size = ft_strlen(av[i]);
		i++;
	}
	result[i].str = 0;
	result[i].copy = 0;
	result[i].size = 0;
	return (result);
}
