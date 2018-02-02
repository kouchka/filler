/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threat_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:21:45 by allallem          #+#    #+#             */
/*   Updated: 2018/02/01 18:56:45 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			ft_check_tab(t_filler *p)
{
	if (p->point != (p->x * p->y) - (p->playerone + p->playertwo))
		return (0);
	return (1);
}

static void		ft_incremente(char *str, t_filler *p, int *i)
{
	while (str[*i])
	{
		(str[*i] == '.') ? p->point++: 0;
		if (str[*i] == 'X')
		{
			p->posxx = *i - 4;
			p->posxy = p->limity;
			p->map[p->posxy][p->posxx] = 'X';
			p->playertwo++;
		}
		if (str[*i] == 'O')
		{
			p->posox = *i - 4;
			p->posoy = p->limity;
			p->map[p->posoy][p->posox] = 'O';
			p->playerone++;
		}
		*i = *i + 1;
	}
	p->limity++;
}

int			ft_read(t_filler *p)
{
	int i;
	char *str;

	i = 0;
	if (p->limity == p->y)
	{
		if (!ft_check_tab(p))
				return (0);
		return (1);
	}
	get_next_line(0, &str);
	while (ft_strstr_int("0123456789 ", str[i]))
		i++;
	ft_incremente(str, p, &i);
	free(str);
	if (i != p->x + 4)
		return (0);
	if (!ft_read(p))
		return (0);
	return (1);
}
int			ft_threat_fd(t_filler *p)
{
	char	*str;
	int		i;

	i = 0;
	get_next_line(0, &str);
	if (!ft_strncmp(str, "$$$ exec p1 : [../allallem.filler]", 34))
		p->symbol = 'O';
	else if (!ft_strncmp(str, "$$$ exec p2 : [../allallem.filler]", 34))
		p->symbol = 'X';
	free(str);
	get_next_line(0, &str);
	if (ft_strcmp(str, "Plateau ") &&
			ft_strlen(str) > 8 && str[ft_strlen(str) - 1] == ':')
	{
		p->y = ft_atoi(str + 8);
		p->x = ft_atoi(str + (9 + ft_sizeofint(p->y)));
	}
	else
		return (0);
	free(str);
	return (1);
}
