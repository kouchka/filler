/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:18:08 by allallem          #+#    #+#             */
/*   Updated: 2018/02/12 18:40:06 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_calc(t_filler *p, int i, int j)
{
	int valuex;
	int valuey;

	valuex = j - p->er;
	valuey = i - p->eu;
	if (valuex < 0)
		valuex *= -1;
	if (valuey < 0)
		valuey *= -1;
	valuex += valuey;
	if (valuex < p->ml)
	{
		p->ml = valuey;
		p->mu = i;
		p->mr = j;
	}
}

static void		ft_get_nearest_point(t_filler *p)
{
	int i;
	int j;

	i = 0;
	p->ml = p->x + p->y;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == p->symbol + 32 || p->map[i][j] == p->symbol)
				ft_calc(p, i, j);
			if (p->map[i][j] == p->symbol)
				p->map[i][j] = p->symbol + 32;
			j++;
		}
		i++;
	}
}

static void		ft_focus_ennemie(t_filler *p)
{
	int i;
	int j;

	i = 0;
	p->ml = p->y + p->x;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == p->other + 32)
			{
				p->er = j;
				p->eu = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void			ft_complete(t_filler *p)
{
	ft_reinit(p);
	ft_focus_ennemie(p);
	ft_get_nearest_point(p);
	p->ml = p->x + p->y;
	while (p->myposy < p->y)
	{
		ft_place_piece(p);
		if (((ft_abs(p->myposx - p->er) + ft_abs(p->myposy - p->eu)) < p->ml)
				&& p->myposy < p->y)
		{
			p->ml = ft_abs(p->myposx - p->er) + ft_abs(p->myposy - p->eu);
			p->bestx = p->myposx;
			p->besty = p->myposy;
		}
	}
	if (p->besty != -p->piecey && p->bestx != -p->piecex)
		ft_printf("%i %i\n", p->besty, p->bestx);
	else
	{
		ft_reinit(p);
		ft_place_piece(p);
		ft_printf("%i %i\n", p->myposy, p->myposx);
	}
}
