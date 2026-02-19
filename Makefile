NAME			=	libpush_swap.a
EXEC         	=	push_swap
CC				=	cc
FLAGS			=	-Wall -Werror -Wextra -g3 -ggdb -MMD -MP
PUB_INCL		=	-I include -I lib/libft
ENGINE_INCL		=	-I src/engine
SRC_DIR			=	src
OBJ_DIR			=	obj
LIB_DIR			=	lib
LIBFT_F			=	$(LIB_DIR)/libft
LIBFTLIB		= 	libft.a
LIBS        	=	-L. -lpush_swap -L$(LIBFT_F) -lft
MAIN_SRCS		=	$(SRC_DIR)/etl/parser.c
MAIN_SRCS		+=	$(SRC_DIR)/etl/validator.c
MAIN_SRCS		+=	$(SRC_DIR)/etl/cleanup.c
MAIN_SRCS		+= 	$(SRC_DIR)/etl/loader.c
MAIN_SRCS		+= 	$(SRC_DIR)/handlers/error.c
MAIN_SRCS		+= 	$(SRC_DIR)/utils/utils.c
# # US.1: Environment - Dynamic Mapping
# SUB_DIRS    = etl logger model solver
# MAIN_SRCS   = $(SRC_DIR)/push_swap.c
# # For each directory in SUB_DIRS, find all .c files
# MAIN_SRCS  += $(foreach dir,$(SUB_DIRS),$(wildcard $(SRC_DIR)/$(dir)/*.c))		
ENGINE_SRCS		=	$(SRC_DIR)/engine/model_api/dll_init.c
#ENGINE_SRCS		+=	$(SRC_DIR)/engine/model_api/dll_getters.c
ENGINE_SRCS		+=	$(SRC_DIR)/engine/model_api/dll_setters.c
ENGINE_SRCS		+=	$(SRC_DIR)/engine/model_api/dll_utils.c
ENGINE_SRCS		+= 	$(SRC_DIR)/engine/solver/ranker.c
ENGINE_SRCS		+= 	$(SRC_DIR)/engine/solver/solver.c
ENGINE_SRCS		+= 	$(SRC_DIR)/engine/solver/moves.c
ENGINE_SRCS		+= 	$(SRC_DIR)/engine/solver/ops_core.c
ENGINE_SRCS		+= 	$(SRC_DIR)/engine/solver/sort_big.c
ENGINE_SRCS		+= 	$(SRC_DIR)/engine/solver/sort_small.c
ENGINE_SRCS		+= 	$(SRC_DIR)/engine/solver/winner.c
ENGINE_SRCS		+= 	$(SRC_DIR)/engine/solver/distance_calc.c
ENGINE_SRCS		+= 	$(SRC_DIR)/engine/solver/solver_utils.c
ENGINE_SRCS		+= 	$(SRC_DIR)/engine/logger/log_ops.c
PROJECT_SRCS	=	$(ENGINE_SRCS) $(MAIN_SRCS)
PROJECT_OBJS	=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(PROJECT_SRCS))
ENGINE_OBJS		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(ENGINE_SRCS))
GREEN			= 	\033[0;32m
GREY			= 	\033[0;90m
RESET			= 	\033[0m

all								:	$(EXEC)
$(ENGINE_OBJS)					:	PRIV_FLAGS := $(ENGINE_INCL)
$(NAME)							:	$(PROJECT_OBJS)
									@echo "$(GREY)$(NAME):$(RESET)Making ar file..."
									cp $(LIBFT_F)/$(LIBFTLIB) $(NAME)
									ar -rcs $(NAME) $(PROJECT_OBJS)
									ranlib $(NAME)
									@echo "$(GREY)$(NAME): $(GREEN)ar file created successfully$(RESET)"

$(EXEC)							:	$(LIBFTLIB) $(NAME) main.c 
									$(CC) $(FLAGS) $(PUB_INCL) main.c $(LIBS) -o $(EXEC)

$(LIBFTLIB)						:
									@$(MAKE) -C $(LIBFT_F)

#removing the -c from compilation which means "no linking"
$(OBJ_DIR)/%.o					:	%.c
									@echo "$(GREY)$(NAME):$(RESET) running the following compiler instruction: $(CC) $(FLAGS) $(PUB_INC) $(PRIV_FLAGS) -c"
									@mkdir -p $(dir $@)
									$(CC) $(FLAGS) $(PUB_INCL) $(PRIV_FLAGS) -c $< -o $@
									@echo "$(GREY)$(NAME): $(GREEN)Objects images created successfully$(RESET)"

-include $(PROJECT_OBJS:.o=.d)

clean	:
			$(MAKE) -C $(LIBFT_F) clean
			@echo "$(GREY)$(NAME):$(RESET) Cleaning object files..."
			$(RM) -r $(OBJ_DIR)
			@echo "$(GREY)$(NAME): $(GREEN)objects removed successfully$(RESET)"

fclean	:	clean
			$(MAKE) -C $(LIBFT_F) fclean
			@echo "$(GREY)$(NAME):$(RESET) Cleaning ar file..."
			rm -f push_swap.d
			rm -f $(NAME)
			@echo "$(GREY)Libft: $(GREEN)$(NAME) was removed successfully$(RESET)"

re		:	fclean all

.PHONY	:	all clean fclean re

#cc -ggdb unit_tests/simpletest.c -o unit_tests/simpletest.out -Iinclude -L. -lftprintf -Llibft -lft