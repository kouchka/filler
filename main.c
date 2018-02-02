/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:19:50 by allallem          #+#    #+#             */
/*   Updated: 2018/02/01 18:59:41 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_init_struct(t_filler *p)
{
	p->point = 0;
	p->playerone = 0;
	p->playertwo = 0;
	p->x = 0;
	p->y = 0;
	p->limity = 0;
	p->posxx = 0;
	p->posxy = 0;
	p->posox = 0;
	p->posoy = 0;
	p->symbol = 'Z';
}

int			main(void)
{
	t_filler	st;
	t_filler	*p;
	char		*str;

	p = &st;
	ft_init_struct(p);
	if (!ft_threat_fd(p))
	{
		ft_putstr("Error on player assignement!\n");
		return (0);
	}
	get_next_line(0, &str);
	free(str);
	if (!ft_create_map(p))
		return (0);
	if (!ft_read(p))
	{
		ft_putstr("Error on map!\n");
		return (0);	
	}
	printf("13 15\n");
	ft_filler(p);
	return (0);
}
