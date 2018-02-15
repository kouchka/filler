/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_in_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:57:49 by allallem          #+#    #+#             */
/*   Updated: 2018/02/15 10:04:20 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		ft_put_in_image(t_visu *p, int x, int y, int color)
{
	p->data[(x * (p->bpp / 8)) + (y * p->size_line)] =  color & 0xFF;
	p->data[(x * (p->bpp / 8)) + (y * p->size_line) + 1] = (color >> 8) & 0xFF;
	p->data[(x * (p->bpp / 8)) + (y * p->size_line) + 2] = (color >> 16) & 0xFF;
}
