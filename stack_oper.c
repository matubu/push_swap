#include "push_swap.h"

/*
void	swap(t_stack *stack);
void	push(t_stack *stack);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);*/
/*
void	swap(t_stack *stack, int ab)
{
	t_lst	*elm;

	if (ab & 0b10 && stack->a->next)
	{
		elm = stack->a->next;
		stack->a->next = stack->a->next->next;
		stack->a = elm;
	}
	if (ab & 0b01 && stack->b->next)
	{
		elm = stack->b->next;
		stack->b->next = stack->b->next->next;
		stack->b = elm;
	}
	if (ab & 0b11)
		write(1, "ss\n", 3);
	else if (ab & 0b10)
		write(1, "sa\n", 3);
	else if (ab & 0b01)
		write(1, "sb\n", 3);
}

void	push(t_stack *stack, int ab)
{
	t_lst	*elm;

	if (ab & 0b10 && stack->b)
	{
		elm = lstlast(stack->b);
		elm->next = stack->a;
		stack->a = elm;
	}
	else if (ab & 0b01 && stack->a)
	{
	}
	if (ab & 0b10)
		write(1, "pa\n", 3);
	else if (ab & 0b01)
		write(1, "pb\n", 3);
}

void	rotate(t_stack *stack, int ab)
{

}

void	reverse_rotate(t_stack *stack, int ab)
{

}*/
