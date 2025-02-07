# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 15:13:25 by dbisko            #+#    #+#              #
#    Updated: 2025/02/07 11:22:18 by dbisko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_atoi.c\
		ft_lstdelone.c\
		ft_putendl_fd.c\
		ft_strncmp.c\
		ft_bzero.c\
		ft_lstiter.c\
		ft_putnbr_fd.c\
		ft_strnstr.c\
		ft_calloc.c\
		ft_lstlast.c\
		ft_putstr_fd.c\
		ft_strrchr.c\
		ft_isalnum.c\
		ft_lstmap.c\
		ft_split.c\
		ft_strtrim.c\
		ft_isalpha.c\
		ft_lstnew.c\
		ft_strchr.c\
		ft_substr.c\
		ft_isascii.c\
		ft_lstsize.c\
		ft_strdup.c\
		ft_tolower.c\
		ft_isdigit.c\
		ft_memchr.c\
		ft_striteri.c\
		ft_toupper.c\
		ft_isprint.c\
		ft_memcmp.c\
		ft_strjoin.c\
		get_next_line.c\
		ft_itoa.c\
		ft_memcpy.c\
		ft_strlcat.c\
		ft_lstadd_back.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_lstadd_front.c\
		ft_memset.c\
		ft_strlen.c\
		ft_lstclear.c\
		ft_putchar_fd.c\
		ft_strmapi.c\
		get_next_line.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = $(FILES)
OFILES = $(FILES:.c=.o)
NAME = libft.a
$(NAME): $(OFILES)
		@$(CC) $(CFLAGS) -c $(CFILES) -I./
		@ar rcs $(NAME) $(OFILES)
all:	$(NAME)
clean:
		@rm -f *.o
fclean:	clean
		@rm -f $(NAME)
re:	fclean all

.PHONY: all clean fclean re