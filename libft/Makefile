# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaseaux <mcaseaux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 15:52:21 by mcaseaux          #+#    #+#              #
#    Updated: 2019/01/31 14:11:35 by mcaseaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_bzero.c\
			ft_memalloc.c\
			ft_memchr.c\
			ft_lstmap.c\
			ft_lstiter.c\
			ft_lstdel.c\
			ft_lstadd.c\
			ft_lstnew.c\
			ft_lstdelone.c\
			ft_memcmp.c\
			ft_memccpy.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_atoi.c\
			ft_itoa.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strncmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_btree_apply_by_level.c\
			ft_btree_apply_infix.c\
			ft_btree_apply_prefix.c\
			ft_btree_apply_suffix.c\
			ft_btree_create_node.c\
			ft_btree_insert_data.c\
			ft_btree_level_count.c\
			ft_btree_search_item.c\
			ft_strtrim.c\
			get_next_line.c

OBJS =	ft_isalnum.o\
			ft_isalpha.o\
			ft_isascii.o\
			ft_lstmap.o\
			ft_lstiter.o\
			ft_lstdel.o\
			ft_lstadd.o\
			ft_lstnew.o\
			ft_lstdelone.o\
			ft_isdigit.o\
			ft_isprint.o\
			ft_bzero.o\
			ft_memalloc.o\
			ft_memchr.o\
			ft_memcmp.o\
			ft_memccpy.o\
			ft_memcpy.o\
			ft_memdel.o\
			ft_memmove.o\
			ft_memset.o\
			ft_putchar.o\
			ft_putchar_fd.o\
			ft_putendl.o\
			ft_putendl_fd.o\
			ft_putnbr.o\
			ft_putnbr_fd.o\
			ft_putstr.o\
			ft_putstr_fd.o\
			ft_atoi.o\
			ft_itoa.o\
			ft_tolower.o\
			ft_toupper.o\
			ft_strcat.o\
			ft_strchr.o\
			ft_strclr.o\
			ft_strcmp.o\
			ft_strcpy.o\
			ft_strdel.o\
			ft_strdup.o\
			ft_strequ.o\
			ft_striter.o\
			ft_striteri.o\
			ft_strjoin.o\
			ft_strlcat.o\
			ft_strlen.o\
			ft_strmap.o\
			ft_strmapi.o\
			ft_strncat.o\
			ft_strncmp.o\
			ft_strncpy.o\
			ft_strnequ.o\
			ft_strnew.o\
			ft_strnstr.o\
			ft_strrchr.o\
			ft_strsplit.o\
			ft_strstr.o\
			ft_strsub.o\
			ft_btree_apply_by_level.o\
			ft_btree_apply_infix.o\
			ft_btree_apply_prefix.o\
			ft_btree_apply_suffix.o\
			ft_btree_create_node.o\
			ft_btree_insert_data.o\
			ft_btree_level_count.o\
			ft_btree_search_item.o\
			ft_strtrim.o\
			get_next_line.o

all: $(NAME)

$(NAME):
	@echo "Compiling the libft..."
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libft.a made !"

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
