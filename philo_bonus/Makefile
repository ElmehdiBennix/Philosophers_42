# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 07:56:09 by ebennix           #+#    #+#              #
#    Updated: 2023/08/13 02:14:33 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := philo_bonus

HEADER := inc/philo_bonus.h	inc/colors.h

CC := cc

CFLAGS := -Wall -Wextra -Werror -fsanitize=thread -g

FILES := parse/init_philos	life_cycle/philo_cycle	parse/parsing	utils/exit	\
		 life_cycle/time	parse/routine_fork		utils/tools					\

SRC := $(FILES:=.c)
OBJ := $(SRC:.c=.o)

RM := rm -rf

# **************************************************************************** #

all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(CFLAGS) philo_bonus.c $(OBJ) -o $(EXE)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)

re : fclean all

# **************************************************************************** #

.PHONY : all clean fclean re
