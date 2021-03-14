#include "push_swap.h"

void very_bad_algo(t_struct *st)
{
    int i;
    int low;
    int index;

    while(st->stack_a.size > 1)
    {
        i = 0;
        low = st->stack_a.tab[0];
        index = 0;
        while(i < st->stack_a.size)
        {
            if(st->stack_a.tab[i] < low)
            {
                low = st->stack_a.tab[i];
                index = i;
            }
            i++;
        }
        st->instr = "ra";
        while(index > 0)
        {
            exec_instr(st);
            index--;
        }
        st->instr = "pb";
        exec_instr(st);
    }
    while(st->stack_b.size > 0)
    {
        st->instr = "pa";
        exec_instr(st);
    }
}

int sort_stack(t_struct *st)
{
    very_bad_algo(st);
    //print_stacks(st);
}