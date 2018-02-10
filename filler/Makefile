#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allallem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 18:42:15 by allallem          #+#    #+#              #
#    Updated: 2018/02/10 17:21:36 by allallem         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	allallem.filler

SRCS	= main.c ft_threat_fd.c ft_filler.c ft_create_map.c ft_get_piece.c ft_update_map.c ft_place_piece.c ft_intelligent_placement.c ft_up_left.c ft_bottom_left.c ft_bottom_right.c ft_up_right.c ft_direction.c ft_placepiece_spe.c ft_verif_border.c ft_get_new_pos.c ft_complete.c

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc

LIB		=	libft/libft.a

CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
