#include "push_swap.h"

void print_stacks(t_struct *st)
{
    printf("size a : %d, size b : %d\n", st->stack_a.size, st->stack_b.size);
    printf("stack a :");
    for(int i = 0; i<st->stack_a.size; i++)
    {
        printf(" %d |", st->stack_a.tab[i]);
    }
    printf("\nstack b :");
    for(int i = 0; i<st->stack_b.size; i++)
    {
        printf(" %d |", st->stack_b.tab[i]);
    }
    printf("\n");
}

void exec_instr(t_struct *st)
{
    int     i;
    char    **instr;

    i = 0;
    instr = ft_split(st->instr, ' ');
    while(instr[i])
    {
        st->nb_instr++;
        if(instr[i][0] == 's')
            op_s(st, instr[i]);
        if(instr[i][0] == 'p')
            op_p(st, instr[i]);
        if(instr[i][0] == 'r' && instr[i][1] != 'r')
            op_r(st, instr[i]);
        if(instr[i][0] == 'r' && instr[i][1] == 'r')
            op_rr(st, instr[i]);
        //printf("-----------\ninstr : %s\n", instr[i]);
        //print_stacks(st);
        i++;
    }

}

int check_stack(t_struct *st)
{
    int i;

    i = 0;
    if(st->stack_b.size != 0)
        return(0);
    while(i < st->stack_a.size - 1)
    {
        if(st->stack_a.tab[i] > st->stack_a.tab[i + 1])
            return(0);
        i++;
    }
    return(1);
}

int check_sort(t_struct *st)
{
    int i;

    i = 0;
    while(i < st->stack_a.size - 1)
    {
        if(st->stack_a.tab[i] > st->stack_a.tab[i + 1])
            return(0);
        i++;
    }
    return(1);  
}

int check_rsort(t_struct *st)
{
    int i;

    i = 0;
    while(i < st->stack_b.size - 1)
    {
        if(st->stack_b.tab[i] < st->stack_b.tab[i + 1])
            return(0);
        i++;
    }
    return(1);
}