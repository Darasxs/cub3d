# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 13:38:09 by paprzyby          #+#    #+#              #
#    Updated: 2024/07/15 13:38:38 by paprzyby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	get_next_line.a

SOURCE			=	get_next_line.c get_next_line_utils.c

OBJS			=	$(SOURCE:.c=.o)

CC				=	cc

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

all:				$(NAME)

$(NAME):			$(OBJS)
					ar rcs $(NAME) $(OBJS)

%.o:				%.c
					$(CC) $(CFLAGS) -c $< -o $@

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re