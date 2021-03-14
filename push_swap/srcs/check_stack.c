#include "push_swap.h"

void print_stacks(t_struct *st)
{
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
        if(instr[i][0] == 's')
            op_s(st, instr[i]);
        if(instr[i][0] == 'p')
            op_p(st, instr[i]);
        if(instr[i][0] == 'r' && instr[i][1] != 'r')
            op_r(st, instr[i]);
        if(instr[i][0] == 'r' && instr[i][1] == 'r')
            op_rr(st, instr[i]);
        printf("-----------\ninstr : %s\n", instr[i]);
        print_stacks(st);
        i++;
    }

}

void check_stack(t_struct *st)
{
    int i;

    i = 0;
    exec_instr(st);
    while(i < st->stack_a.size - 1)
    {
        if(st->stack_a.tab[i] > st->stack_a.tab[i + 1])
        {
            printf("\033[31;01mKawO\n\033[00m");
            return;
        }
        i++;
    }
    printf("\033[32;01meuke\n\033[00m");
}