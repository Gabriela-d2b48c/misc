# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 09:59:29 by gabriela          #+#    #+#              #
#    Updated: 2023/04/23 17:35:54 by gabriela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iheader
DFLAGS = -MMD -MF $(DEP_DIR)$*.d

SRC_DIR = srcs/
OBJ_DIR = obj/
DEP_DIR = $(OBJ_DIR)deps/

LIBFT_DIR = libft/
LIBFT_MAKEFILE = $(LIBFT_DIR)Makefile
LIBFT = $(LIBFT_DIR)libft.a

SRCS = free_mem.c \
	init_stack.c \
	input_handling.c \
	list_functions.c \
	sorting_utils.c \
	stack_a_operations.c \
	stack_b_operations.c \
	stack_sort.c \
	s_operations.c \
	p_operations.c \
	r_operations.c \
	rr_operations.c \

OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
DEPS = $(SRCS:%.c=$(DEP_DIR)%.d)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_DIR) $(DEP_DIR) $(DEPS) $(OBJS)
	@ $(CC) $(CFLAGS) $(DFLAGS) $(OBJS) -o $@ $(LIBFT)
	@echo "Creating $@"

$(OBJ_DIR):
	@mkdir $@

$(DEP_DIR):
	@mkdir -p $@

$(DEPS):
-include $(DEPS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEP_DIR)%.d
	@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_DIR) $(LIBFT_MAKEFILE)
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJS) $(OBJ_DIR) $(DEP_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "Cleaning successful"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "All generated files are deleted"

re: fclean all
	@echo "Remake completed"

.PHONY: all clean fclean re
