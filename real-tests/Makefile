# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 16:18:45 by jodufour          #+#    #+#              #
#    Updated: 2022/01/09 18:52:05 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC					=	clang -c
LINK				=	clang
MKDIR				=	mkdir -p
RM					=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME				=	unit_test.out

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR				=	./
OBJ_DIR				=	objs/

UNIT_DIR			=	../framework/
FT_PRINTF_DIR		=	libftprintf/

UNIT_INC_DIR		=	include/
UNIT_INC_DIR		:=	${addprefix ${UNIT_DIR}, ${UNIT_INC_DIR}}

FT_PRINTF_INC_DIR	=	include/
FT_PRINTF_INC_DIR	:=	${addprefix ${FT_PRINTF_DIR}, ${FT_PRINTF_INC_DIR}}

#######################################
#              LIBRARIES              #
#######################################
UNIT_A				=	libunit.a
UNIT_A				:=	${addprefix ${UNIT_DIR}, ${UNIT_A}}

FT_PRINTF_A			=	libftprintf.a
FT_PRINTF_A			:=	${addprefix ${FT_PRINTF_DIR}, ${FT_PRINTF_A}}

######################################
#            SOURCE FILES            #
######################################
SRC					=	\
						${addprefix cvrt_c/,	\
							00_launcher.c		\
							01_a_test.c			\
						}						\
						${addprefix cvrt_d/,	\
							00_launcher.c		\
						}						\
						${addprefix cvrt_i/,	\
							00_launcher.c		\
						}						\
						${addprefix cvrt_p/,	\
							00_launcher.c		\
						}						\
						${addprefix cvrt_s/,	\
							00_launcher.c		\
						}						\
						${addprefix cvrt_u/,	\
							00_launcher.c		\
						}						\
						${addprefix cvrt_x/,	\
							00_launcher.c		\
						}						\
						${addprefix literal/,	\
							00_launcher.c		\
						}						\
						main.c

######################################
#            OBJECT FILES            #
######################################
OBJ					=	${SRC:.c=.o}
OBJ					:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP					=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS				=	-Wall -Wextra -Werror
CFLAGS				+=	-MMD -MP
CFLAGS				+=	-I${UNIT_INC_DIR}
CFLAGS				+=	-I${FT_PRINTF_INC_DIR}

LDFLAGS				=	-L${UNIT_DIR} -lunit
LDFLAGS				+=	-L${FT_PRINTF_DIR} -lftprintf

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}: ${OBJ} ${UNIT_A} ${FT_PRINTF_A}
	${LINK} ${OBJ} ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} ${CFLAGS} $< ${OUTPUT_OPTION}

${UNIT_A}:
	${MAKE} ${@F} -C ${@D}

${FT_PRINTF_A}:
	${MAKE} ${@F} -C ${@D}

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*
	${MAKE} $@ -C ${UNIT_DIR}
	${MAKE} $@ -C ${FT_PRINTF_DIR}

re: clean all

fre: fclean all

.PHONY: all clean fclean re fre
