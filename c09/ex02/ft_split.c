/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbae <seungbae@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:15:57 by seungbae          #+#    #+#             */
/*   Updated: 2022/06/07 15:46:19 by seungbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		charset++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			cnt++;
			while (str[i] && !is_charset(str[i], charset))
				i++;
		}
		i++;
	}
	return (cnt);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (*src && i < n)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**result;
	char	*from;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (count_word(str, charset) + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			from = str;
			while (*str && !is_charset(*str, charset))
				str++;
			result[i] = (char *)malloc(str - from + 1);
			ft_strncpy(result[i], from, str - from);
			i++;
		}
		str++;
	}
	result[i] = 0;
	return (result);
}
