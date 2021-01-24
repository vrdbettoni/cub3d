# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/20 14:19:27 by vroth-di     #+#   ##    ##    #+#        #
#    Updated: 2019/12/12 03:44:44 by vroth-di    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

HEADER	=	./X11/include/mlx.h\
			./header/cub3d.h\

LIB		=	./X11/lib\
			./mylib/libftprintf.a\

NAME	=	cub3D

SRCS	=	./parsing/error.c\
			./parsing/parsing_cub.c\
			./parsing/parsing_map.c\
			./parsing/parsing_error.c\
			./sources/mlx.c\
			./sources/draw.c\
			./sources/loop.c\
			./sources/image.c\
			./sources/sprite.c\
			./sources/mouvements.c\
			./sources/save_bmp.c\
			./sources/exit.c\

OBJ		=	$(SRCS:.c=.o)

%.o: 		%.c $(HEADER)
			@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C ./mylib
			@$(CC) $(CFLAGS) -o cub3D -L $(LIB)  -l mlx -framework OpenGL -framework AppKit $(OBJ) ./sources/main.c
			@echo "\x1b[32;01mproject compile\x1b[0m"

clean:
			@cd mylib && make clean
			@rm -f $(OBJ)
			@echo "\x1b[33;01m.o are deleted\x1b[0m"

fclean:		clean
			@cd mylib && make fclean
			@rm -f ./a.out
			@rm -rf ./a.out.dSYM/
			@rm -f $(NAME)
			@echo "\x1b[31;01mproject deleted\x1b[0m"

re:			fclean all

.PHONY:		all fclean re bonus
