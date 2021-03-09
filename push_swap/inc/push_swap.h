#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../lib/libft.h"

typedef struct	s_stack
{
	int			*tab;
	int			start;
	int			size;
}				t_stack;

typedef struct	s_struct
{
	t_stack		stack_a;
	t_stack		stack_b;
}				t_struct;

void print_stacks(t_struct *st);

int			check_instr(t_struct *st);

void init_struct(t_struct *st);
int free_struct(t_struct *st);

int check_arg(int ac, char **av);
int realloc_stack(t_stack *stack, int nb);
int parse_arg(t_struct *st, int ac, char **av);

#endif