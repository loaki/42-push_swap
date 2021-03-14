#include "push_swap.h"

int check_arg(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while(i < ac)
    {
        j = 0;
        while(j < i)
        {
            if(ft_strcmp(av[i], av[j]) == 0)
                return(0);
            j++;
        }
        j = 0;
        while(av[i][j])
        {
            if((j == 0 && (av[i][0] == '-' || av[i][0] == '+')) || ft_isdigit(av[i][j]))
                j++;
            else
                return(0);
        }
        i++;
    }
    return (1);
}

int parse_arg(t_struct *st, int ac, char **av)
{
    int i;

    i = 1;
    if(!check_arg(ac, av) || !(st->stack_a.tab = (int*)malloc(sizeof(int) * ac - 1)))
        return(0);
    while(i < ac)
    {
        st->stack_a.tab[i - 1] = ft_atoi(av[i]);
        i++;
    }
    st->stack_a.size = ac - 1;
    st->stack_b.tab = (int*)malloc(sizeof(int) * (st->stack_a.size));
    return(1);
}