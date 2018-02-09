/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:10:26 by allallem          #+#    #+#             */
/*   Updated: 2018/02/09 10:30:04 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_merde(t_filler *p)
{
	p->myposx = -p->piecex;
	p->myposy = -p->piecey;
	ft_place_piece(p);
	p->bestx = p->myposx;
	p->besty = p->myposy;
}


void		ft_up(t_filler *p)
{
	p->besty = p->y;
	while (p->myposy != p->y)
	{
		ft_placepiece_spe(p);
		dprintf(3, "possibilite: %iy %ix\n", p->myposy, p->myposx);
		if (p->myposy < p->besty && p->myposy != p->y)
		{
			p->bestx = p->myposx;
			p->besty = p->myposy;
		}
	}
	if (p->besty == p->y)
		ft_merde(p);
}


void		ft_right(t_filler *p)
{
	p->bestx = -p->piecex;
	while (p->myposy != p->y)
	{
		ft_placepiece_spe(p);
		if (p->myposx > p->bestx && p->myposy != p->y)
		{
			p->bestx = p->myposx;
			p->besty = p->myposy;
		}
	}
	if (p->bestx == -p->piecex)
		ft_merde(p);
}

void		ft_left(t_filler *p)
{
	p->myposx = p->x;
	while (p->myposy != p->y)
	{
		ft_placepiece_spe(p);
		if (p->myposx < p->bestx && p->myposy != p->y)
		{
			p->bestx = p->myposx;
			p->besty = p->myposy;
		}
	}
	if (p->myposx == p->x)
		ft_merde(p);
}

void		ft_bottom(t_filler *p)
{
	p->myposy = -p->piecey;
	while (p->myposy != p->y)
	{
		ft_placepiece_spe(p);
		if (p->myposy > p->besty && p->myposy != p->y)
		{
			p->bestx = p->myposx;
			p->besty = p->myposy;
		}
	}
	if (p->myposy == -p->piecey)
		ft_merde(p);
}
