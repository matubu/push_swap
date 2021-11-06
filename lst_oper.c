#include "push_swap.h"

void	lstswap(t_lst **a)
{
	int	v;

	v = (*a)->v;
	(*a)->v = (*a)->next->v;
	(*a)->next->v = v;
}

void	lstpush(t_lst **a, t_lst **b)
{
	t_lst	*elm;

	elm = *a;
	*a = (*a)->next;
	elm->next = *b;
	*b = elm;
}

void	lstrotate(t_lst **a)
{
	t_lst	*elm;

	(*lstlast(a))->next = *a;
	elm = *a;
	*a = (*a)->next;
	elm->next = NULL;
}

void	lstrrotate(t_lst **a)
{
	t_lst	*elm;
	t_lst	*last;

	last = *lstlast(a);
	*lstat(a, -1) = NULL;
	elm = *a;
	*a = last;
	last->next = elm;
}

