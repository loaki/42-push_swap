/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:26:25 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/04/01 13:26:25 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_moy(t_stack stack, int start, int end)
{
	int i;
	int moy;

	i = start;
	moy = 0;
	if (start >= end)
		return (stack.tab[i]);
	while (i < end)
	{
		moy += stack.tab[i];
		i++;
	}
	return (moy / (end - start));
}

void display(t_struct *st, char *op)
{
	int i;
	int display_max;
	int size_max;

	i = 0;
	if (st->stack_a.size > st->stack_b.size)
		size_max = st->stack_a.size;
	else
		size_max = st->stack_b.size;
	if (size_max > 15)
		display_max = 15;
	else
		display_max = size_max;
	st->instr = op;
	printf("\e[1;1H\e[2J");
	printf("%3s . Stack A   Stack B\n %d\n", op, st->nb_instr);
	//printf("sa : %d sb : %d dis : %d si : %d\n", st->stack_a.size, st->stack_b.size, display_max, size_max);
	while (i < display_max)
	{
		if (st->opt_c == 1)
		{
			print_ac(st, i, size_max, display_max);
			print_bc(st, i, size_max, display_max);
		}
		else
		{
			print_a(st, i, size_max, display_max);
			print_b(st, i, size_max, display_max);
		}
		i++;
	}
	sleep(1);
}