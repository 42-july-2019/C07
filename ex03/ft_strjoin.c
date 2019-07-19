/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:00:58 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/17 12:01:24 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_res_length(int size, char **strs, int sep_length)
{
	int		res_length;
	int		i;
	int		j;

	res_length = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			res_length++;
			j++;
		}
		if (i != size - 1)
			res_length += sep_length;
		i++;
	}
	return (res_length);
}

void	join_strs(int size, char **strs, char *sep, char *result)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < size)
	{
		k = 0;
		while (strs[i][k])
		{
			result[j] = strs[i][k];
			j++;
			k++;
		}
		k = 0;
		while (sep[k] && i != size - 1)
		{
			result[j] = sep[k];
			j++;
			k++;
		}
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		res_length;
	int		sep_length;

	sep_length = 0;
	while (sep[sep_length])
		sep_length++;
	res_length = get_res_length(size, strs, sep_length);
	result = (char *)malloc(sizeof(char) * res_length + 1);
	if (result == 0)
		return (0);
	join_strs(size, strs, sep, result);
	result[res_length] = '\0';
	if (size == 0)
		result = (char *)malloc(0);
	return (result);
}
