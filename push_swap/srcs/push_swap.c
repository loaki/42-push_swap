#include "push_swap.h"

int main(int ac, char **av){
    t_struct    st;

	//write(1, "start\n", 6);
    if(ac == 1)
        return(0);
    init_struct(&st);
    if(!parse_arg(&st, ac, av) || !sort_stack(&st))
    {
        write(2, "Error\n", 6);
        return(free_struct(&st));
    }
    //print_stack(&st);
    //printf("nb_instr : %d\n", st.nb_instr);
    //free_struct(&st);
	//write(1, "end\n", 4);
}