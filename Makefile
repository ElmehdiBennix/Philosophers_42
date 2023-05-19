# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 07:56:09 by ebennix           #+#    #+#              #
#    Updated: 2023/05/19 17:05:00 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := philo

ARCH := utils/utils.a

CC := cc

CFLAGS := -Wall -Wextra -Werror -g

FILES := 

SRC := $(FILES:=.c)

OBJ := $(SRC:.c=.o)

RM := rm -rf

m := MakefileAutoPush


all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(OBJ) $(ARCH) $(EXE)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJ_B)

fclean : clean
	$(RM) $(EXE)
	$(RM) $(EXE_B)

re : fclean all

git :
	git add .
	git status
	git commit -m "$(m)"
	git push

.PHONY : all clean fclean re git
