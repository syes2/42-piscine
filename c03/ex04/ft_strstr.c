/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbae <seungbae@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:53:55 by seungbae          #+#    #+#             */
/*   Updated: 2022/05/26 15:59:27 by seungbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*addr;
	char	*find;
	int		i;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		addr = &str[i];
		find = to_find;
		while (*addr && *find)
		{
			if (*addr != *find)
				break ;
			addr++;
			find++;
		}
		if (!(*find))
			return (&str[i]);
		i++;
	}
	return (0);
}
