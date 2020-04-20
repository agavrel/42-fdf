# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 17:08:23 by agrumbac          #+#    #+#              #
#    Updated: 2017/05/16 22:06:37 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_ARRAY = \
ft_arrayadd.c ft_arraydel.c ft_arraynew.c ft_arrayappend.c ft_arrayread.c

SRC_IO = \
ft_get_next_line.c ft_putendl.c ft_putnbr_fd.c \
ft_putchar.c ft_putendl_fd.c ft_putstr.c \
ft_putchar_fd.c ft_putnbr.c ft_putstr_fd.c

SRC_LST = \
ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstnew.c \
ft_lstaddend.c ft_lstdelone.c ft_lstmap.c ft_lstsize.c ft_lstsort.c

SRC_MATHS = \
ft_abs.c ft_fac.c ft_intlen.c ft_sqrt.c \
ft_atoi.c ft_gcd.c ft_pow.c ft_atol.c ft_atoll.c ft_atoi_base.c

SRC_MEM = \
ft_bzero.c ft_memccpy.c ft_memcmp.c ft_memdel.c ft_memset.c \
ft_memalloc.c ft_memchr.c ft_memcpy.c ft_memmove.c

SRC_STR = \
ft_isalnum.c ft_strchr.c ft_strequ.c ft_strmapi.c ft_strrchr.c \
ft_isalpha.c ft_strchrn.c ft_striter.c ft_strncat.c ft_strsplit.c \
ft_isascii.c ft_strclr.c ft_striteri.c ft_strncmp.c ft_strstr.c \
ft_isdigit.c ft_strcmp.c ft_strjoin.c ft_strncpy.c ft_strsub.c \
ft_isprint.c ft_strcpy.c ft_strlcat.c ft_strnequ.c ft_strtrim.c \
ft_itoa.c ft_itoa_base.c ft_strdel.c ft_strlen.c ft_strnew.c \
ft_strcat.c ft_strdup.c ft_strmap.c ft_strnstr.c ft_toupper.c ft_tolower.c \
ft_strtolower.c ft_strtoupper.c ft_wcslen.c ft_strlaststr.c ft_strnjoin.c \
ft_strndup.c ft_strjoinnfree.c ft_itoa_base_s.c

SRC_PRINTF = \
ft_printf.c ft_printf_int.c ft_printf_str.c ft_printf_ptr.c \
ft_printf_mod.c ft_printf_char.c ft_printf_padding.c ft_printf_itoa.c\
ft_printf_buf.c

OBJDIR = objs

OBJ_ARRAY = $(addprefix ${OBJDIR}/, $(SRC_ARRAY:.c=.o))

OBJ_IO = $(addprefix ${OBJDIR}/, $(SRC_IO:.c=.o))

OBJ_LST = $(addprefix ${OBJDIR}/, $(SRC_LST:.c=.o))

OBJ_MATHS = $(addprefix ${OBJDIR}/, $(SRC_MATHS:.c=.o))

OBJ_MEM = $(addprefix ${OBJDIR}/, $(SRC_MEM:.c=.o))

OBJ_STR = $(addprefix ${OBJDIR}/, $(SRC_STR:.c=.o))

OBJ_PRINTF = $(addprefix ${OBJDIR}/, $(SRC_PRINTF:.c=.o))

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LFT = includes/libft.h
FTP = includes/ft_printf.h

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: ${NAME}
	@echo ${G}Success"   "[${NAME}]${X}

${NAME}: ${OBJ_ARRAY} ${OBJ_IO} ${OBJ_LST} ${OBJ_MATHS} ${OBJ_MEM} ${OBJ_STR} ${OBJ_PRINTF}
	@ar rcs ${NAME} ${OBJ_ARRAY} ${OBJ_IO} ${OBJ_LST} ${OBJ_MATHS} ${OBJ_MEM} ${OBJ_STR} ${OBJ_PRINTF}
	@echo ${B}Compiling [${NAME}]...${X}

${OBJDIR}/%.o : ./srcs/ft_array/%.c ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}/%.o : ./srcs/ft_io/%.c ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}/%.o : ./srcs/ft_lst/%.c ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}/%.o : ./srcs/ft_maths/%.c ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}/%.o : ./srcs/ft_mem/%.c ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}/%.o : ./srcs/ft_str/%.c ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}/%.o : ./srcs/ft_io/ft_printf/%.c ${FTP} ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

clean:
	@echo ${R}Cleaning"  "[${OBJDIR}]...${X}
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@echo ${R}Cleaning"  "[${NAME}]...${X}
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
