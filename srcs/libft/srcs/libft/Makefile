# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 15:18:57 by alyovano          #+#    #+#              #
#    Updated: 2020/12/16 09:22:27 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

SRC			= ft_isdigit.c ft_memset.c ft_strnstr.c ft_atoi.c ft_isprint.c ft_strchr.c\
			  ft_strrchr.c ft_bzero.c ft_memccpy.c ft_strdup.c ft_tolower.c ft_calloc.c\
			  ft_memchr.c ft_strlcat.c ft_toupper.c ft_isalnum.c ft_memcmp.c  ft_strlcpy.c\
			  ft_isalpha.c ft_memcpy.c  ft_strlen.c ft_isascii.c ft_memmove.c ft_strncmp.c\
			  ft_substr.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
			  ft_putnbr_fd.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c\
			  ft_putnbr_unsigned_fd.c ft_intlen.c ft_isprintf.c ft_itoa_base.c ft_putstr_len.c\
			  ft_while_print.c ft_capital.c ft_itoa_base_two.c ft_unsigned_itoa.c ft_utoa.c\
			  utoa_p_zero_printf.c ft_double_tab.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c\
			  ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
			  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c free_double_tab.c ft_strcmp.c\

OBJ			= $(SRC:.c=.o)

NAME		= libft.a

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -Iinclude

%.c: %.o	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I

$(NAME):	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "\033[0;32mDone.\033[0;32m"

all:		$(NAME)

clean:
	@$(RM) $(OBJ) $(OBJBONUS)
	@echo "Clean process"

fclean:		clean
	@${RM} $(NAME)

re:			fclean all

.PHONY: all clean fclean re
