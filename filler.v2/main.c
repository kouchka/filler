/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:19:50 by allallem          #+#    #+#             */
/*   Updated: 2018/02/12 18:41:08 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_init_struct(t_filler *p)
{
	ft_bzero(p, sizeof(t_filler));
	p->symbol = 'O';
}

int			main(void)
{
	t_filler	st;
	t_filler	*p;
	char		*str;

	p = &st;
	ft_init_struct(p);
	if (!ft_threat_fd(p))
		return (0);
	get_next_line(0, &str);
	free(str);
	if (!ft_create_map(p))
		return (0);
	if (!ft_read(p))
		return (0);
	ft_filler(p);
	return (0);
}
