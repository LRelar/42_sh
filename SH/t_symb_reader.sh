# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    t_symb_reader.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschimme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/28 17:45:29 by mschimme          #+#    #+#              #
#    Updated: 2019/08/28 17:49:12 by mschimme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

object=symb_reader

gcc -Wall -Wextra -I./includes -I./libft/includes ./_tests/$object.c \
./src/built-in_prompt.c ./src/deb_funcs.c ./src/errors.c ./src/init_structs.c \
./src/process_control.c ./src/process_input.c ./src/read.c \
./src/termios.c -L./libft -lft -o ./$object