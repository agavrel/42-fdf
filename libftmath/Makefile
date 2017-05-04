# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angavrel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/20 22:25:39 by angavrel          #+#    #+#              #
#    Updated: 2017/01/25 16:29:22 by angavrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC       = gcc
FLAGS    = -Wall -Wextra -Werror

### EXECUTABLE ###
NAME     = libftmath.a

### INCLUDES ###
OBJ_PATH = objs
SRC_PATH = srcs

### SOURCES ###
SRCS = ft_factor_matrix_free.c \
	   ft_matrix_global_rotation.c \
	   ft_matrix_to_vector.c \
	   ft_identity_matrix.c \
	   ft_sum_matrix.c \
	   ft_free_matrix.c \
	   ft_matrix_rotation.c \
	   ft_matrix_z_scaling.c \
	   ft_identity_matrix.c \
	   ft_matrix_scaling.c \
	   ft_copy_matrix.c \
	   ft_htoi.c \
	   ft_puthex.c \
	   ft_isdigit.c

### OBJECTS ###
OBJS = $(SRCS:%.c=$(OBJ_PATH)/%.o)

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### RULES ###
all :  tmp $(NAME)

$(NAME) : $(OBJS)
	@echo "$(CYAN)== LibftMath successfully compiled =="
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

tmp :
	@if [ ! -d $(OBJ_PATH) ]; then mkdir $(OBJ_PATH); fi

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@echo "$(CYAN)== Deleting LibftMath .o files =="
	@rm -fr $(OBJ_PATH)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all re
