#include "engine.h"
#include <stdio.h>

static void dist_calc(t_list *b, t_candidate *cd, t_vec *dt, t_3gdz_meta *m)
{
	t_node *t;
	int dist;
	int d;
	int second_found;

	reverse_rotate(b);
	t = b->head;
	d = b->head->direction;
	second_found = 0;
	dist = 0;
	while (t->next)
	{
		if (t->direction != t->next->direction) // is it a change of direction? a max or min
		{
			if ((t->rank == m->b_max || t->next->rank == m->b_max) && (cd->nd->rank > m->b_max || (cd->nd->rank < t->rank && cd->nd->rank > t->next->rank) || (cd->nd->rank > t->rank && cd->nd->rank < t->next->rank))) // max
			{
				if (t->rank > t->next->rank) // assign to the lower local max
					dt->dtp = t->next->direction;
				else
					dt->dtp = t->direction;
				dt->dbt = dt->dtp;		   // both have same direction...
				dt->tp = dist;			   // TODO: Check this...
				dt->bt = b->size - dt->tp; // TODO: Check this...
				break;
			}
			if ((t->rank == m->b_min || t->next->rank == m->b_min) && (cd->nd->rank < m->b_min || (cd->nd->rank < t->rank && cd->nd->rank > t->next->rank) || (cd->nd->rank > t->rank && cd->nd->rank < t->next->rank))) // min
			{
				if (t->rank < t->next->rank) // assign to the higher local min
					dt->dtp = t->next->direction;
				else
					dt->dtp = t->direction;
				dt->dbt = dt->dtp;		   // both have same direction...
				dt->tp = dist;			   // TODO: Check this...
				dt->bt = b->size - dt->tp; // TODO: Check this...
				break;
			}
		}
		else
		{
			d = t->direction;
			if (d * t->rank > d * cd->nd->rank && d * cd->nd->rank > d * t->next->rank) // the direction of comparison changes
			{
				if (!second_found)
				{
					// dt->tp = dist + 1; // TODO: Check this...
					dt->dtp = d;
					dt->tp = dist; // TODO: Check this...
					// if (cd->nd->rank < t->rank)
					// 	dt->tp = dist + 1; // TODO: Check this...
					// else
					// 	dt->tp = dist; // TODO: Check this...
					second_found = 1;
				}
				else
				{
					dt->dbt = d;
					dt->bt = b->size - dist;
					if (cd->nd->rank > t->rank && dist == 0)
						dt->bt = b->size - dist + 1; // TODO: Check this...
					else
						dt->bt = b->size - dist; // TODO: Check this...
					break;
				}
			}
		}
		if (dist == 0)
		{
			rotate(b);
			t = b->head;
			d = b->head->direction;
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
	// int inters_min;
	// int is_minmin;
	// int is_topmin;
	// int d;

	if (!b || !b->head)
		return;
	// is_minmin = cd->nd->rank < meta->b_min;
	// inters_min = b->head->rank == meta->b_min || b->tail->rank == meta->b_min;
	// is_topmin = inters_min && (is_minmin || (cd->nd->rank < b->head->rank || cd->nd->rank < b->tail->rank));
	dist_calc(b, cd, &v, meta);
	// Lets find which of this two would accomodate this specific candidate:
	// Lets update the scoring...
	if (v.tp <= v.bt) // the shortest distance first
	{
		cd->best_route = FROMTOP;
		cd->dist_b = v.tp;
		cd->nd->direction = v.dtp;
		// dist_b == 0; three cases: boundery nodes are either mins, maxs or btwns
		// if (cd->dist_b == 0)
		// {
		// 	if (is_topmin)
		// 	{
		// 		if (b->head->rank < b->tail->rank) // assignment to mins
		// 			cd->nd->direction = b->tail->direction;
		// 		else
		// 			cd->nd->direction = b->head->direction;
		// 	}
		// 	else
		// 	{
		// 		if (b->head->rank > b->tail->rank) // assignment to maxs or btwns
		// 			cd->nd->direction = b->tail->direction;
		// 		else
		// 			cd->nd->direction = b->head->direction;
		// 	}
		// }
		// dist_b > 0 but still from top, then it had to find inside the piles
		// if (cd->dist_b > 0 && cd->dist_b >= cd->dist_a)
		// {
		// 	cd->nd->direction = v.dtp;
		// 	// cd->doub_dist = cd->dist_a;
		// 	// cd->dist_b = cd->dist_b - cd->dist_a;
		// 	// cd->dist_a = 0;
		// }
		// if (cd->dist_a > 0 && cd->dist_a >= cd->dist_b)
		// {
		// 	//cd->nd->direction = v.dtp;
		// 	// cd->doub_dist = cd->dist_b;
		// 	// cd->dist_a = cd->dist_a - cd->dist_b;
		// 	// cd->dist_b = 0;
		// }
	}
	// from bottom, ALWAYS dist_b > 0 and had to search inside the piles (no need to check boundery nodes)
	else
	{
		cd->dist_b = v.bt;
		cd->nd->direction = v.dbt;
		cd->best_route = FROMBOT;
		// if (cd->dist_b > 0 && cd->dist_b >= cd->dist_a)
		// {
		// 	cd->doub_dist = cd->dist_a;
		// 	cd->dist_b = cd->dist_b - cd->dist_a;
		// 	cd->dist_a = 0;
		// }
		// else if (cd->dist_a > 0 && cd->dist_a >= cd->dist_b)
		// {
		// 	cd->doub_dist = cd->dist_b;
		// 	cd->dist_a = cd->dist_a - cd->dist_b;
		// 	cd->dist_b = 0;
		// }
	}
}
