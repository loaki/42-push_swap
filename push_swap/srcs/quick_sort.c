#include "push_swap.h"

void    set_working_stack(t_struct *st, char key)
{

}

void    add_pivot(t_struct *st, int pivot)
{
    int i;
    int tmp;

    i = st->pivot.size;
    while(i >= 0)
    {
        if(i == 0 || st->pivot.tab[i - 1] < pivot)
        {
            st->pivot.tab[i] = pivot;
            break;
        }
        else
            st->pivot.tab[i] = st->pivot.tab[i - 1];
        i--;
    }
    st->pivot.size++;
}

int    get_pivot(t_struct *st)
{
    int i;
    int moy;
    int pivot;

    i = 0;
    pivot = st->working_stack.tab[0];
    while(i < st->working_stack.size)
    {
        moy += st->working_stack.tab[i];
        i++;
    }
    moy /= i;
    i = 0;
    while(i < st->working_stack.size)
    {
        if(abs(pivot - moy) > abs(st->working_stack.tab[i] - moy))
            pivot = st->working_stack.tab[i];
        i++;
    }
    return(pivot);
}

void    partition(t_struct *st, char key)
{
    int pivot;
    int i;

    i = 0;
    set_working_stack(st, key);
    pivot = get_pivot(st);
    add_pivot(st, pivot);
    if(key == 'a')
    {
        while(i < st->stack_a.size)
        {
            if(st->stack_a.tab[0] > pivot)
            {
                printf("pb\n");
		        st->instr = "pb";
                exec_instr(st);
            }
            else
            {
                printf("ra\n");
		        st->instr = "ra";
                exec_instr(st);
                i++;
            }
        }
    }
    if(key == 'b')
    {
        while(i < st->stack_b.size)
        {
            if(st->stack_b.tab[0] > pivot)
            {
                printf("pa\n");
		        st->instr = "pa";
                exec_instr(st);
            }
            else
            {
                printf("rb\n");
		        st->instr = "rb";
                exec_instr(st);
                i++;
            }
        }
    }
}

int    quick_sort(t_struct *st)
{
    int *working_stack;

    if(!(st->pivot.tab = (int*)malloc(sizeof(int) * (st->stack_a.size))))
        return(0);
    if(!(st->working_stack.tab = (int*)malloc(sizeof(int) * (st->stack_a.size))))
        return(0);
    while(!check_sort(st) && !check_rsort(st))
    {
        while(!check_sort(st) && st->stack_a.size > 1)
            partition(st, 'a');
        while(!check_rsort(st) && st->stack_b.size > 1)
            partition(st, 'b');
    }
    while (st->stack_b.size != 0)
    {
        printf("pa\n");
		st->instr = "pa";
        exec_instr(st);
    }
    return(1);
}