/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:06:17 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/07 12:23:03 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *nptr, int *v);
int		ft_abs(int v);

char	**split(const char *s, char c, int *len);
int		free_splits(char **splits, int n);

typedef struct s_lst {
	int				v;
	struct s_lst	*next;
}	t_lst;

t_lst	*lstnew(int v);
int		lstsize(t_lst *lst);
t_lst	**lstlast(t_lst **lst);
void	lstclear(t_lst **lst);
void	lstdeln(t_lst **lst, int n);

void	lstswap(t_lst **a);
void	lstpush(t_lst **a, t_lst **b);
void	lstrotate(t_lst **a);
void	lstrrotate(t_lst **a);
int		issorted(t_lst *lst);

int		lstgetclosest(t_lst *a, int v);
int		lstgetsmallest(t_lst *a);
t_lst	**lstat(t_lst **a, int i);
int		lstvat(t_lst *a, int i);
int		lstcontains(t_lst *a, int v);

typedef struct s_stack {
	t_lst	*a;
	t_lst	*b;
	t_lst	*moves;
}	t_stack;

enum e_action {
	STACK_A=		0b000010,
	STACK_B=		0b000001,
	STACK_BOTH=		0b000011,
	SWAP=			0b000100,
	SWAP_A=			SWAP | STACK_A,
	SWAP_B=			SWAP | STACK_B,
	SWAP_BOTH=		SWAP | STACK_BOTH,
	PUSH=			0b001000,
	PUSH_A=			PUSH | STACK_A,
	PUSH_B=			PUSH | STACK_B,
	ROTATE=			0b010000,
	ROTATE_A=		ROTATE | STACK_A,
	ROTATE_B=		ROTATE | STACK_B,
	ROTATE_BOTH=	ROTATE | STACK_BOTH,
	RROTATE=		0b100000,
	RROTATE_A=		RROTATE | STACK_A,
	RROTATE_B=		RROTATE | STACK_B,
	RROTATE_BOTH=	RROTATE | STACK_BOTH,
};

t_stack	*stacknew(char **input, t_stack	*stack);
void	stackclear(t_stack *stack);

void	swap(t_stack *stack, enum e_action on);
void	push(t_stack *stack, enum e_action on);
void	rotate(t_stack *stack, enum e_action on);
void	rrotate(t_stack *stack, enum e_action on);

int		optimize_moves(t_lst **m);

void	find_lower_cost(t_stack *stack);
void	rmove(t_stack *stack, int i);

void	err(void);

#endif
