#include "push_swap.h"

void	sort_three(t_struct *st)
{
	if (st->stack_a.size != 3)
		return ;
	if (st->stack_a.tab[0] > st->stack_a.tab[1] && st->stack_a.tab[0] > st->stack_a.tab[2])
        exec_instr(st, "ra", 1);
	else if (st->stack_a.tab[1] > st->stack_a.tab[0] && st->stack_a.tab[1] > st->stack_a.tab[2])
        exec_instr(st, "rra", 1);
	if (st->stack_a.tab[0] > st->stack_a.tab[1])
        exec_instr(st, "sa", 1);
}

void	small_sort(t_struct *st)
{
    int i;
	int	low;
    int index;

	while(st->stack_a.size > 3)
	{
        //print_stacks(st);
        low = st->stack_a.tab[0];
        index = 0;
        i = 0;
        while(i < st->stack_a.size)
        {
            if(st->stack_a.tab[i] < low)
            {
                low = st->stack_a.tab[i];
                index = i;
            }
            i++;
        }
        //printf("low = %d\n", low);
		if (index < st->stack_a.size / 2)
			while (index--)
                exec_instr(st, "ra", 1);
		else
			while (index++ < st->stack_a.size)
                exec_instr(st, "rra", 1);
        exec_instr(st, "pb", 1);
	}
	sort_three(st);
	while (st->stack_b.size != 0)
        exec_instr(st, "pa", 1);
}

int sort_stack(t_struct *st)
{/*
    int s_save = st->stack_a.size;
    int *a_save = (int*)malloc(sizeof(int) * (st->stack_a.size));
    for(int j = 0; j < st->stack_a.size; j++)
        a_save[j] = st->stack_a.tab[j];
    small_sort(st);
    printf("small_sort : %d instr\n" , st->nb_instr);


    st->nb_instr = 0;
    st->stack_a.size = s_save;
    st->stack_b.size = 0;
    st->instr = 0;
    for(int j = 0; j < st->stack_a.size; j++)
        st->stack_a.tab[j] = a_save[j];*/
	if(st->stack_a.size < 10)
		small_sort(st);
	else
	{
		//write(1, "insertion\n", 10);
    	insertion_sort(st);
		//write(1, "ins end\n", 8);
	}
	//print_stack(st);
    //printf("insertion_sort : %d instr\n", st->nb_instr);
    //free(st->chunk.tab);
    //st->chunk.tab = NULL;
/*
    for(int i = 20; i > 0; i--)
    {
        st->nb_instr = 0;
        st->stack_a.size = s_save;
        st->stack_b.size = 0;
        st->instr = 0;
        for(int j = 0; j < st->stack_a.size; j++)
            st->stack_a.tab[j] = a_save[j];
        insertion_sort(st, i);
        printf("chunk = %d insertion_sort : %d instr\n", i , st->nb_instr);
        free(st->chunk.tab);
        st->chunk.tab = NULL;
    }*/
    return(1);
}