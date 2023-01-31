NAME := libft.a
SRC := \
	ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_tolower \
	ft_toupper \
	ft_strlen \
	ft_strncmp \
	ft_strnstr \
	ft_strchr \
	ft_strrchr \
	ft_strlcpy \
	ft_strlcat \
	ft_strjoin \
	ft_strdup \
	ft_substr \
	ft_strtrim \
	ft_split \
	ft_strmapi \
	ft_striteri \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_atoi \
	ft_itoa \
	ft_memset \
	ft_bzero \
	ft_memchr \
	ft_memcmp \
	ft_memcpy \
	ft_memmove \
	ft_calloc
SRC_C := $(addsuffix .c, $(SRC))
SRC_O := $(addsuffix .o, $(SRC))
BONUS := \
	ft_lstnew \
	ft_lstadd_front \
	ft_lstadd_back \
	ft_lstsize \
	ft_lstlast \
	ft_lstdelone \
	ft_lstclear \
	ft_lstiter \
	ft_lstmap
BONUS_C := $(addsuffix _bonus.c, $(BONUS))
BONUS_O := $(addsuffix _bonus.o, $(BONUS))
SUPPLEMENTARY := \
	ft_printf \
	ft_print_utils \
	get_next_line_bonus \
	get_next_line_utils_bonus
SUPP_C := $(addsuffix .c, $(SUPPLEMENTARY))
SUPP_O := $(addsuffix .o, $(SUPPLEMENTARY))
CC_FLAG := -Wall -Wextra -Werror -c

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME):
	@cc $(CC_FLAG) $(SRC_C)
	@ar -crs $(NAME) $(SRC_O)

clean:
	@rm -f $(SRC_O) $(BONUS_O) $(SUPP_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(BONUS_O) $(SUPP_O)

$(BONUS_O):
	@cc $(CC_FLAG) $(BONUS_C)
	@ar -crs $(NAME) $(BONUS_O)

$(SUPP_O):
	@cc $(CC_FLAG) $(SUPP_C)
	@ar -crs $(NAME) $(SUPP_O)
