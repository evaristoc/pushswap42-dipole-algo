#include "engine.h"

void cands_init(t_node *chall, int dist_a, t_candidate *cand, int best_route)
{
	cand->best_route = best_route;
	cand->d_score = 0;
	cand->dist_a = dist_a;
	cand->dist_b = 0;
	cand->doub_dist = 0;
	cand->nd = chall;
	cand->pos = TOP;
}

void score_calc(t_candidate *cand)
{
	cand->d_score = cand->dist_a + cand->dist_b + cand->doub_dist;
}

void select_winner(t_candidate *w, t_candidate *challenger)
{
	// score_calc(w);
	// score_calc(challenger);
	if (challenger->d_score < w->d_score)
		*w = *challenger;
	else if (challenger->d_score == w->d_score)
	{
		if (challenger->nd->rank < w->nd->rank)
			*w = *challenger;
	}
}
