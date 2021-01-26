# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ksmorozo <ksmorozo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/18 14:53:34 by ksmorozo      #+#    #+#                  #
#    Updated: 2021/01/26 14:44:11 by ksmorozo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJ_FILES = ft_printf.o
HEADER_FILES = ft_printf.h
CFLAGS = -Wall -Wextra -Werror

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

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
