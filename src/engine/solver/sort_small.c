#include "engine.h"

// static void update_dir(t_list *p)
// {
// 	t_node *temp;
// 	int index;

// 	temp = p->head;
// 	index = 0;
// 	while (temp)
// 	{
// 		if (index > 2)
// 			temp->direction = -1;
// 		temp = temp->next;
// 	}
// }

// void primer(t_list *a, t_list *b, t_3gdz_meta *meta)
// {
// 	if (a->head->rank > a->tail->rank && a->head->rank > a->head->next->rank)
// 	{
// 		p(a, b);
// 		if (a->head->rank < a->tail->rank)
// 		{
// 			rr(a);
// 			p(a, b);
// 			p(a, b);
// 		}
// 		else
// 		{
// 			p(a, b);
// 			rr(a);
// 			p(a, b);
// 		}
// 	}
// 	else if (a->head->next->rank > a->tail->rank && a->head->next->rank > a->head->rank)
// 	{
// 		swap(a);
// 		p(a, b);
// 		if (a->head->rank < a->tail->rank)
// 		{
// 			rr(a);
// 			p(a, b);
// 			p(a, b);
// 		}
// 		else
// 		{
// 			p(a, b);
// 			rr(a);
// 			p(a, b);
// 		}
// 	}
// 	else if (a->tail->rank > a->head->next->rank && a->tail->rank > a->head->rank)
// 	{
// 		rr(a);
// 		p(a, b);
// 		if (a->head->rank < a->tail->rank)
// 		{
// 			rr(a);
// 			p(a, b);
// 			p(a, b);
// 		}
// 		else
// 		{
// 			p(a, b);
// 			rr(a);
// 			p(a, b);
// 		}
// 	}
// 	b->head->direction = -1;
// 	b->head->next->direction = -1;
// 	b->tail->direction = -1;
// 	if (a->head->rank < a->tail->rank && a->head->rank < a->head->next->rank)
// 	{
// 		p(a, b);
// 		if (a->head->rank > a->tail->rank)
// 		{
// 			rr(a);
// 			p(a, b);
// 			p(a, b);
// 		}
// 		else
// 		{
// 			p(a, b);
// 			rr(a);
// 			p(a, b);
// 		}
// 	}
// 	else if (a->head->next->rank < a->tail->rank && a->head->next->rank < a->head->rank)
// 	{
// 		swap(a);
// 		p(a, b);
// 		if (a->head->rank > a->tail->rank)
// 		{
// 			rr(a);
// 			p(a, b);
// 			p(a, b);
// 		}
// 		else
// 		{
// 			p(a, b);
// 			rr(a);
// 			p(a, b);
// 		}
// 	}
// 	else if (a->tail->rank < a->head->next->rank && a->tail->rank < a->head->rank)
// 	{
// 		rr(a);
// 		p(a, b);
// 		if (a->head->rank > a->head->next->rank)
// 		{
// 			swap(a);
// 			p(a, b);
// 			p(a, b);
// 		}
// 		else
// 		{
// 			p(a, b);
// 			p(a, b);
// 		}
// 	}
// 	b->head->direction = 1;
// 	b->head->next->direction = 1;
// 	b->head->next->next->direction = 1;
// 	update_meta_after_push(b, meta);
// }

void primer(t_list *a, t_list *b, t_3gdz_meta *meta)
{
	if (a->head->rank > a->head->next->rank)
	{
		p(a, b);
		p(a, b);
	}
	else
	{
		s(a);
		p(a, b);
		p(a, b);
	}
	b->head->direction = -1;
	b->head->next->direction = -1;
	if (a->head->rank > a->head->next->rank)
	{
		s(a);
		p(a, b);
		p(a, b);
	}
	else
	{
		p(a, b);
		p(a, b);
	}
	update_meta_after_push(b, meta);
}

static void sort_three(t_list *p, t_node *top, t_node *mid, t_node *bot)
{
	if (top->rank > mid->rank && top->rank < bot->rank)
		swap(p);
	else if (top->rank > mid->rank && top->rank > bot->rank)
	{
		if (mid->rank < bot->rank)
			rotate(p);
		else
		{
			swap(p);
			reverse_rotate(p);
		}
	}
	else if (top->rank < mid->rank && mid->rank > bot->rank)
	{
		if (top->rank < bot->rank)
		{
			swap(p);
			rotate(p);
		}
		else
			reverse_rotate(p);
	}
}

int sort_less_three(t_list *p)
{
	t_node *top;
	t_node *mid;
	t_node *bot;

	if (!p || !p->head)
		return (0);
	top = p->head;
	if (top->next == NULL)
		return (1);
	mid = top->next;
	if (mid->next == NULL)
	{
		if (top->rank < mid->rank)
			return (1);
		else
		{
			swap(p);
			return (1);
		}
	}
	bot = mid->next;
	sort_three(p, top, mid, bot);
	return (1);
}

static void find_mins(t_list *a, t_list *b, int *rank)
{
	if (a->size == 3)
		return;

	// 1. THE OPPORTUNITY CHECK
	// If the next rank is already at one of the 3 points, take it!
	if (a->head->rank == *rank)
	{
		push_btwn(a, b);
		(*rank)++;
		return (find_mins(a, b, rank)); // RE-EVALUATE state immediately
	}
	if (a->head->next->rank == *rank)
	{
		swap(a);
		// Do not rotate! Swap might have put the rank at the head.
		return (find_mins(a, b, rank));
	}
	if (a->tail->rank == *rank)
	{
		reverse_rotate(a);
		return (find_mins(a, b, rank));
	}

	// 2. THE LAST RESORT
	// Only if the 3 points are exhausted do we turn the wheel.
	rotate(a);
	find_mins(a, b, rank);
}

int sort_five(t_list *a, t_list *b)
{
	int rank;

	rank = 0;
	while (a->size > 3)
	{
		find_mins(a, b, &rank);
		rotate(a);
	}
	if (!sort_less_three(a))
		return (0);
	if (b->head->next)
	{
		if (b->head < b->head->next)
			rotate(b);
	}
	while (b->size > 0)
		push_btwn(b, a);
	return (1);
}
