/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:06:17 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/16 15:06:26 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int length;
	int *tab;

	tab = 0;
	i = 1;
	if (min >= max)
		return (tab);
	length = max - min;
	tab = malloc(sizeof(int) * (length));
	tab[0] = min;
	while (i < length)
	{
		tab[i] = tab[i - 1] + 1;
		i++;
	}
	return (tab);
}
