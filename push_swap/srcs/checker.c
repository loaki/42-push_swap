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

int main(int ac, char **av){
    t_struct    st;

    init_struct(&st);
    if (!parse_arg(&st, ac, av) || !check_instr(&st))
    {
        write(2, "Error\n", 6);
        return(free_struct(&st));
    }
    print_stacks(&st);
    printf("instr : |%s|\n", st.instr);
    check_stack(&st);
    return(0);
}