# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschimme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/28 20:41:38 by ycorrupt          #+#    #+#              #
#    Updated: 2021/05/01 13:55:16 by mschimme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC		=	clang
FLAGS	=	-Wall -Wextra -g
DIR_LIB	=	./src/libft

#**********************				PATHS:			***************************#
VPATH	:=	./src/my_sh:
#**********************				my_sh:			***************************#
SOURCE	+=	built-in_prompt.c \
			deb_funcs.c \
			errors.c \
			init_structs.c \
			process_control.c \
			process_input.c \
			read.c \
			shell.c \
			signals.c \
			termios.c

OBJ_DIR		:=	./obj_$(NAME)
OBJECTS		:=	$(patsubst %,$(OBJ_DIR)/%,$(SOURCE:.c=.o))

INC_DIR	:=	$(DIR_LIB)/includes ./includes
IFLAGS	+=	$(foreach d, $(INC_DIR), -I $d)

.PHONY: all clean fclean re MAKEDIR LIB

all: $(NAME)

$(NAME): LIB MAKEDIR $(OBJECTS)
	@$(CC) $(OBJECTS) -L $(DIR_LIB) -lft  $(FLAGS) -o $(NAME)
	@echo ""
	@echo '$(NAME) ready'

LIB:
	@$(MAKE) -C $(DIR_LIB)

MAKEDIR:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:%.c
	@echo -ne '\e[1K\e[0ECompile '
	@printf '\e[1;32m%-6s\e[m' $@
	@$(CC) $(IFLAGS) $(FLAGS) -c $< -o $@
	@echo -ne '\e[1K\e[0ECompile competed '

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(DIR_LIB) clean
	

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(DIR_LIB) fclean

re: fclean all