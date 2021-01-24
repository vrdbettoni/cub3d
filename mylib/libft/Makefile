# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/11 16:51:50 by vroth-di     #+#   ##    ##    #+#        #
#    Updated: 2019/11/22 06:44:55 by vroth-di    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-g -Wall -Wextra -Werror

LFLAGS	=	-I $(HEADER)

HEADER	=	../header

NAME	=	libft.a

SRCS	=	ft_atoi.c\
	 		ft_bzero.c\
	 		ft_calloc.c\
	 		ft_isalnum.c\
	 		ft_isalpha.c\
	 		ft_isascii.c\
	 		ft_isdigit.c\
	 		ft_isprint.c\
	 		ft_itoa.c\
	 		ft_memccpy.c\
	 		ft_memchr.c\
	 		ft_memcmp.c\
	 		ft_memcpy.c\
	 		ft_memmove.c\
	 		ft_memset.c\
	 		ft_putchar_fd.c\
	 		ft_putendl_fd.c\
	 		ft_putnbr_fd.c\
	 		ft_putstr_fd.c\
	 		ft_split.c\
	 		ft_strchr.c\
	 		ft_strdup.c\
	 		ft_strjoin.c\
	 		ft_strlcat.c\
	 		ft_strlcpy.c\
	 		ft_strlen.c\
	 		ft_strmapi.c\
	 		ft_strncmp.c\
	 		ft_strnstr.c\
	 		ft_strrchr.c\
	 		ft_strtrim.c\
	 		ft_substr.c\
	 		ft_tolower.c\
	 		ft_toupper.c\
			ft_atoi_ll.c\
			ft_putnbr_ll.c\
			ft_itoa_ll.c\
			ft_itoa_base.c\
			ft_lstadd_back_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstnew_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstmap_bonus.c\
			ft_putnbr_base.c\
			get_next_line.c\
			get_next_line_utils.c\
			ft_realloc.c\
			ft_is_whitespaces.c\
			search.c\
			ft_lerpi.c\

OBJ		=	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJ)
			@ar rcs $(NAME) $(OBJ)

%.o: 		%.c $(HEADER)
			@$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

clean:
			@rm -f $(OBJ) $(OBJS)

fclean: 	clean
			@rm -f $(NAME)

re : 		fclean all

.PHONY: 	all fclean clean re bonus
