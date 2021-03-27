#include "push_swap.h"

void init_struct(t_struct *st)
{
    st->stack_a.tab = NULL;
	st->stack_a.size = 0;
	st->stack_b.tab = NULL;
	st->stack_b.size = 0;
	st->pivot.tab = NULL;
	st->pivot.size = 0;
	st->working_stack.tab = NULL;
	st->working_stack.size = 0;
	st->instr = 0;
	st->nb_instr = 0;
}

int free_struct(t_struct *st)
{
    if(st->stack_a.tab)
	{
		free(st->stack_a.tab);
		st->stack_a.tab = NULL;
	}
	if(st->stack_b.tab)
	{
		//seg fault ?
		free(st->stack_b.tab);
		st->stack_b.tab = NULL;
	}
	if(st->pivot.tab)
	{
		free(st->pivot.tab);
		st->pivot.tab = NULL;
	}
	if(st->working_stack.tab)
	{
		free(st->working_stack.tab);
		st->working_stack.tab = NULL;
	}
	if(st->instr)
		free(st->instr);
	return (0);
}