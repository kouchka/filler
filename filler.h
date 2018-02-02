/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:22:18 by allallem          #+#    #+#             */
/*   Updated: 2018/02/01 16:28:57 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct	s_filler
{
	int			piecex;
	int			piecey;
	char		symbol;
	char		**map;
	char		**piece;
	int			x;
	int			y;
	int			point;
	int			playerone;
	int			playertwo;
	int			limity;
	int			posxx;
	int			posxy;
	int			posox;
	int			posoy;
}				t_filler;

int				ft_threat_fd(t_filler *p);
int				ft_read(t_filler *p);
void			ft_filler(t_filler *p);
int				ft_create_map(t_filler *p);
int				ft_get_piece(t_filler *p);
void			ft_place_piece(t_filler *p);
void			ft_update_map(t_filler *p);

#endif
