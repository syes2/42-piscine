/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbae <seungbae@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:27:39 by seungbae          #+#    #+#             */
/*   Updated: 2022/06/05 22:47:29 by seungbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

int	get_len(char **strs, char *sep, int size)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (++i < size)
		len += ft_strlen(strs[i]);
	len = len + (size - 1) * ft_strlen(sep);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*result;
	int		len;

	if (size == 0)
	{
		result = (char *)malloc(sizeof(char));
		*result = '\0';
		return (result);
	}
	i = -1;
	len = get_len(strs, sep, size);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[0] = '\0';
	i = -1;
	while (++i < size - 1)
	{
		ft_strcat(result, strs[i]);
		ft_strcat(result, sep);
	}
	ft_strcat(result, strs[i]);
	result[len] = '\0';
	return (result);
}
