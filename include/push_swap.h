#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"

#define INTMAX "2147483647"
#define INTMIN "2147483648"

typedef struct s_list t_list;

typedef struct t_ctx
{
	int max_bits;
} t_ctx;

typedef void (*t_solver)(t_list *list_a, t_list *list_b, t_ctx *ctx);
typedef void (*t_handler_func)(t_list *list_a, t_list *list_b);
typedef int (*t_op)(t_list *);

// typedef struct s_oper
// {
// 	t_oper logic;
// 	char *name;
// } t_oper;

typedef struct s_handler_map
{
	t_handler_func *handler;

} t_handler_map;

/**
 * @brief model api (dll)
 */

t_list *list_create(char name);
void list_destroy(t_list **list);
int list_push_start(t_list *list, int value, int rank, int dir);
int list_push_end(t_list *list, int value, int rank, int dir);
int list_pop_start(t_list *list, int *out_value, int *out_rank, int *out_dir);
int list_pop_end(t_list *list, int *out_value, int *out_rank, int *out_dir);
int is_duplicate(t_list *list, int value);
int *list_to_array(t_list *list);
int is_sorted(t_list *a);
int get_stack_size(t_list *list);

/**
 * @brief parser
 */

int is_valid_input(char **input);
char **get_input(int argc, char **argv);
void input_arr_destroy(char ***gotinput);
int loader(t_list **a, char **input, char name);
int parser(int argc, char **argv, char ***input_ptr);

int report_error(void);

int ft_abs(int n1, int n2);
int ft_min(int n1, int n2);

int ranker(t_list *a);
int solver(t_list *a, t_list *b);
