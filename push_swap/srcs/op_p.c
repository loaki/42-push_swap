#include "push_swap.h"

static void	apply_p(t_stack *dest, t_stack *source)
{
	int i;
	int push;

	i = 0;
	if(source->size == 0)
		return;
	push = source->tab[0];
	source->size--;
	dest->size++;
	while(i < source->size || i < dest->size)
	{
		if(i < dest->size)
			dest->tab[dest->size - i] = dest->tab[dest->size - i - 1];
		if(i < source->size)
			source->tab[i] = source->tab[i + 1];
		i++;
	}
	dest->tab[0] = push;
}

void		op_p(t_struct *st, char *instr)
{
	if (ft_strcmp(instr, "pa") == 0)
		apply_p(&st->stack_a, &st->stack_b);
	if (ft_strcmp(instr, "pb") == 0)
		apply_p(&st->stack_b, &st->stack_a);
}