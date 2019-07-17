/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:18:19 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/17 17:12:27 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_alphanumeric(char c);
char	*nb_to_str_base(int nbr, char *base);

int		check_base(char *base, long int *base_length)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (!is_alphanumeric(base[i]))
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
	*base_length = i;
	if (*base == '\0' || *base_length <= 1)
		return (0);
	return (1);
}

int		get_digit(char c, char *base, long int *base_length)
{
	long int i;

	i = 0;
	while (i < *base_length && base[i] != c)
	{
		i++;
	}
	if (i == *base_length)
		return (-1);
	return (i);
}

int		convert_to_int(char *str, char *base, long int *base_length)
{
	long int i;
	long int result;
	long int current_digit;

	i = 0;
	result = 0;
	current_digit = get_digit(str[i], base, base_length);
	while (current_digit != -1)
	{
		result = result * *base_length;
		result = result + current_digit;
		i++;
		current_digit = get_digit(str[i], base, base_length);
	}
	return (result);
}

int		ft_atoi_base(char *str, char *base)
{
	long int	length;
	long int	*base_length;
	long int	result;
	int			nb_sign;

	length = 0;
	base_length = &length;
	nb_sign = 1;
	result = 0;
	if (check_base(base, base_length))
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' ||
				(*str == '\f') || (*str == '\r'))
			str++;
		while (*str == '+' || *str == '-')
		{
			if (*str == '-')
				nb_sign = -1 * nb_sign;
			str++;
		}
		result = convert_to_int(str, base, base_length);
	}
	return (nb_sign * result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	nb;
	char		*result;

	nb = ft_atoi_base(nbr, base_from);
	result = nb_to_str_base(nb, base_to);
	return (result);
}
