#include "push_swap.h"

int check_arg(int ac, char **av)
{
    int i, j;

    i = 1;
    while(i < ac)
    {
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

int realloc_stack(t_stack *stack, int nb)
{
	int *tmp;
	int i;

	tmp = (int*)malloc(sizeof(int) * (stack->size + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (i < stack->size)
	{
		tmp[i] = stack->tab[i];
		i++;
	}
	tmp[i] = nb;
	if (stack->tab)
		free(stack->tab);
	stack->tab = tmp;
	stack->size++;
	return (1);
}

int parse_arg(t_struct *st, int ac, char **av)
{
    int i;

    i = 1;
    if(!check_arg(ac, av))
        return(0);
    while(i < ac)
    {
        realloc_stack(&st->stack_a, ft_atoi(av[i]));
        i++;
    }
    return(1);
}