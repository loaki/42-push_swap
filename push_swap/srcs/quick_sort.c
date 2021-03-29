#include "push_swap.h"

void    set_working_stack(t_struct *st, int key)
{
    int i;
    int j;
    int pivot;

    //printf("----working_stack %d----\n", key);
    //print_stacks(st);
    pivot = st->pivot.size - 1;
    if(key == 0 || st->pivot.size == 0)
        pivot = 0;
    if(st->stack_b.size > 0)
        st->working_stack.size = 0;
    /*
    printf("pivot = %d\nsize = %d\n", pivot, st->working_stack.size);
    for(int k = 0; k < st->pivot.size; k++)
    {
        printf(" %d|", st->pivot.tab[k]);
    }
    printf("\npivot.size= %d\n", st->pivot.size);*/
    while(st->working_stack.size == 0 && pivot >= 0 && pivot < st->pivot.size)
    {
        i = 0;
        j = 0;
        if(key == 1)
            while(i < st->stack_a.size)
            {
                if(st->stack_a.tab[i] <= st->pivot.tab[pivot])
                {
                    st->working_stack.tab[j] = st->stack_a.tab[i];
                    st->working_stack.size++;
                    j++;
                }
                i++;
            }
        if(key == -1)
            while(i < st->stack_b.size)
            {
                if(st->stack_b.tab[i] > st->pivot.tab[pivot])
                {
                    st->working_stack.tab[j] = st->stack_b.tab[i];
                    st->working_stack.size++;
                    j++;
                }
                i++;
            }
        pivot+=key;
    }
    if(st->working_stack.size == 0)
    {
        if(key == 1)
        {
            for(int k = 0; k < st->stack_a.size; k++)
                st->working_stack.tab[k] = st->stack_a.tab[k];
            st->working_stack.size = st->stack_a.size;
        }
        if(key == -1)
        {    for(int k = 0; k < st->stack_b.size; k++)
                st->working_stack.tab[k] = st->stack_b.tab[k];
            st->working_stack.size = st->stack_b.size;
        }
    }
    /*
    for(int k = 0; k < st->working_stack.size; k++)
    {
        printf(" %d|", st->working_stack.tab[k]);
    }
    printf("\nworking_stack.size= %d\n", st->working_stack.size);
    printf("----working_stack done----\n");*/
}

void    add_pivot(t_struct *st, int pivot)
{
    int i;
    int tmp;

    i = st->pivot.size;
    while(i >= 0)
    {
        if(st->pivot.tab[i - 1] == pivot)
            return;
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

int    get_pivot(t_struct *st) //better to get med instead of moy
{
    int i;
    double moy;
    int pivot;

    i = 0;
    moy = 0;
    pivot = st->working_stack.tab[0];
    while(i < st->working_stack.size)
    {
        moy += st->working_stack.tab[i];
        i++;
    }
    moy /= i;
    i = 0;
    //printf("moy = %f\n", moy);
    while(i < st->working_stack.size)
    {
        if(abs((double)pivot - moy) > abs((double)st->working_stack.tab[i] - moy))
            pivot = st->working_stack.tab[i];
        i++;
    }
    return(pivot);
}

void    partition(t_struct *st, int key)
{
    int pivot;
    int i;

    //printf("----partition %d----\n", key);
    i = 0;
    set_working_stack(st, key);
    pivot = get_pivot(st);
    add_pivot(st, pivot);
    //printf("pivot = %d\n", pivot);
    if(key == 1)
    {
        while(i < st->stack_a.size)
        {
            //print_stacks(st);
            if(st->stack_a.tab[0] <= pivot)
            {
                //printf("pb\n");
		        st->instr = "pb";
                exec_instr(st);
            }
            else
            {
                //printf("ra\n");
		        st->instr = "ra";
                exec_instr(st);
                i++;
            }
        }
    }
    if(key == -1)
    {
        while(i < st->stack_b.size)
        {
            //print_stacks(st);
            if(st->stack_b.tab[0] >= pivot)
            {
                //printf("pa\n");
		        st->instr = "pa";
                exec_instr(st);
            }
            else
            {
                //printf("rb\n");
		        st->instr = "rb";
                exec_instr(st);
                i++;
            }
        }
    }
    //printf("----partition done----\n");
}

int    quick_sort(t_struct *st)
{
    if(!(st->pivot.tab = (int*)malloc(sizeof(int) * (st->stack_a.size))))
        return(0);
    if(!(st->working_stack.tab = (int*)malloc(sizeof(int) * (st->stack_a.size))))
        return(0);
    while(!check_sort(st) || !check_rsort(st))
    {
        while(!check_sort(st) || st->stack_a.size > 1)
            partition(st, 1);
        while(!check_rsort(st) || st->stack_b.size > 1)
            partition(st, -1);
    }
    while (st->stack_b.size != 0)
    {
        //printf("pa\n");
		st->instr = "pa";
        exec_instr(st);
    }
    return(1);
}