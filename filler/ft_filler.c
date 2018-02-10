/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:44:23 by allallem          #+#    #+#             */
/*   Updated: 2018/02/10 14:20:01 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_assign(t_filler *p)
{
	if (p->symbol == 'O')
	{
		p->playerx = p->posox;
		p->playery = p->posoy;
	}
	else
	{
		p->playerx = p->posxx;
		p->playery = p->posxy;
	}
}

void		ft_reinit(t_filler *p)
{
	p->contact = 0;
	p->value = 0;
	p->myposx = 0;
	p->myposy = 0;
}

void		ft_jump(char *str)
{
	while (ft_strncmp("    0", str, 5) != 0)
	{
		free(str);
		get_next_line(0, &str);
	}
	free(str);
}

void		ft_filler(t_filler *p)
{
	char	*str;

	ft_get_piece(p);
	ft_intelligent_placement(p);
	ft_assign(p);
	while (get_next_line(0, &str))
	{
		ft_reinit(p);
		ft_jump(str);
		ft_update_map(p);
		ft_get_piece(p);
		ft_intelligent_placement(p);
	}
}
