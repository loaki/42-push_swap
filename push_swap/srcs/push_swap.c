#include "push_swap.h"

int main(int ac, char **av){
    t_struct    st;

    if (ac == 1)
        return(0);
    init_struct(&st);
    if (!parse_arg(&st, ac, av) || !sort_stack(&st))
    {
        write(2, "Error\n", 6);
        return (free_struct(&st));
    }
	return (free_struct(&st));
}