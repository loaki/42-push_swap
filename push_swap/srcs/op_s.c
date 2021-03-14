#include "push_swap.h"

static void	apply_s(t_stack *stack)
{
	int tmp;

	if (1 <= stack->size)
	{
		tmp = stack->tab[0];
		stack->tab[0] = stack->tab[1];
		stack->tab[1] = tmp;
	}
}

void		op_s(t_struct *st, char *instr)
{
	if (ft_strcmp(instr, "sa") == 0 || ft_strcmp(instr, "ss") == 0)
		apply_s(&st->stack_a);
	if (ft_strcmp(instr, "sb") == 0 || ft_strcmp(instr, "ss") == 0)
		apply_s(&st->stack_b);
}