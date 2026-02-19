#include "engine.h"
#include <stdio.h>

static void moves_in_a(t_list *a, t_candidate *w)
{
	int i;

	i = 0;
	while (i < w->dist_a)
	{
		if (w->pos == TOP)
			r(a);
		else
			rr(a);
		i++;
	}
}

static void double_moves(t_list *a, t_list *b, t_candidate *w)
{
	int i;

	i = 0;
	while (i < w->doub_dist)
	{
		if (w->pos == TOP)
			drr(a, b);
		else
			rrr(a, b);
		i++;
	}
}

static void moves_in_b(t_list *b, t_candidate *w)
{
	int i;

	i = 0;
	while (i < w->dist_b)
	{
		if (w->best_route == FROMTOP)
			r(b);
		else
			rr(b);
		i++;
	}
}

static int fillback_a(t_list *a, t_list *b)
{
	while (b->head)
	{
		if (b->tail)
		{
			if (b->head->rank > b->tail->rank)
				p(b, a);
			else
			{
				rr(b);
				p(b, a);
			}
		}
	}
	return (1);
}

static void inverse_sort(t_list *pile, t_3gdz_meta *meta)
{
	while (pile->head->rank != meta->b_max)
		r(pile);
	//	printf("1111 %i %i\n", pile->head->rank, meta->b_max);
}

int sort_big(t_list *a, t_list *b)
{
	t_candidate challenger;
	t_candidate winner;
	t_node *temp;
	t_3gdz_meta meta;
	int distance_budget;
	int search;

	primer(a, b, &meta);
	update_meta_after_push(b, &meta);
	while (a->size > 0)
	{
		// comparing candidates on top of A
		cands_init(a->head, 0, &challenger, FROMTOP);
		distance_choice(b, &challenger, &meta);
		score_calc(&challenger);
		distance_budget = challenger.d_score;
		winner = challenger;
		search = 1;
		if (a->head->next)
		{
			temp = a->head->next;
			while (temp && search <= distance_budget)
			{
				cands_init(temp, search, &challenger, FROMTOP);
				distance_choice(b, &challenger, &meta);
				score_calc(&challenger);
				select_winner(&winner, &challenger);
				temp = temp->next;
				search++;
			}
		}
		// comparing candidates on bottom of A
		// use data from the winner of the top when checking from bottom
		distance_budget = winner.d_score;
		search = 1;
		if (a->tail)
		{
			temp = a->tail;
			while (temp && search <= distance_budget)
			{
				cands_init(temp, search, &challenger, FROMBOT);
				challenger.pos = BOTTOM;
				distance_choice(b, &challenger, &meta);
				score_calc(&challenger);
				select_winner(&winner, &challenger);
				temp = temp->prev;
				search++;
			}
		}
		double_moves(a, b, &winner);
		moves_in_a(a, &winner);
		moves_in_b(b, &winner);
		p(a, b);
		update_meta_after_push(b, &meta);
	}
	inverse_sort(b, &meta);
	fillback_a(a, b);
	return (1);
}
