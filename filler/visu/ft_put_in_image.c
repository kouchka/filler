/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_in_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:57:49 by allallem          #+#    #+#             */
/*   Updated: 2018/02/13 18:39:35 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	ft_get_color(int color, int *r, int *v, int *b)
{
	*r = color % 16;
	color /= 16;
	*r += color % 16 * 10;
	color /= 16;
	*v = color % 16;
	color /= 16;
	*v += color % 16 * 10;
	color /= 16;
	*b = color % 16;
	color /= 16;
	*b += color % 16 * 10;
	color /= 16;
}

void		ft_put_in_image(t_visu *p, int x, int y, int color)
{
	int r;
	int v;
	int b;

	r = 0;
	v = 0;
	b = 0;
	ft_get_color(color, &r, &v, &b);
	p->data[(x * (p->bpp / 8)) + (y * p->size_line)] = r;
	p->data[(x * (p->bpp / 8)) + (y * p->size_line) + 1] = v;
	p->data[(x * (p->bpp / 8)) + (y * p->size_line) + 2] = b;
}
