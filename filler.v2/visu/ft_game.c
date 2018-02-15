/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:57:21 by allallem          #+#    #+#             */
/*   Updated: 2018/02/14 17:31:00 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		ft_keep_data(t_img *s)
{
	t_img	*new;

	if (!(new = malloc(sizeof(t_img))))
		exit(EXIT_SUCCESS);
	s->next = new;
	new->previous = s;
	new->next = NULL;
}

int				ft_go_to_tab(char *str)
{
	while (ft_strncmp("    0", str, 5) != 0)
	{
		free(str);
		if (!get_next_line(0, &str))
			return (0);
	}
	free(str);
	return (1);
}

static int	ft_read_forward_backward(t_visu *p, t_img *s)
{
	ft_reset_img(p);
	ft_complete_map_spe(p, s);
	if (p->read == 1)
		mlx_put_image_to_window(p->mlx, p->window, p->img, 0, 0);
	else
		mlx_put_image_to_window(p->mlx, p->window, p->img, 0, 0);
	return (0);
}

int			ft_game(t_visu *p)
{
	char			*str;
	static t_img	*s = NULL;

	if (p->pause == 0 && p->read == 0)
	{
		if (s == NULL)
		{
			if (!(s = malloc(sizeof(t_img))))
				exit(EXIT_SUCCESS);
			ft_bzero(s, sizeof(t_img));
		}
		while (s->next != NULL)
			s = s->next;
		printf("hunhun\n");
		ft_keep_data(s);
		if (get_next_line(0, &str))
		{
			if (!ft_go_to_tab(str))
				return (0);
			ft_complete_map(p, s);
			mlx_put_image_to_window(p->mlx, p->window, p->img, 0, 0);
			return (0);
		}
		s = s->next;
		p->pause = 1;
	}
	if (p->read == 1)
	{
		if (s->next != NULL)
			s = s->next;
		if (s->next == NULL)
		{
			p->read = 0;
			p->pause = 0;
			return (0);
		}
		return (ft_read_forward_backward(p, s));
	}
	else if (p->read == -1)
	{
		if (s->previous != NULL)
			s = s->previous;
		return (ft_read_forward_backward(p, s));
	}
	if (p->pause == 1)
		return (0);
	return (1);
}
