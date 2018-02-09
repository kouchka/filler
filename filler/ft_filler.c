/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:44:23 by allallem          #+#    #+#             */
/*   Updated: 2018/02/07 05:26:55 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_reinit(t_filler *p)
{
		p->contact = 0;
		p->value = 0;
		p->myposx = 0;
		p->myposy = 0;
}

static void	ft_jump(char *str)
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
	while (get_next_line(0, &str))
	{
		ft_reinit(p);
		ft_jump(str);
		ft_update_map(p);
		ft_get_piece(p);
		ft_intelligent_placement(p);
	}
}
