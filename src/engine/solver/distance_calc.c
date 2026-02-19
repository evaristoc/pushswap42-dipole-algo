#include "engine.h"

static void dist_calc(t_list *b, t_candidate *cd, t_vec *ot, t_3gdz_meta *m)
{
	t_node *t;
	int dist;
	int orient;
	int second_found;

	reverse_rotate(b);
	t = b->head;
	orient = b->head->orientation;
	second_found = 0;
	dist = 0;
	while (t->next)
	{
		if (t->orientation != t->next->orientation) // is it a change of direction? a max or min
		{
			if ((t->rank == m->b_max || t->next->rank == m->b_max) && (cd->nd->rank > m->b_max || (cd->nd->rank < t->rank && cd->nd->rank > t->next->rank) || (cd->nd->rank > t->rank && cd->nd->rank < t->next->rank))) // max
			{
				if (t->rank > t->next->rank) // assign as local max of pole with current lower rank
					ot->otp = t->next->orientation;
				else
					ot->otp = t->orientation;
				ot->obt = ot->otp;
				ot->tp = dist;
				ot->bt = b->size - ot->tp;
				break;
			}
			if ((t->rank == m->b_min || t->next->rank == m->b_min) && (cd->nd->rank < m->b_min || (cd->nd->rank < t->rank && cd->nd->rank > t->next->rank) || (cd->nd->rank > t->rank && cd->nd->rank < t->next->rank))) // min
			{
				if (t->rank < t->next->rank) // assign as local min of pole with current higher rank
					ot->otp = t->next->orientation;
				else
					ot->otp = t->orientation;
				ot->obt = ot->otp;		   // as choice, both have same direction...
				ot->tp = dist;			   // same top distance...
				ot->bt = b->size - ot->tp; // and same bottom distance
				break;
			}
		}
		else
		{
			orient = t->orientation;
			if (orient * t->rank > orient * cd->nd->rank && orient * cd->nd->rank > orient * t->next->rank) // the direction of comparison changes
			{
				if (!second_found) // we have found a slot position closer to the top of the B pile
				{
					ot->otp = orient;
					ot->tp = dist;
					second_found = 1;
				}
				else // we have found a slot position closer to the bottom of the B pile
				{
					ot->obt = orient;
					ot->bt = b->size - dist;
					if (cd->nd->rank > t->rank && dist == 0)
						ot->bt = b->size - dist + 1;
					else
						ot->bt = b->size - dist;
					break;
				}
			}
		}
		if (dist == 0)
		{
			rotate(b);
			t = b->head;
			orient = b->head->orientation;
		}
		else
			t = t->next;
		dist++;
	}
	if (dist == 0)
		rotate(b);
}

void distance_choice(t_list *b, t_candidate *cd, t_3gdz_meta *meta)
{
	t_vec v;

	if (!b || !b->head)
		return;
	dist_calc(b, cd, &v, meta);
	// Lets find which of this two would accomodate this specific candidate:
	// Lets update the scoring...
	if (v.tp <= v.bt) // the shortest distance first
	{
		cd->best_route = FROMTOP;
		cd->dist_b = v.tp;
		cd->nd->orientation = v.otp;
	}
	// from bottom, ALWAYS dist_b > 0 and had to search inside the piles (no need to check boundery nodes)
	else
	{
		cd->dist_b = v.bt;
		cd->nd->orientation = v.obt;
		cd->best_route = FROMBOT;
	}
}
