#include "push_swap.h"

void print_stacks(t_struct *st)
{
    printf("stack a :\n");
    for(int i = 0; i<st->stack_a.size; i++)
    {
        printf(" %d |", st->stack_a.tab[i]);
    }
    printf("\nstack b :\n");
    for(int i = 0; i<st->stack_b.size; i++)
    {
        printf(" %d |", st->stack_b.tab[i]);
    }
}

int main(int ac, char **av){
    t_struct    st;
    char        *instr;

    instr = 0;
    init_struct(&st);
    if (!parse_arg(&st, ac, av))
    {
        write(2, "Error\n", 6);
        return(free_struct(&st));
    }
    check_instr(&st);
    printf("%s\n", instr);
    print_stacks(&st);
    //exec
    //compare
    return(0);
}