# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 07:56:09 by ebennix           #+#    #+#              #
#    Updated: 2023/05/27 22:04:22 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := philo

HEADER := inc/philo.h

CC := cc

CFLAGS := -Wall -Wextra -g
# -Werror

FILES := Mandatory/philo	Mandatory/utils/error	Mandatory/utils/tools	Mandatory/parse/parsing \
		 Mandatory/parse/init_philos 		Mandatory/utils/ft_atoi			Mandatory/utils/lst		\
		 Mandatory/life_cycle/philo_cycle \

SRC := $(FILES:=.c)

OBJ := $(SRC:.c=.o)

RM := rm -rf

m := MakefileAutoPush


all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)

re : fclean all

git :
	git add .
	git status
	git commit -m "$(m)"
	git push

.PHONY : all clean fclean re git
