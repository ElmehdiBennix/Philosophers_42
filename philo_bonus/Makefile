# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 07:56:09 by ebennix           #+#    #+#              #
#    Updated: 2023/08/10 15:30:35 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := philo

B_EXE := philo_bonus

HEADER := inc/philo_bonus.h		inc/colors.h

CC := cc

CFLAGS := -g -Wall -Wextra
# -Werror

FILES := philo_bonus			utils/exit					utils/tools			\
		 parse/init_philos		life_cycle/philo_cycle		parse/parsing		\
		 life_cycle/time														\

SRC := $(FILES:=.c)
OBJ := $(SRC:.c=.o)

RM := rm -rf

m := MakefileAutoPush


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

git :
	git add .
	git status
	git commit -m "$(m)"
	git push

.PHONY : all clean fclean re git
