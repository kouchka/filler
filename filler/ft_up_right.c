/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 08:57:05 by allallem          #+#    #+#             */
/*   Updated: 2018/02/10 15:58:26 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_init_best(t_filler *p)
{
	p->myposx = -p->piecex;
	p->myposy = -p->piecey;
	p->bestx = p->x;
	p->besty = -p->piecey;
}

static void	ft_redirection_up_right(t_filler *p)
{
	while (1)
	{
		ft_lfennemie(p);
		ft_lfmylast(p);
		if (p->posenx > p->myposx && p->poseny > p->myposy)
			ft_bottom(p);
		else if (p->posenx < p->myposx && p->poseny > p->myposy)
			ft_up(p);
		else if (p->posenx > p->myposx && p->poseny < p->myposy)
			ft_right(p);
		else if (p->posenx < p->myposx && p->poseny < p->myposy)
			ft_left(p);
		else
		{
			ft_place_piece(p);
			ft_printf("%i %i\n", p->myposy, p->myposx);
		}
	}
}

void		ft_up_right(t_filler *p)
{
	ft_init_best(p);
	if (ft_check_around_mid(p))
	{
		while (p->myposy != p->y)
		{
			ft_place_piece(p);
			if ((p->myposx < p->bestx || p->myposy > p->besty)
					&& p->myposy != p->y)
			{
				p->bestx = p->myposx;
				p->besty = p->myposy;
			}
		}
	}
	if (p->bestx != p->x && p->besty != -p->piecey)
		ft_printf("%i %i\n", p->besty, p->bestx);
	else
		ft_redirection_up_right(p);
}
