NAME = minitalk

NAME_SERVER = server

NAME_CLIENT = client

CC = cc

CC_FLAGS = -Wall -Werror -Wextra -g3

LIBFT_FLAG = -Llibft -lft

RM = rm

RM_FLAGS = -f

MAKE = make

MAKE_FLAGS = --no-print-directory

DIR_LIBFT = libft

FILES_SERVER = main_server.c server_handler.c

DIR_SERVER = srcs_server/

FILES_SERVER := $(addprefix $(DIR_SERVER), $(FILES_SERVER))

FILES_CLIENT = main_client.c client_handler.c

DIR_CLIENT = srcs_client/

FILES_CLIENT := $(addprefix $(DIR_CLIENT), $(FILES_CLIENT))

.PHONY: all clean fclean library

all: library $(NAME_CLIENT) $(NAME_SERVER)

library:
	$(MAKE) $(MAKE_FLAGS) -C $(DIR_LIBFT)

$(NAME_CLIENT): $(FILES_CLIENT)
	$(CC) $(CC_FLAGS) $^ -o $(NAME_CLIENT) $(LIBFT_FLAG)

$(NAME_SERVER): $(FILES_SERVER)
	$(CC) $(CC_FLAGS) $^ -o $(NAME_SERVER) $(LIBFT_FLAG)

clean:
	$(RM) $(RM_FLAGS) $(DIR_LIBFT)/*.o $(DIR_CLIENT)*.o $(DIR_SERVER)*.o

fclean: clean
	$(RM) $(RM_FLAGS) $(DIR_LIBFT)/libft.a $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all