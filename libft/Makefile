# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 16:02:11 by jfleisch          #+#    #+#              #
#    Updated: 2018/03/28 13:14:10 by jfleisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra -g

NORM = norminette -R CheckForbiddenSourceHeader

CC = gcc

NAME = libft.a
NAME2 = libft

RM = rm -rf

SRC = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_islower.c \
		ft_isprint.c \
		ft_isupper.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putchar.c \
		ft_putendl_fd.c \
		ft_putendl.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_putstr_fd.c \
		ft_putstr.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncpy.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstprint.c \
		ft_putstrarr.c \
		ft_strrep.c \
		ft_freestrarr.c \
		ft_atoi_base.c \
		ft_error.c \
		ft_exit.c \
		ft_countword.c \
		ft_lstapp.c \
		ft_error_unknown.c \
		get_next_line.c \
		ft_gnl.c \
		ft_strjoinfree.c \
		ft_strndup.c \
		ft_ltoa.c \
		ft_ltoa_base.c \
		ft_ultoa_base.c \
		ft_strrev.c \
		ft_strtoupper.c \
		ft_itoa_base.c \
		ft_wstrlen.c \
		ft_printf.c \
		ft_pow.c

OBJ = $(SRC:.c=.o)

EXT = $(IDIR)$(NAME:.a=.h)

LIBCOMPLEX = ./complex/libftcomplex.a

LIBPF = ./printf/libftprintf.a

IDIR = ./
ODIR = ./bin/

O = $(addprefix $(ODIR), $(OBJ))

all: $(LIBPF) $(NAME) # $(LIBCOMPLEX) extra_obj

$(LIBPF):
	@make -C ./printf

$(LIBCOMPLEX):
	@make -C ./complex

$(ODIR)%.o: %.c
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@

$(NAME): $(O) $(EXT)
	@echo "-> Creating archive $(NAME)...\n"
	@ar rc $(NAME) $(O)
	@ranlib $(NAME)

$(O): | ./bin

extra_obj:
	@mv *.o $(ODIR)

./bin:
	@mkdir $(ODIR)

clean:
	@echo "-> Cleaning $(NAME2) object files..."
	@$(RM) $(O)

fclean: clean
	@echo "-> Cleaning $(NAME)...\n"
	@$(RM) $(NAME)
	@make -C ./printf fclean

re: fclean all

norm:
	$(NORM)

.PHONY: all clean fclean re

