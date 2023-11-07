# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 17:16:17 by ivalimak          #+#    #+#              #
#    Updated: 2023/11/07 16:58:47 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CURDIR	=	$(shell pwd)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g

ATOI	=	../atoitest
SPLIT	=	../splittest
HPATCH	=	hpatcher

all: atoi split

$(ATOI):
	@make -C .. 1> /dev/null
	@echo Compiling...
	@c++ -Wall -Wextra -Werror -I.. atoi.cpp -L.. -lft -o $(ATOI)

$(SPLIT): $(HPATCH)
	@mv ../libft.h ../libft.h.bak
	@./$(HPATCH) ../libft.h.bak ../libft.h
	@touch ../ft_split.c
	@make -C .. 1> /dev/null
	@echo Compiling...
	@$(CC) $(CFLAGS) -I.. split.c -L.. -lft -o $(SPLIT)
	@mv ../libft.h.bak ../libft.h

$(HPATCH):
	@$(CC) $(CLFAGS) get_next_line*.c hpatcher.c -o $(HPATCH)

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
	@rm -f $(HPATCH)

re: clean all
