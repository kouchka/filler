/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:10:26 by allallem          #+#    #+#             */
/*   Updated: 2018/02/09 04:42:45 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_up(t_filler *p)
{
	while (p->myposy != p->y)
	{
		ft_place_piece(p);
		if (p->myposy < p->besty && p->myposy != p->y)
		{
			p->bestx = p->myposx;
			p->besty = p->myposy;
		}
	}
}


void		ft_right(t_filler *p)
{
	while (p->myposy != p->y)
	{
		ft_place_piece(p);
		if (p->myposx > p->bestx && p->myposy != p->y)
		{
			p->bestx = p->myposx;
			p->besty = p->myposy;
		}
	}

}

void		ft_left(t_filler *p)
{
	while (p->myposy != p->y)
	{
		ft_place_piece(p);
		if (p->myposx < p->bestx && p->myposy != p->y)
		{
			p->bestx = p->myposx;
			p->besty = p->myposy;
		}
	}
}

void		ft_bottom(t_filler *p)
{
	while (p->myposy != p->y)
	{
		ft_place_piece(p);
		if (p->myposy > p->besty && p->myposy != p->y)
		{
			p->bestx = p->myposx;
			p->besty = p->myposy;
		}
	}
}
