/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 09:34:02 by allallem          #+#    #+#             */
/*   Updated: 2018/02/12 18:36:51 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_verif_width(t_filler *p, int i)
{
	int j;

	j = 0;
	while (p->map[j])
	{
		if (j + 1 < p->y)
		{
			if (p->map[j + 1][i] != p->other
			&& (p->map[j][i] == p->symbol || p->map[j][i] == p->symbol + 32))
				return (0);
		}
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
		if (j + 1 < p->x)
		{
			if (p->map[i][j + 1] != p->other
			&& (p->map[i][j] == p->symbol || p->map[i][j] == p->symbol + 32))
				return (0);
		}
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
