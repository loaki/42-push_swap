#include "push_swap.h"

static void	apply_rr(t_stack *stack)
{
	int i;
	int end;

	i = 1;
	end = stack->tab[stack->size - 1];
	while (i < stack->size)
	{
		stack->tab[stack->size - i] = stack->tab[stack->size - i - 1];
		i++;
	}
	stack->tab[0] = end;
}

void		op_rr(t_struct *st, char *instr)
{
	if (st->stack_a.size > 1
		&& (ft_strcmp(instr, "rra") == 0 || ft_strcmp(instr, "rrr") == 0))
		apply_rr(&st->stack_a);
	if (st->stack_b.size > 1
		&& (ft_strcmp(instr, "rrb") == 0 || ft_strcmp(instr, "rrr") == 0))
		apply_rr(&st->stack_b);
}