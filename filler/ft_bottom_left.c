/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bottom_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 06:23:53 by allallem          #+#    #+#             */
/*   Updated: 2018/02/09 03:55:34 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

static void		ft_init_best(t_filler *p)
{
	p->myposx = -p->piecex;
	p->myposy = -p->piecey;
	p->bestx = -p->piecex;
	p->besty = p->y;
}

void			ft_bottom_left(t_filler *p)
{
	ft_init_best(p);
	if (ft_check_around_mid(p))
	{
		while (p->myposy != p->y)
		{
			ft_place_piece(p);
			if ((p->myposx > p->bestx || p->myposy < p->besty)
					&& p->myposy != p->y)
			{
				p->bestx = p->myposx;
				p->besty = p->myposy;
			}
		}
	}
	if (p->bestx != -p->piecex && p->besty != p->y)
		ft_printf("%i %i\n", p->besty, p->bestx);
//	else
//		ft_redirection(p);
}
