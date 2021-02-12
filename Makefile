# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ksmorozo <ksmorozo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/18 14:53:34 by ksmorozo      #+#    #+#                  #
#    Updated: 2021/02/12 15:33:15 by ksmorozo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_FILE = ft_printf.c
HEADER_FILES = ft_printf.h

PARSE_DIR = parser/
PARSE_SRC_FILES = parse.c \
parse_flag.c parse_width.c \
parse_length.c parse_precision.c \
parse_type.c

PROCESSOR_DIR = processor/
PROCESSOR_SRC_FILES = print.c \
print_char.c write_padding.c \
print_hex.c count_num_length.c \
print_d_i_u.c print_percent.c \
print_ptr.c print_str.c \
print_d_i_u_utils.c print_hex_utils.c

LIBFT_DIR = libft/
LIBFT =	libft.a

CFLAGS = -g -Wall -Wextra -Werror

OBJ_FILES = $(SRC_FILE:.c=.o) \
$(addprefix $(PARSE_DIR), $(PARSE_SRC_FILES:.c=.o)) \
$(addprefix $(PROCESSOR_DIR), $(PROCESSOR_SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	ar rc $@ $^
	ranlib $@

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT_DIR)$(LIBFT)

re: fclean all

.PHONY: all clean fclean re
