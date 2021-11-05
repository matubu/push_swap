#include "push_swap.h"

t_lst	*lstswap(t_lst **a)
{
	int	v;

	v = (*a)->v;
	(*a)->v = (*a)->next->v;
	(*a)->next->v = v;
	return (*lstlast(a));
}

t_lst	*lstpush(t_lst **a, t_lst **b)
{
	t_lst	*elm;

	elm = *a;
	*a = (*a)->next;
	elm->next = *b;
	*b = elm;
	return (*lstlast(a));
}

t_lst	*lstrotate(t_lst **a)
{
	t_lst	*elm;

	(*lstlast(a))->next = *a;
	elm = *a;
	*a = (*a)->next;
	elm->next = NULL;
	return (*lstlast(a));
}

t_lst	*lstrrotate(t_lst **a)
{
	t_lst	*elm;
	t_lst	*last;

	last = *lstlast(a);
	*lstat(a, -1) = NULL;
	elm = *a;
	*a = last;
	last->next = elm;
	return (*lstlast(a));
}

