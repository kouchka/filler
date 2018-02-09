/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 04:45:35 by allallem          #+#    #+#             */
/*   Updated: 2018/02/09 07:28:51 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_init_best(t_filler *p)
{
	p->myposx = -p->piecex;
	p->myposy = -p->piecey;
	p->bestx = -p->piecex;
	p->besty = -p->piecey;
}

void		ft_redirection_up_left(t_filler *p)
{
	ft_lfennemie(p);
	dprintf(3, "%i %i %c\n", p->poseny, p->posenx, p->other);
	if (p->posenx > p->myposx && p->poseny > p->myposy)
	{
		dprintf(3, "up\n");
		ft_up(p);
	}
	else if (p->posenx < p->myposx && p->poseny > p->myposy)
	{
		dprintf(3, "left\n");
		ft_left(p);
	}
	else if (p->posenx > p->myposx && p->poseny < p->myposy)
	{
		dprintf(3, "bottom\n");
		ft_bottom(p);
	}
	else if (p->posenx < p->myposx && p->poseny < p->myposy)
	{
		dprintf(3, "right\n");
		ft_right(p);
	}
	else
		ft_place_piece(p);
	dprintf(3, "%i %i\n", p->besty, p->bestx);
	ft_printf("%i %i\n", p->besty, p->bestx);
}

void		ft_up_left(t_filler *p)
{
	ft_init_best(p);
	if (ft_check_around_mid(p))
	{
		while (p->myposy != p->y)
		{
			ft_place_piece(p);
			if ((p->myposx > p->bestx || p->myposy > p->besty)
					&& p->myposy != p->y)
			{
				p->bestx = p->myposx;
				p->besty = p->myposy;
			}
		}
	}
	if (p->bestx != -p->piecex && p->besty != -p->piecey)
		ft_printf("%i %i\n", p->besty, p->bestx);
	else
		ft_redirection_up_left(p);
}
