# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperrein <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 12:19:04 by aperrein          #+#    #+#              #
#    Updated: 2023/04/20 15:54:51 by aperrein         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

BONUS	=	checker

OBJ_DIR =	OBJ/

SRC_DIR =	SRC/

SRC	=	do_r.c do_s_p.c radix.c stack.c init_check.c

OBJ	=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

RM	=	rm -f

CFLAGS	=	-Wall -Werror -Wextra

all     :       $(OBJ_DIR) $(NAME)
	
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		gcc $(CFLAGS) -c $< -o $@
		gcc $(CFLAGS) -c SRC/main.c -o OBJ/main.o
		gcc $(CFLAGS) -c SRC/checker.c -o OBJ/checker.o

$(OBJ_DIR) :
		@./libft/swaps
		mkdir $(OBJ_DIR)


$(NAME)	:	make_lib $(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ) OBJ/main.o libft/libft.a

bonus :		make_lib $(OBJ)
		gcc $(CFLAGS) -o $(BONUS) $(OBJ) OBJ/checker.o libft/libft.a
make_lib :
		@make -s -C libft/

clean	:
		$(RM) $(OBJ) OBJ/main.o OBJ/checker.o

fclean	:	clean
		$(RM) $(NAME) $(BONUS)

re 	:	fclean $(NAME)
