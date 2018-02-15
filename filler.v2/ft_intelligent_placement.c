/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intelligent_placement.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 00:32:40 by allallem          #+#    #+#             */
/*   Updated: 2018/02/12 18:39:49 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_init_pos(t_filler *p)
{
	p->mu = p->y;
	p->eu = p->y;
	p->er = 0;
	p->mr = 0;
	p->el = p->x;
	p->ml = p->x;
	p->eb = 0;
	p->mb = 0;
}

static void	ft_search(t_filler *p, int i, int j)
{
	if ((p->map[i][j] == p->other || p->map[i][j] == p->other + 32)
			&& i < p->eu)
		p->eu = i;
	if ((p->map[i][j] == p->other || p->map[i][j] == p->other + 32)
			&& j > p->er)
		p->er = j;
	if ((p->map[i][j] == p->other || p->map[i][j] == p->other + 32)
			&& i > p->eb)
		p->eb = i;
	if ((p->map[i][j] == p->other || p->map[i][j] == p->other + 32)
			&& j < p->el)
		p->el = j;
	if ((p->map[i][j] == p->symbol || p->map[i][j] == p->symbol + 32)
			&& j < p->ml)
		p->ml = j;
	if ((p->map[i][j] == p->symbol || p->map[i][j] == p->symbol + 32)
			&& i < p->mu)
		p->mu = i;
	if ((p->map[i][j] == p->symbol || p->map[i][j] == p->symbol + 32)
			&& i > p->mb)
		p->mb = i;
	if ((p->map[i][j] == p->symbol || p->map[i][j] == p->symbol + 32)
			&& j > p->mr)
		p->mr = j;
}

static void	ft_get_pos(t_filler *p)
{
	if (p->symbol == 'O')
	{
		p->playerx = p->posox;
		p->playery = p->posoy;
		p->myposx = p->posox;
		p->myposy = p->posoy;
		p->other = 'X';
	}
	else
	{
		p->playerx = p->posxx;
		p->playery = p->posxy;
		p->myposx = p->posxx;
		p->myposy = p->posxy;
		p->other = 'O';
	}
}

void		ft_lfennemie(t_filler *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_init_pos(p);
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			ft_search(p, i, j);
			j++;
		}
		i++;
	}
}

void		ft_intelligent_placement(t_filler *p)
{
	ft_get_pos(p);
	ft_lfennemie(p);
	p->myposx = 0;
	p->myposy = 0;
	if (p->eu - 5 > p->mu && p->er + 5 > p->mr && p->eu != p->mu && p->er
			!= p->mr && ft_verif_border(p, 0) && ft_verif_border(p, 3))
		ft_up_right(p);
	else if (p->eu - 5 < p->mu && p->el - 5 < p->ml && p->eu != p->mu && p->el
			!= p->ml && ft_verif_border(p, 0) && ft_verif_border(p, 2))
		ft_up_left(p);
	else if (p->eb + 5 > p->mb && p->er + 5 > p->mr && p->eb != p->mb && p->er
			!= p->mr && ft_verif_border(p, 2) && ft_verif_border(p, 3))
		ft_bottom_right(p);
	else if (p->eb + 5 > p->mb && p->el - 5 < p->ml && p->eb != p->mb && p->el
			!= p->ml && ft_verif_border(p, 2) && ft_verif_border(p, 2))
		ft_bottom_left(p);
	else
		ft_complete(p);
}
