# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 07:56:09 by ebennix           #+#    #+#              #
#    Updated: 2023/08/13 01:25:31 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := philo

HEADER := inc/philo.h inc/colors.h

CC := cc

CFLAGS := -g -Wall -Wextra -Werror

FILES := philo					utils/exit					utils/tools			\
		 parse/init_philos		life_cycle/philo_cycle		parse/parsing		\
		 life_cycle/time														\

SRC := $(FILES:=.c)
OBJ := $(SRC:.c=.o)

RM := rm -rf


all : $(EXE)

bonus : $(B_EXE)

$(EXE) : $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)
	$(RM) $(B_OBJ)

fclean : clean
	$(RM) $(EXE)
	$(RM) $(B_EXE)

re : fclean all

.PHONY : all clean fclean re
