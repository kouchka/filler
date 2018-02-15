/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:11:05 by allallem          #+#    #+#             */
/*   Updated: 2018/02/14 17:04:10 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		ft_complete_case(t_visu *p, int x, int y, int player)
{
	int i;
	int j;
	int capx;
	int capy;

	i = (p->ymap * y) + 1;
	capy = i + p->ymap - 1;
	capx = (p->xmap * x) + p->xmap - 1;
	while (i < capy)
	{
		j = (p->xmap * x) + 1;
		while (j < capx)
		{
			if (player == 0)
				ft_put_in_image(p, j, i, 0x677E52);
			else if (player == 3)
				ft_put_in_image(p, j, i, 0xFF5B2B);
			else if (player == 2)
				ft_put_in_image(p, j, i, 0xFFF168);
			else if (player == 1)
				ft_put_in_image(p, j, i, 0xB7CA79);
			j++;
		}
		i++;
	}
}
