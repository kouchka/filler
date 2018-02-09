/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:16:16 by allallem          #+#    #+#             */
/*   Updated: 2018/02/09 08:00:34 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_check_around_mid(t_filler *p)
{
	int i;
	int j;

	i = p->posmidy - p->y / 10;
	while (i < p->posmidy + p->y / 10)
	{
		j = p->posmidx - p->x / 10;
		while (j < p->posmidx + p->x / 10)
		{
			if (p->map[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_check_str(t_filler *p, char *str, int j, int i)
{
	if ((str[j] == 'X' && p->map[i][j - 4] == 'x')
			|| (p->symbol == 'X' && str[j] == 'X'))
		p->map[i][j - 4] = 'X';
	else if (str[j] == 'X' && p->map[i][j - 4] == '.')
		p->map[i][j - 4] = 'x';
	else if (str[j] == 'O' && p->map[i][j - 4] == '.')
		p->map[i][j - 4] = 'o';
	else if ((str[j] == 'O' && p->map[i][j - 4] == 'o')
			|| (p->symbol == 'O' && str[j] == 'O'))
		p->map[i][j - 4] = 'O';
}

void		ft_update_map(t_filler *p)
{
	char *str;
	int i;
	int j;

	i = 0;
	while (i < p->y)
	{
		j = 0;
		get_next_line(0, &str);
		while (j < p->x + 4)
		{
			ft_check_str(p, str, j, i);
			j++;
		}
		dprintf(3, "%s\n", p->map[i]);
		free(str);
		i++;
	}
}
