#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allallem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 18:42:15 by allallem          #+#    #+#              #
#    Updated: 2018/02/01 16:29:16 by allallem         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	allallem.filler

SRCS	= main.c ft_threat_fd.c ft_filler.c ft_create_map.c ft_get_piece.c ft_update_map.c

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