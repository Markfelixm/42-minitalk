SERVER := server
CLIENT := client
SRC_SERVER := source/server.c
SRC_CLIENT := source/client.c
LIBFT_DIR := Libft
LIBFT := $(LIBFT_DIR)/libft.a
CC_FLAG := -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT)
	@cc $(CC_FLAG) $(SRC_SERVER) $(LIBFT) -o $(SERVER)

$(CLIENT): $(LIBFT)
	@cc $(CC_FLAG) $(SRC_CLIENT) $(LIBFT) -o $(CLIENT)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@make bonus -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@make fclean -C $(LIBFT_DIR)

re: fclean all