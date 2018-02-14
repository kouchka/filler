/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:46:31 by allallem          #+#    #+#             */
/*   Updated: 2018/02/13 19:19:51 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int				ft_complete_map(t_visu *p)
{
	int i;
	int j;
	char *str;

	i = 0;
	while (i < p->y)
	{
		j = 4;
		if (!get_next_line(0, &str))
			return (0);
		while (str[j] && j < p->x + 4)
		{
			if (str[j] == 'o' || str[j] == 'O')
				ft_complete_case(p, j - 4, i, 0);
			else if (str[j] == 'x' || str[j] == 'X')
				ft_complete_case(p, j - 4, i, 1);
			j++;
		}
		free(str);
		i++;
	}
	return (1);
}
