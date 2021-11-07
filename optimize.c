/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:46:32 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/07 13:34:53 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mid(t_lst *moves, int n)
{
	int	move;

	move = 0;
	while (n-- && moves)
	{
		move |= moves->v << n * 6;
		moves = moves->next;
	}
	return (move);
}

typedef struct s_opti {
	int	size;
	int	mid;
	int	a;
	int	b;
}	t_opti;

//moves list order is inverted
static int	replace_moves_pattern(t_lst **m)
{
	const t_opti	opti[7] = {{2, PUSH_B | PUSH_A << 6, 0, 0},
		{2, ROTATE_A | RROTATE_A << 6, 0, 0},
		{2, RROTATE_A | ROTATE_A << 6, 0, 0},
		{3, PUSH_B | ROTATE_A << 6 | PUSH_A << 12, ROTATE_A, SWAP_A},
		{3, ROTATE_A | PUSH_A << 6 | RROTATE_A << 12, SWAP_A, PUSH_A},
		{4, PUSH_B | SWAP_A << 6 | PUSH_A << 12 | ROTATE_A << 18,
			SWAP_A, ROTATE_A},
		{4, ROTATE_A | PUSH_B << 6 | RROTATE_A << 12 | PUSH_A << 18, SWAP_A, 0}
	};
	int				i;

	i = -1;
	while (++i < 7)
	{
		if (mid(*m, opti[i].size) == opti[i].mid)
		{
			lstdeln(m, opti[i].size - !!opti[i].a - !!opti[i].b);
			if (opti[i].b)
				(*m)->next->v = opti[i].b;
			if (opti[i].a)
				(*m)->v = opti[i].a;
			return (1);
		}
	}
	return (0);
}

int	optimize_moves(t_lst **m)
{
	int		b;

	b = 0;
	if (*m == NULL)
		return (0);
	while (optimize_moves(&(*m)->next))
		b = 1;
	return (replace_moves_pattern(m) || b);
}
