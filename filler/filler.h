	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:22:18 by allallem          #+#    #+#             */
/*   Updated: 2018/02/10 17:21:22 by allallem         ###   ########.fr       */
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
	int			playerx;
	int			playery;
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
void			ft_placepiece_spe(t_filler *p);
void			ft_lfmylast(t_filler *p);
int				ft_verif_border(t_filler *p, int i);
void			ft_jump(char *str);
void			ft_get_information(t_filler *p);
void			ft_reinit(t_filler *p);
void			ft_get_new_pos(t_filler *p);
void			ft_complete(t_filler *p);

#endif
