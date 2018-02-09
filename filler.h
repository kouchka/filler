	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:22:18 by allallem          #+#    #+#             */
/*   Updated: 2018/02/09 04:41:50 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct	s_filler
{
	int			size;
	int			piecex;
	int			piecey;
	char		symbol;
	char		other;
	char		**map;
	char		**piece;
	int			x;
	int			y;
	int			point;
	int			playerone;
	int			playertwo;
	int			limity;
	int			myposx;
	int			myposy;
	int			posxx;
	int			posxy;
	int			posox;
	int			posoy;
	int			value;
	int			contact;
	int			posenx;
	int			poseny;
	int			posmidx;
	int			posmidy;
	int			bestx;
	int			besty;
}				t_filler;

int				ft_threat_fd(t_filler *p);
int				ft_read(t_filler *p);
void			ft_filler(t_filler *p);
int				ft_create_map(t_filler *p);
int				ft_get_piece(t_filler *p);
void			ft_place_piece(t_filler *p);
void			ft_update_map(t_filler *p);
void			ft_place_piece(t_filler *p);
void			ft_intelligent_placement(t_filler *p);
void			ft_up_left(t_filler *p);
void			ft_bottom_left(t_filler *p);
void			ft_bottom_right(t_filler *p);
void			ft_up_right(t_filler *p);
int				ft_check_around_mid(t_filler *p);
void			ft_up(t_filler *p);
void			ft_right(t_filler *p);
void			ft_left(t_filler *p);
void			ft_bottom(t_filler *p);
void			ft_lfennemie(t_filler *p);

#endif
