# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 04:39:59 by jodufour          #+#    #+#              #
#    Updated: 2022/10/29 08:42:34 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC				=	clang
LINK			=	clang
MKDIR			=	mkdir -p
RM				=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME			=	unit_test.out

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR			=	srcs
OBJ_DIR			=	objs

PRV_DIR			=	private

UNIT_DIR		=	../framework
UNIT_INC_DIR	=	include
UNIT_INC_DIR	:=	${addprefix ${UNIT_DIR}/, ${UNIT_INC_DIR}}

#######################################
#              LIBRARIES              #
#######################################
UNIT_A			=	libunit.a
UNIT_A			:=	${addprefix ${UNIT_DIR}/, ${UNIT_A}}

######################################
#            SOURCE FILES            #
######################################
SRC				=	\
					${addprefix math/,			\
						00_launcher.c			\
						01_div_zero_test.c		\
					}							\
					${addprefix strchr/,		\
						00_launcher.c			\
						01_basic_test.c			\
						02_null_test.c			\
					}							\
					${addprefix strcmp/,		\
						00_launcher.c			\
						01_basic_test.c			\
						02_null_test.c			\
						03_illegal_test.c		\
					}							\
					${addprefix strcpy/,		\
						00_launcher.c			\
						01_basic_test.c			\
						02_bad_cpy_test.c		\
						03_freed_test.c			\
						04_misaligned_test.c	\
					}							\
					${addprefix strlen/,		\
						00_launcher.c			\
						01_basic_test.c			\
						02_null_test.c			\
						03_bad_len_test.c		\
						04_uninitialized_test.c	\
						05_lorem_ipsum_test.c	\
						06_abort_test.c			\
						07_endless_loop_test.c	\
					}							\
					${addprefix write/,			\
						00_launcher.c			\
						01_basic_test.c			\
						02_pipe_test.c			\
					}							\
					main.c

######################################
#            OBJECT FILES            #
######################################
OBJ				=	${SRC:.c=.o}
OBJ				:=	${addprefix ${OBJ_DIR}/, ${OBJ}}

DEP				=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS			=	-c
CFLAGS			+=	-Wall -Wextra -Werror
CFLAGS			+=	-MMD -MP
CFLAGS			+=	-I${PRV_DIR}
CFLAGS			+=	-I${UNIT_INC_DIR}

LDFLAGS			=	-L${UNIT_DIR} -lunit

VG_OPTION		=	--track-fds=yes
VG_OPTION		+=	--show-leak-kinds=all
VG_OPTION		+=	--leak-check=full
VG_OPTION		+=	--trace-children=yes

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
.PHONY: all test clean fclean re fre

${NAME}: ${OBJ} ${UNIT_A}
	${LINK} ${OBJ} ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKDIR} ${@D}
	${CC} ${CFLAGS} $< ${OUTPUT_OPTION}

${UNIT_A}:
	${MAKE} ${@F} -C ${@D}

test: ${NAME}
ifeq (${DEBUG}, 1)
	valgrind ${VG_OPTION} ./${NAME}
else
	./${NAME}
endif

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*
	${MAKE} $@ -C ${UNIT_DIR}

re: clean all

fre: fclean all

-include ${HOME}/Templates/mk_files/coffee.mk
-include ${HOME}/Templates/mk_files/norm.mk
