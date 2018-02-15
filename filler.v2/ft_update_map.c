/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:16:16 by allallem          #+#    #+#             */
/*   Updated: 2018/02/11 13:54:34 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_check_str(t_filler *p, char *str, int j, int i)
{
	if (str[j] == 'X' && p->map[i][j - 4] == 'x')
		p->map[i][j - 4] = 'X';
	else if (str[j] == 'X' && p->map[i][j - 4] == '.')
		p->map[i][j - 4] = 'x';
	else if (str[j] == 'O' && p->map[i][j - 4] == '.')
		p->map[i][j - 4] = 'o';
	else if (str[j] == 'O' && p->map[i][j - 4] == 'o')
		p->map[i][j - 4] = 'O';
}

void		ft_update_map(t_filler *p)
{
	char	*str;
	int		i;
	int		j;

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
		free(str);
		i++;
	}
}
