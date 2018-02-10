/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intelligent_placement.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 00:32:40 by allallem          #+#    #+#             */
/*   Updated: 2018/02/10 08:27:57 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_get_mid_pos(t_filler *p)
{
	p->posmidx = p->x / 2;
	p->posmidy = p->y / 2;
}

static void	ft_get_pos(t_filler *p)
{
	if (p->symbol == 'O')
	{
		p->myposx = p->posox;
		p->myposy = p->posoy;
		p->posenx = p->posxx;
		p->poseny = p->posxy;
		p->other = 'X';
	}
	else
	{
		p->myposx = p->posxx;
		p->myposy = p->posxy;
		p->posenx = p->posox;
		p->poseny = p->posoy;
		p->other = 'O';
	}
}

void		ft_lfennemie(t_filler *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j] && p->map[i][j] != p->other + 32)
			j++;
		if (p->map[i][j] == p->other + 32)
		{
			p->posenx = j;
			p->poseny = i;
			return ;
		}
		i++;
	}
}

void		ft_intelligent_placement(t_filler *p)
{
	ft_get_pos(p);
	ft_get_mid_pos(p);
	if (p->playerx > p->x / 2 && p->playery < p->y / 2)
		ft_up_right(p);
	else if (p->playerx < p->x / 2 && p->playery > p->y / 2)
		ft_bottom_left(p);
	else if (p->playerx > p->x / 2 && p->playery > p->y / 2)
		ft_bottom_right(p);
	else if (p->playerx < p->x / 2 && p->playery < p->y / 2)
		ft_up_left(p);
}
