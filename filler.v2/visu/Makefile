#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allallem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 18:42:15 by allallem          #+#    #+#              #
#    Updated: 2018/02/13 18:02:49 by allallem         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	allallem.visu

SRCS	=	main.c ft_put_in_image.c ft_complete_case.c ft_complete_map.c ft_game.c

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBX = -L minilibx_macos -lmlx -framework OpenGL -framework appKit

LIB = -L ../libft -lft
all		:	$(NAME)

$(NAME)	:	$(OBJS)
		make -C minilibx_macos
		make -C ../libft
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBX) $(LIB)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
