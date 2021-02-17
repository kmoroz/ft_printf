# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ksmorozo <ksmorozo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/10 19:37:56 by ksmorozo      #+#    #+#                  #
#    Updated: 2021/02/17 16:54:46 by ksmorozo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_FILES = ft_isdigit.c ft_isalpha.c \
ft_itoa_base.c ft_strlen.c \
ft_strcpy.c
HEADER_FILES = libft.h
CFLAGS = -g -Wall -Wextra -Werror
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $@ $^
	ranlib $@

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
