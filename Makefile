# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 07:56:09 by ebennix           #+#    #+#              #
#    Updated: 2023/08/08 06:43:33 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := philo

B_EXE := philo_bonus

HEADER := inc/philo.h inc/colors.h

B_HEADER := inc/philo_bonus.h inc/colors.h

CC := cc

CFLAGS := -g -Wall -Wextra
# -Werror

FILES := Mandatory/philo				Mandatory/utils/exit				Mandatory/utils/tools		\
		 Mandatory/parse/init_philos	Mandatory/life_cycle/philo_cycle	Mandatory/parse/parsing		\
		 Mandatory/life_cycle/time	\

B_FILES := bonus/philo				bonus/utils/error				bonus/utils/tools		\
		   bonus/parse/init_philos	bonus/life_cycle/philo_cycle	bonus/parse/parsing		\

SRC := $(FILES:=.c)
OBJ := $(SRC:.c=.o)

B_SRC := $(B_FILES:=.c)
B_OBJ := $(B_SRC:.c=.o)

RM := rm -rf

m := MakefileAutoPush


all : $(EXE)

bonus : $(B_EXE)

$(EXE) : $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

$(B_EXE) : $(B_OBJ)
	$(CC) $(B_OBJ) -o $(B_EXE)

%.o : %.c $(HEADER) || $(B_HEADER)
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
