/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:46:31 by allallem          #+#    #+#             */
/*   Updated: 2018/02/14 17:13:13 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void			ft_reset_img(t_visu *p)
{
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, 1920, 1080);
}

void			ft_complete_map_spe(t_visu *p, t_img *s)
{
	int i;
	int j;

	i = 0;
	while (i < p->y)
	{
		j = 4;
		while (s->map[j] && j < p->x + 4)
		{
			if (s->map[i][j] == 'O')
				ft_complete_case(p, j - 4, i, 0);
			else if (s->map[i][j] == 'o')
				ft_complete_case(p, j - 4, i, 1);
			else if (s->map[i][j] == 'x')
				ft_complete_case(p, j - 4, i, 2);
			else if (s->map[i][j] == 'X')
				ft_complete_case(p, j - 4, i, 3);
			j++;
		}
		i++;
	}
}

static void		ft_init_map(t_visu *p, t_img *s)
{
	if (!(s->map = (char **)malloc(sizeof(char *) * p->y + 1)))
		exit(EXIT_SUCCESS);
	s->map[p->y] = 0;
}

int				ft_complete_map(t_visu *p, t_img *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (s != NULL)
		ft_init_map(p, s);
	while (i < p->y)
	{
		j = 4;
		if (!get_next_line(0, &str))
			return (0);
		if (s != NULL)
			s->map[i] = ft_strdup(str);
		while (str[j] && j < p->x + 4)
		{
			if (str[j] == 'O')
				ft_complete_case(p, j - 4, i, 0);
			else if (str[j] == 'o')
				ft_complete_case(p, j - 4, i, 1);
			else if (str[j] == 'x')
				ft_complete_case(p, j - 4, i, 2);
			else if (str[j] == 'X')
				ft_complete_case(p, j - 4, i, 3);
			j++;
		}
		i++;
	}
	return (1);
}
