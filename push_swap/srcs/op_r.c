#include "push_swap.h"

static void	apply_r(t_stack *stack)
{
	int i;
	int top;

	i = 0;
	top = stack->tab[0];
	while (i < stack->size)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[stack->size - 1] = top;
}

void		op_r(t_struct *st, char *instr)
{
	if (st->stack_a.size > 1 && (ft_strcmp(instr, "ra") == 0 || ft_strcmp(instr, "rr") == 0))
		apply_r(&st->stack_a);
	if (st->stack_b.size > 1 && (ft_strcmp(instr, "rb") == 0 || ft_strcmp(instr, "rr") == 0))
		apply_r(&st->stack_b);
}