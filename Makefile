# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 12:22:19 by alyovano          #+#    #+#              #
#    Updated: 2021/01/27 15:21:36 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


BUILTIN = $(addprefix srcs/builtin/, export.c unset.c pwd.c echo.c exit.c \
			cd.c env.c utils.c utils_environnement.c export_whitout_argument.c)
MINISHELL = $(addprefix srcs/minishell/, minishell.c error.c conditionning.c \
			signaux.c free_minishell.c error2.c create_files.c)
PARSING = $(addprefix srcs/parsing/, backslash.c parsing.c parsing2.c \
			first_split.c clean_line.c semicolon.c chevron.c \
			clean_spaces.c check_start.c dollar.c dollar2.c dollar3.c \
			parsing_redirrect.c split_pipe.c split_pipe2.c \
			pipe.c parsing_utils.c)
QUOTE = $(addprefix srcs/quote/, algo_quote_actuel.c requote_or_rmquote.c)
EXEC = $(addprefix srcs/exec/, exec.c dispatch.c exec_main.c exec_type.c \
			in_out_setup.c split_tokenize.c tokenize_realloc.c last_clean.c)
REDIRRECT = $(addprefix srcs/redirrect/, redirrect.c double_tab.c \
			init_redirrect.c error_redirrect.c path_redirrect.c \
			path_redirrect2.c next_redirrect.c remove_redirrect.c)

SRCS		= 	$(BUILTIN)					\
				$(MINISHELL)				\
				$(PARSING)					\
				$(QUOTE) 					\
				$(EXEC) 					\
				$(REDIRRECT) 				\

INCL		= 	srcs/includes/

OBJS		= 	${SRCS:.c=.o}

LIBFTPRINTF	= 	srcs/libft/libftprintfgnl.a

NAME		= 	minishell

CC			= 	gcc

RM			= 	rm -f

CFLAGS 		= 	-Wall -Wextra -Werror -I ${INCL}

.c.o:
			${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C srcs/libft
			${CC} -o ${NAME} ${OBJS} ${LIBFTPRINTF}

all:		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C srcs/libft
fclean:		clean
			${RM} ${NAME}
			make fclean -C srcs/libft

re:			fclean all

.PHONY:		clean fclean re all bonus
