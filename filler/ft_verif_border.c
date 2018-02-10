/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 09:34:02 by allallem          #+#    #+#             */
/*   Updated: 2018/02/10 17:09:34 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_get_information(t_filler *p)
{
	char *str;

	p->bestx = -p->piecex;
	p->besty = -p->piecey;
	if (!get_next_line(0, &str))
		exit(EXIT_SUCCESS);
	ft_reinit(p);
	ft_jump(str);
	ft_update_map(p);
	ft_get_piece(p);
	ft_lfennemie(p);
	ft_lfmylast(p);
}

static int	ft_verif_width(t_filler *p, int i)
{
	int j;

	j = 0;
	while (p->map[j])
	{
		if (p->map[j][i] == p->symbol || p->map[j][i] == p->symbol + 32)
			return (0);
		j++;
	}
	return (1);
}

static int	ft_verif_lenght(t_filler *p, int i)
{
	int j;

	j = 0;
	while (p->map[i][j])
	{
		if (p->map[i][j] == p->symbol || p->map[i][j] == p->symbol + 32)
			return (0);
		j++;
	}
	return (1);
}

int			ft_verif_border(t_filler *p, int i)
{
	if (i == 0)
		return (ft_verif_lenght(p, 0));
	else if (i == 1)
		return (ft_verif_width(p, 0));
	else if (i == 2)
		return (ft_verif_lenght(p, p->y - 1));
	else if (i == 3)
		return (ft_verif_width(p, p->x - 1));
	return (-1);
}
