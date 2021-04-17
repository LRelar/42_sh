object=t_bitwizenot

gcc -Wall -Wextra -I./includes -I./libft/includes ./_tests/$object.c -L./libft -lft -o ./$object
