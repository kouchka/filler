/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:10:26 by allallem          #+#    #+#             */
/*   Updated: 2018/02/12 18:37:50 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_merde(t_filler *p)
{
	p->myposx = -p->piecex;
	p->myposy = -p->piecey;
	ft_place_piece(p);
	ft_printf("%i %i\n", p->myposy, p->myposx);
}

void		ft_up_right(t_filler *p)
{
	p->besty = p->y;
	p->bestx = -p->piecex;
	while (p->myposy != p->y)
	{
		ft_place_piece(p);
		if (p->myposy <= p->besty && p->myposx >= p->bestx && p->myposy != p->y)
		{
			p->bestx = p->myposx;
			p->besty = p->myposy;
		}
	}
	if (p->besty == p->y && p->bestx == -p->piecex)
		ft_merde(p);
	else
		ft_printf("%i %i\n", p->besty, p->bestx);
}

void		ft_bottom_right(t_filler *p)
{
	p->bestx = -p->piecex;
	p->besty = -p->piecey;
	while (p->myposy != p->y)
	{
		ft_place_piece(p);
		if (p->myposx >= p->bestx && p->myposy >= p->besty && p->myposy != p->y)
		{
			p->bestx = p->myposx;
			p->besty = p->myposy;
		}
	}
	if (p->bestx == -p->piecex && p->besty == -p->piecey)
		ft_merde(p);
	else
		ft_printf("%i %i\n", p->besty, p->bestx);
}

void		ft_bottom_left(t_filler *p)
{
	p->bestx = p->x;
	p->besty = -p->piecey;
	while (p->myposy != p->y)
	{
		ft_place_piece(p);
		if (p->myposx <= p->bestx && p->myposy >= p->besty && p->myposy != p->y)
		{
			p->bestx = p->myposx;
			p->besty = p->myposy;
		}
	}
	if (p->bestx == p->x && p->besty == -p->piecey)
		ft_merde(p);
	else
		ft_printf("%i %i\n", p->besty, p->bestx);
}

void		ft_up_left(t_filler *p)
{
	p->besty = p->y;
	p->bestx = p->x;
	while (p->myposy != p->y)
	{
		ft_place_piece(p);
		if (p->myposy <= p->besty && p->myposx <= p->bestx && p->myposy != p->y)
		{
			p->bestx = p->myposx;
			p->besty = p->myposy;
		}
	}
	if (p->besty == p->y && p->bestx == p->x)
		ft_merde(p);
	else
		ft_printf("%i %i\n", p->besty, p->bestx);
}
