/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:40:20 by exam              #+#    #+#             */
/*   Updated: 2019/07/18 18:43:00 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char *str, char *charset, int start)
{
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = 0;
	while (charset[length])
		length++;
	while (str[start + i] && charset[i] && str[start + i] == charset[i])
		i++;
	while ((str[start - j] && charset[j]) &&
			(str[start - j] == charset[length - 1 - j]))
		j++;
	return (charset[i] || str[start - j + 1] != *charset ? 0 : 1);
}

int		get_nb_word(char *str, char *charset)
{
	int		i;
	int		j;
	int		nb_word;
	int		length;

	i = 0;
	nb_word = 0;
	length = 0;
	while (str[length])
		length++;
	while (str[i])
	{
		j = 0;
		if (!is_separator(str, charset, i))
		{
			while (i + j < length - 1 && !is_separator(str, charset, i + j))
				j++;
			if (j > 0)
				nb_word++;
		}
		i = i + j + 1;
	}
	return (nb_word);
}

int		write_str(char **array, char *str, int i, int k)
{
	int		j;

	j = 0;
	if (k != 0)
	{
		array[i] = (char *)malloc(sizeof(char) * k + 1);
		if (array[i] == 0)
			return (0);
		j = 0;
		while (j < k)
		{
			array[i][j] = str[j];
			j++;
		}
		array[i][j] = '\0';
		i++;
	}
	return (1);
}

int		fill_array(char **array, char *str, char *charset, int sep_length)
{
	int		i;
	int		k;
	int		length;

	length = 0;
	while (str[length])
		length++;
	i = 0;
	while (*str && array[i] != 0)
	{
		k = 0;
		if (!is_separator(str, charset, 0))
		{
			while (k < length - 1 && str[k] && !is_separator(str, charset, k))
				k++;
			if (!write_str(array, str, i, k))
				return (0);
		}
		str = str + k + sep_length;
	}
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		nb_words;
	int		sep_length;

	array = 0;
	sep_length = 0;
	if (str == 0 && charset == 0 && !*str)
		return (0);
	else if (!*charset && *str)
	{
		if (!(array = (char **)malloc(sizeof(str) + sizeof(0))))
			return (0);
		array[0] = str;
		array[1] = 0;
		return (array);
	}
	while (charset[sep_length])
		sep_length++;
	nb_words = get_nb_word(str, charset);
	if ((array = (char **)malloc(sizeof(char *) * nb_words + 1)) == 0)
		return (0);
	array[nb_words] = 0;
	if (!fill_array(array, str, charset, sep_length))
		return (0);
	return (array);
}
