/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:10:26 by allallem          #+#    #+#             */
/*   Updated: 2018/02/10 17:59:32 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_merde(t_filler *p)
{
	p->myposx = -p->piecex;
	p->myposy = -p->piecey;
	ft_place_piece(p);
	dprintf(3, "merde%i %i\n", p->myposy, p->myposx);
	ft_printf("%i %i\n", p->myposy, p->myposx);
}

void		ft_up(t_filler *p)
{
	while (ft_verif_border(p, 0))
	{
		dprintf(3, "up\n");
		p->besty = p->y;
		while (p->myposy != p->y)
		{
			ft_placepiece_spe(p);
			if (p->myposy < p->besty && p->myposy != p->y)
			{
				p->bestx = p->myposx;
				p->besty = p->myposy;
			}
		}
		if (p->besty == p->y)
			ft_merde(p);
		else
			ft_printf("%i %i\n", p->besty, p->bestx);
		ft_get_information(p);
	}
	ft_get_new_pos(p);
	if (!ft_verif_border(p, 0))
		ft_right(p);
}

void		ft_right(t_filler *p)
{
	while (ft_verif_border(p, 3))
	{
		dprintf(3, "right\n");
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
		else
			ft_printf("%i %i\n", p->besty, p->bestx);
		ft_get_information(p);
	}
	ft_get_new_pos(p);
	if (!ft_verif_border(p, 3))
		ft_left(p);
}

void		ft_left(t_filler *p)
{
	while (ft_verif_border(p, 1))
	{
		dprintf(3, "left\n");
		p->bestx = p->x;
		while (p->myposy != p->y)
		{
			ft_placepiece_spe(p);
			if (p->myposx < p->bestx && p->myposy != p->y)
			{
				p->bestx = p->myposx;
				p->besty = p->myposy;
			}
		}
		if (p->bestx == p->x)
			ft_merde(p);
		else
			ft_printf("%i %i\n", p->besty, p->bestx);
		ft_get_information(p);
	}
	ft_get_new_pos(p);
	dprintf(3, "%i %i %i %i\n",ft_verif_border(p , 1) ,ft_verif_border(p, 0), ft_verif_border(p, 2) ,ft_verif_border(p, 3));
	if (!ft_verif_border(p , 1) && !ft_verif_border(p, 0) &&
			!ft_verif_border(p, 2) && !ft_verif_border(p, 3))
		ft_complete(p);
	if (!ft_verif_border(p, 1))
		ft_bottom(p);
}

void		ft_bottom(t_filler *p)
{
	while (ft_verif_border(p, 2))
	{
		dprintf(3, "left\n");
		p->besty = -p->piecey;
		while (p->myposy != p->y)
		{
			ft_placepiece_spe(p);
			if (p->myposy > p->besty && p->myposy != p->y)
			{
				p->bestx = p->myposx;
				p->besty = p->myposy;
			}
		}
		if (p->besty == -p->piecey)
			ft_merde(p);
		else
			ft_printf("%i %i\n", p->besty, p->bestx);
		ft_get_information(p);
	}
	ft_get_new_pos(p);
	if (!ft_verif_border(p, 2))
		ft_up(p);
}
