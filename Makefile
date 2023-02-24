



SRCS			=	 Mandatory/libft/ft_substr.c Mandatory/libft/ft_strlen.c  Mandatory/libft/ft_strncmp.c  Mandatory/libft/ft_putstr_fd.c  Mandatory/libft/ft_strdup.c\
					Mandatory/ft_printf/ft_printf.c  Mandatory/ft_printf/ft_put_u.c  Mandatory/ft_printf/ft_putadd.c  Mandatory/ft_printf/ft_putnbr.c  Mandatory/ft_printf/ft_putstr.c \
					 Mandatory/ft_printf/print_hex.c  Mandatory/ft_printf/put_char.c\
					  Mandatory/check_clean.c  Mandatory/ft_split.c  Mandatory/get_next_line_utils.c  Mandatory/get_next_line.c  Mandatory/parcing.c  Mandatory/pipex.c 

BONUS           =	Bonus/ft_printf/ft_printf.c Bonus/ft_printf/ft_put_u.c Bonus/ft_printf/ft_putadd.c Bonus/ft_printf/ft_putnbr.c Bonus/ft_printf/ft_putstr.c Bonus/ft_printf/print_hex.c Bonus/ft_printf/put_char.c Bonus/here_doc.c Bonus/here_doc_utils.c\
					Bonus/libft/ft_putstr_fd.c Bonus/libft/ft_strcmp.c Bonus/libft/ft_strdup.c Bonus/libft/ft_strlen.c Bonus/libft/ft_strncmp.c Bonus/libft/ft_substr.c Bonus/check_clean_bonus.c Bonus/ft_split_bonus.c Bonus/get_next_line_bonus.c \
					Bonus/get_next_line_utils_bonus.c Bonus/parcing_bonus.c Bonus/pipex_bonus.c
					
OBJS			= $(SRCS:.c=.o)
B_OBJS          = $(BONUS:.c=.o)
CC				= cc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror
NAME			= Mandatory/pipex
NAME_B		    = Bonus/pipex

.PHONY: all clean bonus fclean re

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(NAME_B): $(B_OBJS) 
	$(CC) $(FLAGS) $(B_OBJS) -o $(NAME_B)

all: $(NAME) 

bonus: $(NAME_B)

%.o: %.c Mandatory/pipex.h Bonus/pipex_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(B_OBJS) 

fclean:	clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all
	 