#include "push_swap.h"

void very_bad_algo(t_struct *st)
{
    int i;
    int low;
    int index;

    while(st->stack_a.size > 1)
    {
        i = 0;
        low = st->stack_a.tab[0];
        index = 0;
        while(i < st->stack_a.size)
        {
            if(st->stack_a.tab[i] < low)
            {
                low = st->stack_a.tab[i];
                index = i;
            }
            i++;
        }
        st->instr = "ra";
        while(index > 0)
        {
            //printf("ra\n");
            exec_instr(st);
            index--;
        }
        //printf("pb\n");
        st->instr = "pb";
        exec_instr(st);
    }
    while(st->stack_b.size > 0)
    {
        //printf("pa\n");
        st->instr = "pa";
        exec_instr(st);
    }
}

#include <time.h>

int sort_stack(t_struct *st)
{
    int i = 0;
    int nb_ins;
    clock_t start, end;
    //very_bad_algo(st);
    srand(time(0));
    start = clock();
    end = clock();
    nb_ins = -1;
    char *instr_str, *low_instr;
    //duplicate
    int s_save = st->stack_a.size;
    int *a_save = (int*)malloc(sizeof(int) * (st->stack_a.size));
    for(int j = 0; j < st->stack_a.size; j++)
        a_save[j] = st->stack_a.tab[j];

    while((double)(end - start)/CLOCKS_PER_SEC < 20)
    {
        end = clock();
        st->nb_instr = 0;
        st->stack_a.size = s_save;
        st->stack_b.size = 0;
        free(instr_str);
        instr_str = "";
        for(int j = 0; j < st->stack_a.size; j++)
            st->stack_a.tab[j] = a_save[j];
        print_stacks(st);
        while(!check_stack(st))
        {
            if(nb_ins != -1 && st->nb_instr > nb_ins)
                break;
            i = rand() %8;
            if(i == 0)
            {
                instr_str = ft_strjoin(instr_str, "sa ");
                st->instr = "sa";
                exec_instr(st);
            }
            if(i == 1)
            {
                instr_str = ft_strjoin(instr_str, "sb ");
                st->instr = "sb";
                exec_instr(st);
            }
            if(i == 2)
            {
                instr_str = ft_strjoin(instr_str, "ra ");
                st->instr = "ra";
                exec_instr(st);
            }
            if(i == 3)
            {
                instr_str = ft_strjoin(instr_str, "rb ");
                st->instr = "rb";
                exec_instr(st);
            }
            if(i == 4)
            {
                instr_str = ft_strjoin(instr_str, "rra ");
                st->instr = "rra";
                exec_instr(st);
            }
            if(i == 5)
            {
                instr_str = ft_strjoin(instr_str, "rrb ");
                st->instr = "rrb";
                exec_instr(st);
            }
            if(i == 6)
            {
                instr_str = ft_strjoin(instr_str, "pa ");
                st->instr = "pa";
                exec_instr(st);
            }
            if(i == 7)
            {
                instr_str = ft_strjoin(instr_str, "pb ");
                st->instr = "pb";
                exec_instr(st);
            }
            printf(".");
        }
        if(check_stack(st) && (st->nb_instr < nb_ins || nb_ins == -1))
        {
            printf("\n\n\n\n--------------------------------found-------------------------\n\n\n\n");
            print_stacks(st);
            printf("%s\n", instr_str);
            printf("check : %d\n", check_stack(st));
            low_instr = ft_strdup(instr_str);
            nb_ins = st->nb_instr;
        }
    }
    printf("\n\n\n\n--------------------------------final-------------------------\n\n\n\n");
    printf("nb_instr = %d\n", nb_ins);
    printf("%s\n", low_instr);
    printf("nb : %d\n", st->nb_instr);
}