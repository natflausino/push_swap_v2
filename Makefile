# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/13 18:44:00 by nbarreir          #+#    #+#              #
#    Updated: 2021/09/16 20:07:07 by nbarreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
INCLUDES = ./includes/push_swap.h

SRC_PATH = ./src/
UTILS_PATH = ./utils/

SRC = $(SRC_PATH)main.c\
			$(SRC_PATH)errors.c\
			$(SRC_PATH)stack_a.c\
			$(SRC_PATH)set_sort.c\
			$(SRC_PATH)move_rotate_reverse.c\
			$(SRC_PATH)move_push_swap.c\
			$(SRC_PATH)sort_utils.c\
			$(SRC_PATH)sort_big_utils.c\
			$(UTILS_PATH)ft_split.c\
			$(UTILS_PATH)ft_isdigit.c\
			$(UTILS_PATH)ft_isspace.c\
			$(UTILS_PATH)ft_atoll.c\
			$(UTILS_PATH)ft_strncmp.c\
			$(UTILS_PATH)ft_lstadd_back.c\
			$(UTILS_PATH)ft_lstadd_front.c\
			$(UTILS_PATH)ft_lstlast.c\
			$(UTILS_PATH)ft_lstsize.c\
			$(UTILS_PATH)ft_lstnew.c\
			$(UTILS_PATH)ft_lstduplicate.c\


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

.c.o: $(SRC_PATH)/%.c
		$(CC) $(FLAGS) -c $< -o $@

git:
	@git add .
	@git commit -m "$m"
	@git push
#make git m="blablabla"

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all


.PHONY:		all clean fclean re