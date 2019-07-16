/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:08:19 by exam              #+#    #+#             */
/*   Updated: 2019/07/16 12:23:16 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int min, int max)
{
	int i;
	int length;
	int *tab;

	tab = 0;
	i = 1;
	if (min >= max)
		return tab;
	length =  max - min;
	tab = malloc(sizeof(int) * (length) - 1);
	tab[0] = min;
	while (i < length)
	{
		tab[i] = tab[i - 1] + 1;
		i++;
	}
	return tab;
}
