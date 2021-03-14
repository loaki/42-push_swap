#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../lib/libft.h"

typedef struct	s_stack
{
	int				*tab;
	int				size;
}				t_stack;

typedef struct	s_struct
{
	t_stack		stack_a;
	t_stack		stack_b;
	char		*instr;
}				t_struct;

void print_stacks(t_struct *st);

static void	apply_p(t_stack *dest, t_stack *source);
void		op_p(t_struct *st, char *instr);
static void	apply_r(t_stack *stack);
void		op_r(t_struct *st, char *instr);
static void	apply_rr(t_stack *stack);
void		op_rr(t_struct *st, char *instr);
static void	apply_s(t_stack *stack);
void		op_s(t_struct *st, char *instr);

void exec_instr(t_struct *st);
void check_stack(t_struct *st);

int		ft_strcmp(const char *s1, const char *s2);
static int	instr_cmp(char *line);
static int	check_if_valid_instr(t_struct *st, char buf[], int *index);
int			check_instr(t_struct *st);

void init_struct(t_struct *st);
int free_struct(t_struct *st);

int check_arg(int ac, char **av);
int realloc_stack(t_stack *stack, int nb);
int parse_arg(t_struct *st, int ac, char **av);

#endif