/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:54:27 by allallem          #+#    #+#             */
/*   Updated: 2018/02/01 16:05:32 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_free_piece(t_filler *p)
{
	int i;

	i = 0;
	while (p->piece[i])
	{
		free(p->piece[i]);
		i++;
	}
	free(p->piece);
}

static int	ft_create_piece(t_filler *p)
{
	int i;
	int j;

	i = 0;
	if (!(p->piece = (char**)malloc(sizeof(char*) * p->piecey + 1)))
		return (0);
	p->piece[p->piecey] = 0;
	while (i < p->piecey)
	{
		j = 0;
		if (!(p->piece[i] = (char*)malloc(sizeof(char) * p->piecex + 1)))
			return (0);
		while (j < p->piecex)
		{
			p->piece[i][j] = '.';
			j++;
		}
		p->piece[i][j] = '\0';
		i++;
	}
	return (1);
}

static int	ft_fill_piece(t_filler *p, char *str)
{
	int i;
	int j;

	i = 0;
	while (i < p->piecey)
	{
		j = 0;
		if (get_next_line(0, &str) < 0)
			return (0);
		while (j < p->piecex)
		{
			if (str[j] == '*')
				p->piece[i][j] = '*';
			j++;
		}
		free(str);
		i++;
	}
	return (1);
}

int			ft_get_piece(t_filler *p)
{
	char	*str;
	int		i;

	i = 0;
	get_next_line(0, &str);
	while (ft_strstr_int("Piece ", str[i]))
		i++;
	p->piecex = ft_atoi(str + i);
	while (ft_strstr_int("0123456789", str[i]))
		i++;
	p->piecey = ft_atoi(str + i);
	if (p->piece)
		ft_free_piece(p);
	if (!ft_create_piece(p))
		return (0);
	free(str);
	ft_fill_piece(p, str);
	return (1);
}
