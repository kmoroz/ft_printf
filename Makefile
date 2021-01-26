# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ksmorozo <ksmorozo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/18 14:53:34 by ksmorozo      #+#    #+#                  #
#    Updated: 2021/01/26 18:34:47 by ksmorozo      ########   odam.nl          #
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
print_char.o write_padding.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES) $(addprefix $(PARSE_DIR), $(PARSE_OBJ_FILES)) \
$(addprefix $(PROCESSOR_DIR), $(PROCESSOR_OBJ_FILES))
	ar rc $@ $^
	ranlib $@

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(addprefix $(PARSE_DIR), $(PARSE_OBJ_FILES)) \
$(addprefix $(PROCESSOR_DIR), $(PROCESSOR_OBJ_FILES))

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
