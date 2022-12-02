
CC = gcc
CFLAGS = -Wall -Werror -Wextra 
NAME = libft.a
AR = ar rcs
SRC = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_istrlen.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_printf.c \
		ft_printnbr.c \
		ft_putchar_fd.c \
		ft_putcharf.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putnbrhexa.c \
		ft_putnbrhexa_p.c \
		ft_putstr_fd.c \
		ft_putstrf.c \
		ft_split.c \
		ft_split2.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strdupcat.c \
		ft_strichr.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tablen.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_uprint.c \
		get_next_line.c\
		ft_isalpha_under_s.c\
		ft_strjoin_free.c

#******Colors******#

BLUE_T			=		\033[0;34m
BLUE			=		\033[44m
ENDCOLOR		=		\033[0m

#******Echo********#

START			=		echo "$(BLUE_T)Start compilation LIBFT\n$(ENDCOLOR)"
END_COMP_LIB	=		echo "$(BLUE_T)End compilation LIBFT\n$(ENDCOLOR)"
CHARG_LINE		=		echo "$(BLUE)    $(ENDCOLOR)\c"
BS_N			=		echo "\n"

#******Rules*******#

OBJS = ${SRC:.c=.o}

all: start ${NAME}

start:
	@${START}

%.o: %.c
		@${CC} ${CFLAGS} -c $< -o $@
		@$(CHARG_LINE)

${NAME}: ${OBJS}
		 @$(BS_N)
		@${AR} ${NAME} ${OBJS}
		@$(END_COMP_LIB)


clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean