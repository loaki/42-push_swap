#include "push_swap.h"

int main(int ac, char **av){
    t_struct    st;

    if(ac == 1)
        return(0);
    init_struct(&st);
    if(!parse_arg(&st, ac, av) || !check_instr(&st))
    {
        write(2, "Error\n", 6);
        return(free_struct(&st));
    }
    print_stacks(&st);
    printf("instr : |%s|\n", st.instr);
    check_stack(&st);
    return(0);
}