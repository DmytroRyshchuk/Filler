# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 12:29:23 by dryshchu          #+#    #+#              #
#    Updated: 2018/02/26 12:29:26 by dryshchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dryshchu.filler
FLAGS = gcc -Wall -Werror -Wextra

SRC = read.c get_next_line.c fill.c lib.c lib2.c \

OBJ = $(SRC:.c=.o)

NO_COLOUR	=	\033[0m
UGreen		=	\033[4;32m
URed		=	\033[4;31m

all: $(SRC) $(NAME)

$(NAME): $(SRC)
	@echo "${UGreen}Compiling $(NAME) with $(FLAGS) flags ${NO_COLOUR}\n..."
	$(FLAGS) $^ -o $@
	@echo "${UGreen}Done!${NO_COLOUR}"

# %.o: %.c
# 	$(FLAGS) -c $< 

clean:
	rm -f $(OBJ)
	@echo "${URed}Folder with object files has been removed.${NO_COLOUR}"

fclean: clean
	rm -f .DS*
	rm -f $(NAME)
	@echo "${URed}${NAME} has been removed.${NO_COLOUR}"

re: fclean all

.PHONY: clean fclean all re
