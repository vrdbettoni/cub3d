# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/13 15:21:57 by vroth-di     #+#   ##    ##    #+#        #
#    Updated: 2019/12/10 22:52:43 by vroth-di    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-g -Wall -Wextra -Werror

LFLAGS	=	-I $(HEADER)

HEADER	=	./header

NAME	=	libftprintf.a

SRCS	=	sources/ft_printf.c\
			sources/printf_utils.c\
			sources/conversion_1.c\
			sources/conversion_2.c\

OBJ		=	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJ)
			@make -C ./libft
			@cd libft && mv libft.a ../
			@ar rcs libft.a $(OBJ)
			@mv libft.a libftprintf.a

%.o: 		%.c $(HEADER)
			@$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

clean:
			@rm -rf $(OBJ)
			@cd libft && make clean

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		all fclean clean re
