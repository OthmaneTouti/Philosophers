# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 10:50:47 by ottouti           #+#    #+#              #
#    Updated: 2024/01/29 11:11:22 by ottouti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../incl/ -fsanitize=address
DEBUGFLAGS = -g
LDFLAGS = -L ./incl/ -fsanitize=address
RM = rm -f

MAIN = main.c
MAIN_OBJ = main.o

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS = $(SRCS:.c=.o) $(MAIN_OBJ)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUGFLAGS)
debug: re

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ./incl/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./incl/ fclean

re: fclean all

.PHONY: all clean fclean re debug


