NAME		= 	push_swap

MAKEFILE	= 	Makefile

SRC			= 	 ft_check.c ft_count.c ft_error_exit.c ft_final.c ft_pars_string.c \
				ft_pars.c ft_pre_sort.c ft_put_b.c ft_split.c main.c pa_pb.c ra_rb.c \
				rra_rrb.c sa_sb.c \
				
OBJS		= ${SRC:.c=.o}

D_FILES		= $(patsubst %.c, %.d, $(SRC))

HEADER		= push_swap.h

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

.PHONY		:	all clean fclean re bonus

all			:	${NAME}

%.o 		: %.c ${MAKEFILE}
			$(CC) -c $< -o $@ -MD

$(NAME)	:	${OBJS}
			$(CC) $(OBJS) -o $(NAME)
			
clean		:
	@rm -f ${OBJS} ${D_FILES}

fclean	:	clean
	@${RM} ${NAME}

-include $(D_FILES)

re		:	fclean all