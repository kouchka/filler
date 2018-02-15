/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:29:14 by allallem          #+#    #+#             */
/*   Updated: 2018/02/15 12:20:54 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "../libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct		s_visu
{
	void			*mlx;
	void			*window;
	void			*img;
	unsigned char	*data;
	char			**map;
	int				size_line;
	int				bpp;
	int				endian;
	int				pause;
	int				xmap;
	int				read;
	int				ymap;
	int				x;
	int				y;
	int				color;
	int				boeuf;
}					t_visu;

typedef struct		s_img
{
	struct s_img	*previous;
	struct s_img	*next;
	char			**map;
	int				stop;
}					t_img;

void				ft_put_in_image(t_visu *p, int x, int y, int color);
void				ft_complete_case(t_visu *p, int x, int y, int player);
int					ft_complete_map(t_visu *p, t_img *s);
int					ft_game(t_visu *p);
int					ft_go_to_tab(char *str);
void				ft_complete_map_spe(t_visu *p, t_img *s);
void				ft_reset_img(t_visu *p);

#endif
