#include "push_swap.h"

int main(int ac, char **av){
    t_struct    st;

    if(ac == 1)
        return(0);
    init_struct(&st);
    if(!parse_arg(&st, ac, av))
    {
        write(2, "Error\n", 6);
        return(free_struct(&st));
    }
    //print_stacks(&st);
    sort_stack(&st);
    //printf("nb_instr : %d\n", st.nb_instr);
}