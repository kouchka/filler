/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:09:31 by allallem          #+#    #+#             */
/*   Updated: 2018/02/09 02:22:11 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_reinit(t_filler *p)
{
		p->contact = 0;
		p->value = 0;
}

static int		ft_check_x(t_filler *p, int *i, int *j)
{
	while (p->piece[*i][*j] == '.')
		*j = *j + 1;
	if ((p->myposx + *j >= p->x || p->myposx + *j < 0 || p->myposy + *i < 0)
			&& p->piece[*i][*j] == '*')
		return (0);
	if (p->piece[*i][*j] == '*' && (p->map[p->myposy + *i][p->myposx + *j]
	== p->symbol || p->map[p->myposy + *i][p->myposx + *j] == p->symbol + 32
	|| p->map[p->myposy + *i][p->myposx + *j] == '.'))
	{
		if ((p->map[p->myposy + *i][p->myposx + *j] == p->symbol)
			|| (p->map[p->myposy + *i][p->myposx + *j] == p->symbol + 32))
			p->contact++;
		p->value++;
	}
	if (p->piece[*i][*j] != '\0')
		*j = *j + 1;
	return (1);
}

static int		ft_checkplace(t_filler *p)
{
	int i;
	int j;

	i = 0;
	while (p->piece[i])
	{
		j = 0;
		if (p->myposy + i >= p->y)
			return (0);
		while (p->piece[i][j])
		{
			if (!ft_check_x(p, &i, &j))
				return (0);
		}
		i++;
	}
	return (1);
}

int				ft_check_if_ok(t_filler *p)
{
	if ((p->contact == 1 && p->value == p->size) || p->myposy == p->y)
		return (1);
	return (0);
}

void			ft_place_piece(t_filler *p)
{
	int		i;

	i = 0;
	ft_checkplace(p);
	while (!ft_check_if_ok(p))
	{
		ft_reinit(p);
		if (p->myposx < p->x)
			p->myposx++;
		else
		{
			p->myposx = 0 - p->piecex;
			p->myposy++;
		}
		ft_checkplace(p);
	}
}
