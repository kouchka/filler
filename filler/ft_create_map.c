/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:42:55 by allallem          #+#    #+#             */
/*   Updated: 2018/01/31 17:30:14 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_create_map(t_filler *p)
{
	int i;
	int j;

	i = 0;
	if (!(p->map = (char**)malloc(sizeof(char*) * p->y + 1)))
		return (0);
	p->map[p->y] = 0;
	while (i < p->y)
	{
		j = 0;
		if (!(p->map[i] = (char*)malloc(sizeof(char) * p->x + 1)))
			return (0);
		while (j < p->x)
		{
			p->map[i][j] = '.';
			j++;
		}
		p->map[i][j] = '\0';
		i++;
	}
	return (1);
}

