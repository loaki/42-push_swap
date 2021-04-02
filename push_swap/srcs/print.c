/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 20:41:59 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/04/02 20:41:59 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_a(t_struct *st, int i, int size_max, int display_max)
{
	if (i < (int)((double)st->stack_a.size / ((double)size_max / (double)display_max)))
		if (i == 0 && (!ft_strcmp(st->instr, "sa") || !ft_strcmp(st->instr, "ra") || !ft_strcmp(st->instr, "rra")
		|| !ft_strcmp(st->instr, "ss") || !ft_strcmp(st->instr, "rr")) ||
			i == 1 && (!ft_strcmp(st->instr, "sa") || !ft_strcmp(st->instr, "ss")) ||
			i + 1 >= (int)((double)st->stack_a.size / ((double)size_max / (double)display_max)) &&
				(!ft_strcmp(st->instr, "ra") || !ft_strcmp(st->instr, "rra") || !ft_strcmp(st->instr, "rr")))
			printf("%13d |", get_moy(st->stack_a,
			(int)((double)i / ((double)st->stack_a.size / ((double)size_max / (double)display_max)) * (double)st->stack_a.size),
			(int)((double)(i + 1) / ((double)st->stack_a.size / ((double)size_max / (double)display_max)) * (double)st->stack_a.size)));
		else if (i == 0 && !ft_strcmp(st->instr, "pa"))
			printf("%13d |", get_moy(st->stack_a,
			(int)((double)i / ((double)st->stack_a.size / ((double)size_max / (double)display_max)) * (double)st->stack_a.size),
			(int)((double)(i + 1) / ((double)st->stack_a.size / ((double)size_max / (double)display_max)) * (double)st->stack_a.size)));
		else
			printf("%13d |", get_moy(st->stack_a,
			(int)((double)i / ((double)st->stack_a.size / ((double)size_max / (double)display_max)) * (double)st->stack_a.size),
			(int)((double)(i + 1) / ((double)st->stack_a.size / ((double)size_max / (double)display_max)) * (double)st->stack_a.size)));
	else if (i < (int)((double)st->stack_b.size / ((double)size_max / (double)display_max)))
		printf("              |");
}

void print_b(t_struct *st, int i, int size_max, int display_max)
{
	if (i < (int)((double)st->stack_b.size / ((double)size_max / (double)display_max)))
		if (i == 0 && (!ft_strcmp(st->instr, "sp") || !ft_strcmp(st->instr, "rb") || !ft_strcmp(st->instr, "rrb") || !ft_strcmp(st->instr, "ss") || !ft_strcmp(st->instr, "rr")) ||
			i == 1 && (!ft_strcmp(st->instr, "sb") || !ft_strcmp(st->instr, "ss")) ||
			i + 1 >= (int)((double)st->stack_b.size / ((double)size_max / (double)display_max)) &&
				(!ft_strcmp(st->instr, "rb") || !ft_strcmp(st->instr, "rrb") || !ft_strcmp(st->instr, "rr")))
			printf("%7d\n", get_moy(st->stack_b,
			(int)((double)i / ((double)st->stack_b.size / ((double)size_max / (double)display_max)) * (double)st->stack_b.size),
			(int)((double)(i + 1) / (double)st->stack_b.size / ((double)size_max / (double)display_max) * (double)st->stack_b.size)));
		else if (i == 0 && !ft_strcmp(st->instr, "pb"))
			printf("%7d\n", get_moy(st->stack_b,
			(int)((double)i / ((double)st->stack_b.size / ((double)size_max / (double)display_max)) * (double)st->stack_b.size),
			(int)((double)(i + 1) / ((double)st->stack_b.size / ((double)size_max / (double)display_max)) * (double)st->stack_b.size)));
		else
			printf("%7d\n", get_moy(st->stack_b,
			(int)((double)i / ((double)st->stack_b.size / ((double)size_max / (double)display_max)) * (double)st->stack_b.size),
			(int)((double)(i + 1) / ((double)st->stack_b.size / ((double)size_max / (double)display_max)) * (double)st->stack_b.size)));
	else
		printf("\n");
}

void print_ac(t_struct *st, int i, int size_max, int display_max)
{
	if (i < (int)((double)st->stack_a.size / ((double)size_max / (double)display_max)))
		if (i == 0 && (!ft_strcmp(st->instr, "sa") || !ft_strcmp(st->instr, "ra") || !ft_strcmp(st->instr, "rra") || !ft_strcmp(st->instr, "ss")
		|| !ft_strcmp(st->instr, "rr")) ||
			i == 1 && (!ft_strcmp(st->instr, "sa") || !ft_strcmp(st->instr, "ss")) ||
			i + 1 >= (int)((double)st->stack_a.size / ((double)size_max / (double)display_max)) &&
				(!ft_strcmp(st->instr, "ra") || !ft_strcmp(st->instr, "rra") || !ft_strcmp(st->instr, "rr")))
			printf("\033[33m%13d\033[00m |", get_moy(st->stack_a,
			(int)((double)i / ((double)st->stack_a.size / ((double)size_max / (double)display_max)) * (double)st->stack_a.size),
			(int)((double)(i + 1) / ((double)st->stack_a.size / ((double)size_max / (double)display_max)) * (double)st->stack_a.size)));
		else if (i == 0 && !ft_strcmp(st->instr, "pa"))
			printf("\033[32m%13d\033[00m |", get_moy(st->stack_a,
			(int)((double)i / ((double)st->stack_a.size / ((double)size_max / (double)display_max)) * (double)st->stack_a.size),
			(int)((double)(i + 1) / ((double)st->stack_a.size / ((double)size_max / (double)display_max)) * (double)st->stack_a.size)));
		else
			printf("%13d |", get_moy(st->stack_a,
			(int)((double)i / ((double)st->stack_a.size / ((double)size_max / (double)display_max)) * (double)st->stack_a.size),
			(int)((double)(i + 1) / ((double)st->stack_a.size / ((double)size_max / (double)display_max)) * (double)st->stack_a.size)));
	else if (i < (int)((double)st->stack_b.size / ((double)size_max / (double)display_max)))
		printf("              |");
}

void print_bc(t_struct *st, int i, int size_max, int display_max)
{
	if (i < (int)((double)st->stack_b.size / ((double)size_max / (double)display_max)))
		if (i == 0 && (!ft_strcmp(st->instr, "sp") || !ft_strcmp(st->instr, "rb") || !ft_strcmp(st->instr, "rrb") || !ft_strcmp(st->instr, "ss") || !ft_strcmp(st->instr, "rr")) ||
			i == 1 && (!ft_strcmp(st->instr, "sb") || !ft_strcmp(st->instr, "ss")) ||
			i + 1 >= (int)((double)st->stack_b.size / ((double)size_max / (double)display_max)) &&
				(!ft_strcmp(st->instr, "rb") || !ft_strcmp(st->instr, "rrb") || !ft_strcmp(st->instr, "rr")))
			printf("\033[33m%7d\033[00m\n", get_moy(st->stack_b,
			(int)((double)i / ((double)st->stack_b.size / ((double)size_max / (double)display_max)) * (double)st->stack_b.size),
			(int)((double)(i + 1) / (double)st->stack_b.size / ((double)size_max / (double)display_max) * (double)st->stack_b.size)));
		else if (i == 0 && !ft_strcmp(st->instr, "pb"))
			printf("\033[32m%7d\033[00m\n", get_moy(st->stack_b,
			(int)((double)i / ((double)st->stack_b.size / ((double)size_max / (double)display_max)) * (double)st->stack_b.size),
			(int)((double)(i + 1) / ((double)st->stack_b.size / ((double)size_max / (double)display_max)) * (double)st->stack_b.size)));
		else
			printf("%7d\n", get_moy(st->stack_b,
			(int)((double)i / ((double)st->stack_b.size / ((double)size_max / (double)display_max)) * (double)st->stack_b.size),
			(int)((double)(i + 1) / ((double)st->stack_b.size / ((double)size_max / (double)display_max)) * (double)st->stack_b.size)));
	else
		printf("\n");
}
