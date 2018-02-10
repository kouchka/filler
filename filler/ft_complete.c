/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:18:08 by allallem          #+#    #+#             */
/*   Updated: 2018/02/10 17:31:28 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_complete(t_filler *p)
{
	char *str;

	ft_reinit(p);
	ft_place_piece(p);
	ft_printf("%i %i\n", p->myposy, p->myposx);
	while (get_next_line(0, &str))
	{
		ft_reinit(p);
		ft_jump(str);
		ft_update_map(p);
		ft_get_piece(p);
		ft_place_piece(p);
		ft_printf("%i %i\n", p->myposy, p->myposx);
	}
	exit(EXIT_SUCCESS);
}
