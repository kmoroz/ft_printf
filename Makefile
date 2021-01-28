# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ksmorozo <ksmorozo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/18 14:53:34 by ksmorozo      #+#    #+#                  #
#    Updated: 2021/01/28 15:20:24 by ksmorozo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJ_FILES = ft_printf.o
HEADER_FILES = ft_printf.h

PARSE_DIR = parser/
PARSE_OBJ_FILES = parse.o \
parse_flag.o parse_width.o \
parse_length.o parse_precision.o \
parse_type.o

PROCESSOR_DIR = processor/
PROCESSOR_OBJ_FILES = print.o \
print_char.o write_padding.o \
print_hex.o

LIBFT_DIR = libft/
LIBFT =	libft.a

CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES) $(addprefix $(PARSE_DIR), $(PARSE_OBJ_FILES)) \
$(addprefix $(PROCESSOR_DIR), $(PROCESSOR_OBJ_FILES))
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rc $@ $^
	ranlib $@

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(addprefix $(PARSE_DIR), $(PARSE_OBJ_FILES)) \
$(addprefix $(PROCESSOR_DIR), $(PROCESSOR_OBJ_FILES))
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT_DIR)/$(LIBFT)

re:
	fclean all

.PHONY: all clean fclean re
