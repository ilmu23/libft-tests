# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 17:16:17 by ivalimak          #+#    #+#              #
#    Updated: 2023/11/04 21:57:30 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ATOI	=	../atoitest

all: atoi

$(ATOI): atoi.cpp
	@make -C .. --no-print-directory
	@echo Compiling...
	@c++ -Wall -Wextra -Werror -I.. atoi.cpp -L.. -lft -o $(ATOI)

atoi: $(ATOI)
	@./$(ATOI)

clean:
	@rm -f $(ATOI)

re: clean all
