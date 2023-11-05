# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 17:16:17 by ivalimak          #+#    #+#              #
#    Updated: 2023/11/05 16:28:54 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CURDIR	=	$(shell pwd)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g

ATOI	=	../atoitest
SPLIT	=	../splittest

all: atoi split

$(ATOI):
	@make -C .. 1> /dev/null
	@echo Compiling...
	@c++ -Wall -Wextra -Werror -I.. atoi.cpp -L.. -lft -o $(ATOI)

$(SPLIT): $(MALLOC)
	@mv ../libft.h ../libft.h.bak
	@cp libft.h ../libft.h
	@touch ../ft_split.c
	@make -C .. 1> /dev/null
	@echo Compiling...
	@$(CC) $(CFLAGS) -I.. split.c -L.. -lft -o $(SPLIT)
	@mv ../libft.h.bak ../libft.h

atoi: $(ATOI)
	@./$(ATOI)
	@make fclean --no-print-directory

split: $(SPLIT)
	@./$(SPLIT)
	@make fclean --no-print-directory

clean:

fclean: clean
	@rm -f $(ATOI)
	@rm -f $(SPLIT)

re: clean all
