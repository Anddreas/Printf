# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: handrias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 15:34:51 by handrias          #+#    #+#              #
#    Updated: 2023/05/22 15:34:53 by handrias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libftprintf.a

CC =cc

CFLAGS= #-Wall -Wextra -Werror

SRCS =  ft_printf.c		\
		ft_printf_hex.c	\
		putchar1.c	\

OBJS        = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@ar -r $(NAME) $(OBJS)

all : $(NAME)
fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJS)

re: fclean all

.PHONY: all clean fclean re