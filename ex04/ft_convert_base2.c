/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:18:39 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/17 17:14:07 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int			check_base(char *base, long int *base_length);

int			is_alphanumeric(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
			(c >= '0' && c <= '9'))
		return (1);
	return (0);
}

long int	ft_strlen(char *str)
{
	long int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		fill_result(long int nb, char *base, char *result, int length)
{
	int			is_neg;
	long int	base_length;
	long int	curr_nb;
	int			i;

	is_neg = nb < 0 ? 1 : 0;
	nb = is_neg ? nb * -1 : nb;
	result[length + is_neg] = '\0';
	base_length = ft_strlen(base);
	curr_nb = nb;
	i = 0;
	while (i <= (length + is_neg))
	{
		result[(length + is_neg) - i] = base[curr_nb % base_length];
		curr_nb = curr_nb / base_length;
		i++;
	}
	if (is_neg)
		result[0] = '-';
}

int			allocate_mem(char **result, long int nbr, int length)
{
	*result = 0;
	if (nbr < 0)
		*result = (char *)malloc(sizeof(char) * length + 1);
	else
		*result = (char *)malloc(sizeof(char) * length);
	if (*result == 0)
		return (0);
	return (1);
}

char		*nb_to_str_base(int nbr, char *base)
{
	long int		base_length;
	int				result_length;
	char			*result;
	long int		curr_nb;

	base_length = 0;
	result_length = 0;
	result = 0;
	nbr = (long)nbr;
	curr_nb = nbr;
	if (check_base(base, &base_length))
	{
		result_length = 0;
		while (curr_nb / base_length != 0)
		{
			curr_nb = curr_nb / base_length;
			result_length++;
		}
		if (allocate_mem(&result, nbr, result_length))
			fill_result(nbr, base, result, result_length);
	}
	return (result);
}
