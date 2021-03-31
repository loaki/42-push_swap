#include "push_swap.h"

int    get_median(t_struct *st)
{
    int *cp_stack;
    int i;
    int tmp;

    i = -1;
    if(!(cp_stack = (int*)malloc(sizeof(int) * (st->stack_a.size))))
        return(0);
    while(++i < st->stack_a.size)
        cp_stack[i] = st->stack_a.tab[i];
    i = 0;
    while(i < st->stack_a.size - 1)
    {
        if(cp_stack[i] > cp_stack[i + 1])
        {
            tmp = cp_stack[i];
            cp_stack[i] = cp_stack[i + 1];
            cp_stack[i + 1] = tmp;
            i = 0;
        }
        else
            i++;
    }
    i = -1;
    while(++i < st->chunk.size)
        st->chunk.tab[i] = cp_stack[(int)(i * st->stack_a.size / st->chunk.size)];
    st->chunk.tab[st->chunk.size] = cp_stack[st->stack_a.size - 1];
    st->chunk.size++;
    free(cp_stack);
    cp_stack = NULL;
    return(1);
}

int     get_high(t_stack stack)
{
    int i;
    int high;

    i = 0;
    high = stack.tab[0];
    while(i < stack.size)
    {
        if(high < stack.tab[i])
            high = stack.tab[i];
        i++;
    }
    return(high);
}

int     get_low(t_stack stack)
{
    int i;
    int low;

    i = 0;
    low = stack.tab[0];
    while(i < stack.size)
    {
        if(low > stack.tab[i])
            low = stack.tab[i];
        i++;
    }
    return(low);
}

int get_index(t_stack stack, int nb)
{
    int i;

    i = 0;
    while(i < stack.size)
    {
        if(nb == stack.tab[i])
            return(i);
        i++;
    }
    return(0);  
}

void    insert_index(t_struct *st)
{
    int nb_move;

    nb_move = 0;
    while(st->stack_b.size > 1 && nb_move < st->stack_b.size - 1 &&
    get_high(st->stack_b) > st->stack_a.tab[0] && get_low(st->stack_b) < st->stack_a.tab[0])
    {
        if((st->stack_b.tab[st->stack_b.size - 1 - nb_move] != get_high(st->stack_b) &&
        st->stack_b.tab[st->stack_b.size - 1 - nb_move] > st->stack_a.tab[0] &&
        st->stack_b.tab[st->stack_b.size - 2 - nb_move] < st->stack_a.tab[0]) ||
        (st->stack_b.tab[st->stack_b.size - 1 - nb_move] != get_high(st->stack_b) &&
        st->stack_b.tab[st->stack_b.size - 1 - nb_move] < st->stack_a.tab[0] &&
        st->stack_b.tab[st->stack_b.size - 2 - nb_move] > st->stack_a.tab[0]))
        {
            nb_move++;
            while(nb_move--)
            {
                //printf("rrb\n");
	            st->instr = "rrb";
                exec_instr(st);
            }
            break;
        }
        if((st->stack_b.tab[nb_move] != get_low(st->stack_b) &&
        st->stack_b.tab[nb_move] > st->stack_a.tab[0] &&
        st->stack_b.tab[nb_move + 1] < st->stack_a.tab[0]) ||
        (st->stack_b.tab[nb_move] != get_low(st->stack_b) &&
        st->stack_b.tab[nb_move] < st->stack_a.tab[0] &&
        st->stack_b.tab[nb_move + 1] > st->stack_a.tab[0]))
        {
            nb_move++;
            while(nb_move--)
            {
                //printf("rb\n");
	            st->instr = "rb";
                exec_instr(st);
            }
            break;
        }
        nb_move++;
    }
}

void    insert_to_b(t_struct *st, int nb_move, char *instr)
{
    while(nb_move--)
    {
        //printf("%s\n", instr);
		st->instr = instr;
        exec_instr(st);
    }
    if(st->stack_b.size > 1 && (get_high(st->stack_b) < st->stack_a.tab[0] || get_low(st->stack_b) > st->stack_a.tab[0]))
        while(get_index(st->stack_b, get_high(st->stack_b)) != 0)
        {
            if(get_index(st->stack_b, get_high(st->stack_b)) <= st->stack_b.size / 2)
            {
                //printf("rb\n");
	            st->instr = "rb";
                exec_instr(st);
            }
            if(get_index(st->stack_b, get_high(st->stack_b)) > st->stack_b.size / 2)
            {
                //printf("rrb\n");
	            st->instr = "rrb";
                exec_instr(st);
            }
        }
    insert_index(st);
    //printf("pb\n");
	st->instr = "pb";
    exec_instr(st);
}

int insertion_sort(t_struct *st)
{
    int i;
    int nb_move;

    i = 0;
    st->chunk.size = 0.01 * st->stack_a.size + 4;
    if(!(st->chunk.tab = (int*)malloc(sizeof(int) * (st->chunk.size))) || !get_median(st))
        return(0);
    while(++i < st->chunk.size)
    {
        nb_move = 0;
        while(st->stack_a.size > 3 && nb_move < st->stack_a.size)
        {
            if(st->stack_a.tab[nb_move] >= st->chunk.tab[i - 1] && st->stack_a.tab[nb_move] < st->chunk.tab[i])
            {
                insert_to_b(st, nb_move, "ra");
                nb_move = 0;
            }
            else if(nb_move > 0 && st->stack_a.tab[st->stack_a.size - nb_move] >= st->chunk.tab[i - 1] && st->stack_a.tab[st->stack_a.size - nb_move] < st->chunk.tab[i])
            {
                insert_to_b(st, nb_move, "rra");
                nb_move = 0;
            }
            else
                nb_move++;
        }
    }
    sort_three(st);
    while(get_index(st->stack_b, get_high(st->stack_b)) != 0)
    {
        if(get_index(st->stack_b, get_high(st->stack_b)) <= st->stack_b.size / 2)
        {
            //printf("rb\n");
	        st->instr = "rb";
            exec_instr(st);
        }
        if(get_index(st->stack_b, get_high(st->stack_b)) > st->stack_b.size / 2)
        {
            //printf("rrb\n");
	        st->instr = "rrb";
            exec_instr(st);
        }
    }
    while (st->stack_b.size != 0)
    {
        //printf("pa\n");
		st->instr = "pa";
        exec_instr(st);
    }
    return(1);
}