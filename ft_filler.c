/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:44:23 by allallem          #+#    #+#             */
/*   Updated: 2018/02/01 18:48:34 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_filler(t_filler *p)
{
	char	*str;
	int		i;

	ft_get_piece(p);
	printf("ok\n");
//	ft_place_piece(p);
	while (get_next_line(0, &str))
	{
		i = 0;
		free(str);
		get_next_line(0, &str);
		free(str);
		ft_update_map(p);
		ft_get_piece(p);
		ft_printf("%i %i\n", p->posox, p->posoy);
	}
}
