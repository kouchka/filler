/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:57:21 by allallem          #+#    #+#             */
/*   Updated: 2018/02/13 19:21:02 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			ft_go_to_tab(char *str)
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

int			ft_game(t_visu *p)
{
	char *str;

	if (get_next_line(0, &str))
	{
		if (!ft_go_to_tab(str))
			return (0);
		ft_complete_map(p);
		mlx_put_image_to_window(p->mlx, p->window, p->img, 0, 0);
		return (0);
	}
	return (1);
}
