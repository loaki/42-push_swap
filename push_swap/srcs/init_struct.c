#include "push_swap.h"

void init_struct(t_struct *st)
{
    st->stack_a.tab = NULL;
	st->stack_a.size = 0;
	st->stack_b.tab = NULL;
	st->stack_b.size = 0;
	st->instr = 0;
}

int free_struct(t_struct *st)
{
    if (st->stack_a.tab)
	{
		free(st->stack_a.tab);
		st->stack_a.tab = NULL;
	}
	if (st->stack_b.tab)
	{
		free(st->stack_b.tab);
		st->stack_b.tab = NULL;
	}
	return (0);
}