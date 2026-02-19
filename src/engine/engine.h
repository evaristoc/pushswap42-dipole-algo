#include "push_swap.h"

typedef struct s_node
{
	int value;
	int rank;
	int orientation;
	struct s_node *next;
	struct s_node *prev;
} t_node;

/**
 * @brief making use of an opaque pointer to keep a higher level
 * of generalization of the functionality. This struct can
 * be anything, but in this case it defines a pointer
 * that will navigate through a doubly linked list
 */
struct s_list
{
	char name;
	t_node *head;
	t_node *tail;
	int size;
};

typedef enum e_route
{
	FROMTOP,
	FROMBOT
} t_route;

typedef enum e_who
{
	TOP,
	SWAP,
	BOTTOM
} t_who;

typedef struct s_candidate
{
	t_node *nd;
	t_who pos;
	t_route best_route;
	int dist_a;
	int doub_dist;
	int dist_b;
	int d_score;
} t_candidate;

typedef struct s_distances
{
	int tp;
	int bt;
	int otp;
	int obt;
} t_vec;

typedef struct s_3gdz_meta
{
	int b_max;
	int b_min;
	int b_negmax;
	int b_negmin;
	int median;
} t_3gdz_meta;

typedef struct s_gate
{
	t_node *target_node; // The 'High' neighbor in Stack B (the entry point)
	int direction;		 // 1 for Positive Cone, -1 for Negative Cone
	int cost_b;			 // How many moves to get this gate to the top of B
	int is_seam;		 // Boolean: Is this the Tail-to-Head transition?
} t_gate;

int find_min(t_list *p);
int find_max(t_list *p);
int median(t_list *pile);

void update_meta_after_push(t_list *pile, t_3gdz_meta *meta);

int swap(t_list *pile);
int rotate(t_list *pile);
int reverse_rotate(t_list *pile);
int push_btwn(t_list *src, t_list *dest);
int double_rotate(t_list *pile1, t_list *pile2);
int double_rev_rotate(t_list *pile1, t_list *pile2);

void cands_init(t_node *chall, int dist_a, t_candidate *cand, int best_route);
void score_calc(t_candidate *cand);
void distance_choice(t_list *b, t_candidate *cd, t_3gdz_meta *meta);
void select_winner(t_candidate *w, t_candidate *challenger);

void moves_logger(t_list *pile, const char *funcname);

int p(t_list *src, t_list *dest);
int s(t_list *pile);
int r(t_list *pile);
int rr(t_list *pile);
int drr(t_list *pile1, t_list *pile2);
int rrr(t_list *pile1, t_list *pile2);

void primer(t_list *a, t_list *b, t_3gdz_meta *meta);
int sort_less_three(t_list *p);
int sort_five(t_list *a, t_list *b);
int sort_big(t_list *a, t_list *b);