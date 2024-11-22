# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 12:57:13 by paprzyby          #+#    #+#              #
#    Updated: 2024/07/23 19:52:16 by paprzyby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE			=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c ft_strchr.c ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memcpy.c \
					ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c \
					ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c \
					ft_strjoin.c ft_strtrim.c \
					ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_putstr_fd.c ft_strmapi.c ft_striteri.c ft_lstclear_bonus.c

BONUS			=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
					ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
					ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS		= $(BONUS:.c=.o)

OBJS			= $(SOURCE:.c=.o)

CC				= cc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)

				ar rcs $(NAME) $(OBJS)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: 			%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)
re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus

fclean:			clean
				$(RM) $(NAME) $(BONUS_OBJS)
