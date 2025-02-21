# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 07:56:09 by ebennix           #+#    #+#              #
#    Updated: 2023/08/13 02:14:31 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := philo

HEADER := inc/philo.h inc/colors.h

CC := cc

CFLAGS := -Wall -Wextra -Werror -fsanitize=thread -g

FILES := life_cycle/time	life_cycle/philo_cycle	utils/exit		\
		 parse/init_philos	parse/parsing			utils/tools		\

SRC := $(FILES:=.c)
OBJ := $(SRC:.c=.o)

RM := rm -rf

# **************************************************************************** #

all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(CFLAGS) philo.c $(OBJ) -o $(EXE)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)

re : fclean all

# **************************************************************************** #

.PHONY : all clean fclean re
