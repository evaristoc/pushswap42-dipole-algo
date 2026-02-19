# === Variables ===
SRC				=	islower isupper isascii \
					isalpha isprint isdigit \
					isalnum tolower toupper \
					strlen strchr strlcpy \
					strlcat memset bzero \
					strcmp strncmp strnstr \
					memcpy memmove memchr memcmp \
					strrchr atoi calloc strdup \
					substr split putstr_fd \
					putchar_fd strmapi strtrim \
					strjoin itoa putendl_fd \
					putnbr_fd striteri numlen

NAME			=	libft.a
SRCC			=	$(patsubst %,ft_%.c, $(SRC))
OBJ				=	$(patsubst %.c,%.o,$(SRCC))
LIB_HEAD		=	.
CFLAGS			=	-Wall -Werror -Wextra -ggdb
DEBUGGING_F		=	-ggdb
GREEN			= 	\033[0;32m
GREY			= 	\033[0;90m
RED				= 	\033[0;31m
RESET			= 	\033[0m

# === Default Target ===

all				:	$(NAME)

# === Build Static Library ===

$(NAME)			:	$(OBJ)
					@echo "$(GREY)Libft:$(RESET)Making ar file..."
					ar -rcs $@ $^
					@echo "$(GREY)Libft: $(GREEN)ar file created successfully$(RESET)"

%.o				:	%.c $(HEADER)
					@echo "$(GREY)Libft:$(RESET) running the following compiler instruction: $(CC) $(CFLAGS) -c $< -o"
					cc $(CFLAGS) -c $< -o $@ -I $(LIB_HEAD)
					@echo "$(GREY)Libft: $(GREEN)Objects images created successfully$(RESET)"

# === Clean Rules ===

clean			:
					@echo "$(GREY)Libft:$(RESET) Cleaning object files..."
					rm -f $(OBJ)
					@echo "$(GREY)Libft: $(GREEN)objects removed successfully$(RESET)"

fclean			:	clean
					@echo "$(GREY)Libft:$(RESET) Cleaning ar file..."
					rm -f $(NAME)
					@echo "$(GREY)Libft: $(GREEN)$(NAME) was removed successfully$(RESET)"

# === Remake Rules ===

re				:	fclean all


# 					THE ORDER OF THE FLAGS IS IMPORTANT!
# 					cc -fsanitize=address -g ft_strsub.c -L. -l:libft.a -o ft_strsub.out

# === Phony Targets ===
#phonying the rules so they are executed not matter what, they are true function arguments
.PHONY			:	all clean fclean re

