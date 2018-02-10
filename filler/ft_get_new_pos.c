/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_new_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:34:43 by allallem          #+#    #+#             */
/*   Updated: 2018/02/10 17:29:22 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_get_new_pos(t_filler *p)
{
	int i;
	int j;
	int bestx;
	int besty;

	bestx = 0;
	besty = 0;
	i = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == p->symbol + 32 &&
			(j > p->x / 2 + p->x / 3  || i > p->y / 2 + p->y / 3
			 || j < p->x / 2 - p->x / 3 || i < p->y / 2 - p->y / 3))
				p->map[i][j] = p->symbol;
			if (p->map[i][j] == p->symbol &&
			(j < p->x / 2 + p->x / 3  && i < p->y / 2 + p->y / 3
			 && j > p->x / 2 - p->x / 3 && i > p->y / 2 - p->y / 3))
				p->map[i][j] = p->symbol + 32;
			j++;
		}
		i++;
	}
	dprintf(3, "\n");
}
