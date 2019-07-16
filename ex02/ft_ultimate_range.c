/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:08:19 by exam              #+#    #+#             */
/*   Updated: 2019/07/16 14:58:12 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int length;
	int *tab;

	i = 1;
	if (min >= max)
	{
		range = 0;
		return (0);
	}
	length = max - min;
	if (range == 0)
		return (-1);
	tab = malloc(sizeof(int) * (length));
	if (tab == 0)
		return (-1);
	tab[0] = min;
	while (i < length)
	{
		tab[i] = tab[i - 1] + 1;
		i++;
	}
	*range = tab;
	return (length);
}
