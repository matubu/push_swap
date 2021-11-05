#include "push_swap.h"

int	lstgetclosest(t_lst *a, int v, t_lst **closest_elm)
{
	int		diff;
	int		bestdiff;
	int		best;
	int		i;
	
	if (a == NULL)
		return (0);
	bestdiff = ft_abs(v - a->v);
	i = 1;
	best = 1;
	*closest_elm = a;
	while (a->next && i++)
	{
		a = a->next;
		diff = ft_abs(v - a->v);
		if (diff < bestdiff)
		{
			bestdiff = diff;
			best = i;
			*closest_elm = a;
		}
	}
	return (best);
}

int	lstgetsmallest(t_lst *a)
{
	int		bestv;
	int		best;
	int		i;
	
	if (a == NULL)
		return (0);
	bestv = a->v;
	i = 1;
	best = 1;
	while (a->next && i++)
	{
		a = a->next;
		if (a->v < bestv)
		{
			bestv = a->v;
			best = i;
		}
	}
	return (best);

}
