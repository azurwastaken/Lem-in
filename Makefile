# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaseaux <mcaseaux@student.42.fr>        +#+  +:+         +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 11:59:32 by mcaseaux          #+#    #+#              #
#    Updated: 2019/01/31 14:11:49 by mcaseaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem-in

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

LIBFTDIR	=	libft/
LIBFT 		=	$(LIBFTDIR)libft.a

SRCDIR		=	src/

SRCS		=	main.c \
					getter.c \
					error.c \
					get_path.c \
					init_free.c \
					print_utils.c \
					init_resolve.c \
					bfs.c \
					lst_free.c \
					node_getid.c \
					print_path.c \
					resolve.c \
					util.c \
					parser/parse_utils.c \
					parser/line_handle.c \
					parser/line_is.c \
					parser/parse_stdin.c

OBJDIR		=	bin/
SUBDIRS		=	parser

OBJDIRS		=	$(addprefix $(OBJDIR), $(SUBDIRS))
OBJS		=	$(addprefix $(OBJDIR), $(SRCS:.c=.o))

all: $(LIBFT) $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	@echo "Creating the lem-in executable..."
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "lem-in made!"

$(LIBFT):
	@make -C $(LIBFTDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIRS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(FLAGS) -Iincludes -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
