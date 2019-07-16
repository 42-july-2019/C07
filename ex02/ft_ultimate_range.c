/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:05:48 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/16 15:06:03 by alabreui         ###   ########.fr       */
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
