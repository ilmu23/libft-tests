# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 17:16:17 by ivalimak          #+#    #+#              #
#    Updated: 2023/11/04 23:15:05 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CURDIR	=	$(shell (pwd))

ATOI	=	../atoitest
SPLIT	=	../splittest

MALLOC	=	malloc.so

all: atoi split

$(ATOI):
	@make -C .. --no-print-directory
	@echo Compiling...
	@c++ -Wall -Wextra -Werror -I.. atoi.cpp -L.. -lft -o $(ATOI)

$(SPLIT): $(MALLOC)
	@make -C .. --no-print-directory
	@echo Compiling...
	@cc -Wall -Wextra -Werror -g -I.. split.c -L.. -lft -o $(SPLIT)

$(MALLOC): nmalloc.c
	@cc -Wall -Wextra -Werror -fPIC -shared -o $@ nmalloc.c

atoi: $(ATOI)
	@./$(ATOI)
	@make fclean --no-print-directory

split: $(SPLIT)
	@LD_PRELOAD=$(CURDIR)/$(MALLOC) ./$(SPLIT)
	@make fclean --no-print-directory

clean:
	@rm -f $(MALLOC)

fclean: clean
	@rm -f $(ATOI)
	@rm -f $(SPLIT)

re: clean all
