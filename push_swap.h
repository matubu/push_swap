#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *nptr, int *v);

char	**split(const char *s, char c, int *len);
int		free_splits(char **splits, int n);

typedef struct s_lst {
	int				v;
	struct s_lst	*next;
}	t_lst;

t_lst	*lstnew(int v);
int		lstsize(t_lst *lst);
t_lst	**lstat(t_lst **a, int i);
t_lst	**lstlast(t_lst **lst);
void	lstclear(t_lst **lst);

void	lstswap(t_lst **a);
void	lstpush(t_lst **a, t_lst **b);
void	lstrotate(t_lst **a);
void	lstrrotate(t_lst **a);

typedef struct s_stack {
	t_lst	*a;
	t_lst	*b;
}	t_stack;

t_stack	*stacknew(char **input);
void	stackclear(t_stack *stack);

void	swap(t_stack *stack);
void	push(t_stack *stack);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);

void	err(void);

//lstget
//lstmin
//lstmax

#endif
