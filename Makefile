# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschimme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 00:16:21 by mschimme          #+#    #+#              #
#    Updated: 2019/08/28 16:55:30 by mschimme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

.PHONY : all clean fclean re directories

DIR_SRC	= ./src/
DIR_INC	= ./includes/
DIR_OBJ	= ./obj/
LIB		= libft.a
DIR_LIB	= libft/

SOURCE	= built-in_prompt.c \
deb_funcs.c \
errors.c \
init_structs.c \
process_control.c \
process_input.c \
read.c \
shell.c \
termios.c


FLAGS	= -Wall -Wextra #-Werror

OBJ		= $(SOURCE:%.c=%.o)
OBJS	= $(SOURCE:%.c=$(DIR_OBJ)%.o)
SRCS	= $(SOURCE:%.c=$(DIR_SRC)%.c)

all: $(NAME)

$(NAME): $(LIB) directories $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $(OBJS) -L$(DIR_LIB) -lft

directories:
	@mkdir -p $(DIR_OBJ)

$(LIB):
	@$(MAKE) -C $(DIR_LIB)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@gcc $(FLAGS) -o $@ -c $< -I$(DIR_PAR)$(DIR_LIB)$(DIR_INC) -I$(DIR_PAR)$(DIR_INC)

clean:
	@rm -f $(DIR_OBJ)*.o
	@rm -f $(DIR_LIB)*.o
	@rm -rf $(DIR_OBJ)
fclean: clean
	@rm -f $(DIR_LIB)$(LIB)
	@rm -f $(NAME)
re: fclean all