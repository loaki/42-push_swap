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

int		get_moy(t_stack stack, int start, int end)
{
	int i;
	int moy;

	i = start;
	moy = 0;
	if(start >= end)
		return(stack.tab[i]);
	while (i < end)
	{
		moy += stack.tab[i];
		i++;
	}
	if(moy/(end - start) > 3000)
		printf("%d = %d | %d   --- size : %d\n",moy/(end - start), start, end, stack.size);
	return (moy/(end - start));
}

void	display(t_struct *st, char *op)
{
	int i;
	int display_max;
	int size_max;

	i = 0;
	if (st->stack_a.size > st->stack_b.size)
		size_max = st->stack_a.size;
	else
		size_max = st->stack_b.size;
	if (size_max > 10)
		display_max = 10;
	else
		display_max = size_max;
	printf("\e[1;1H\e[2J");
	printf("%3s . Stack A   Stack B\n %d\n", op, st->nb_instr);
	printf("sa : %d dis : %d si : %d\n", st->stack_a.size, display_max, size_max);
	while(i < display_max)
	{
		//printf("%d : %d --- %d\n", i, (int)((double)i / (double)st->stack_a.size * (double)size_max / (double)display_max * (double)st->stack_a.size), (int)((double)(i + 1) / (double)st->stack_a.size * (double)size_max / (double)display_max * (double)st->stack_a.size));
		
		if(i < (int)((double)st->stack_a.size * (double)size_max / (double)display_max) && (int)((double)(i + 1) / (double)st->stack_a.size * (double)size_max / (double)display_max * (double)st->stack_a.size) < st->stack_a.size)
			if(i == 0 && (!ft_strcmp(op, "sa") || !ft_strcmp(op, "ra") || !ft_strcmp(op, "rra") || !ft_strcmp(op, "ss") || !ft_strcmp(op, "rr")) ||
				i == 1 && (!ft_strcmp(op, "sa") || !ft_strcmp(op, "ss")) ||
				i + 1 >= (int)((double)st->stack_a.size * (double)size_max / (double)display_max) && (!ft_strcmp(op, "ra") || !ft_strcmp(op, "rra") || !ft_strcmp(op, "rr")))
				printf("\033[33m%13d\033[00m |", get_moy(st->stack_a, (int)((double)i / (double)st->stack_a.size * (double)size_max / (double)display_max * (double)st->stack_a.size), (int)((double)(i + 1) / (double)st->stack_a.size * (double)size_max / (double)display_max * (double)st->stack_a.size)));
			else if(i == 0 && !ft_strcmp(op, "pa"))
				printf("\033[32m%13d\033[00m |", get_moy(st->stack_a, (int)((double)i / (double)st->stack_a.size * (double)size_max / (double)display_max * (double)st->stack_a.size), (int)((double)(i + 1) / (double)st->stack_a.size * (double)size_max / (double)display_max * (double)st->stack_a.size)));
			else
				printf("%13d |", get_moy(st->stack_a, (int)((double)i / (double)st->stack_a.size * (double)size_max / (double)display_max * (double)st->stack_a.size), (int)((double)(i + 1) / (double)st->stack_a.size * (double)size_max / (double)display_max * (double)st->stack_a.size)));
		else
			printf("              |");
		if(i < (int)((double)st->stack_b.size * (double)size_max / (double)display_max) && (int)((double)(i + 1) / (double)st->stack_b.size * (double)size_max / (double)display_max * (double)st->stack_b.size) < st->stack_b.size)
			if(i == 0 && (!ft_strcmp(op, "sp") || !ft_strcmp(op, "rb") || !ft_strcmp(op, "rrb") || !ft_strcmp(op, "ss") || !ft_strcmp(op, "rr")) ||
				i == 1 && (!ft_strcmp(op, "sb") || !ft_strcmp(op, "ss")) ||
				i + 1 >= (int)((double)st->stack_b.size * (double)size_max / (double)display_max) && (!ft_strcmp(op, "rb") || !ft_strcmp(op, "rrb") || !ft_strcmp(op, "rr")))
				printf("\033[33m%7d\033[00m\n", get_moy(st->stack_b, (int)((double)i / (double)st->stack_b.size * (double)size_max / (double)display_max * (double)st->stack_b.size), (int)((double)(i + 1) / (double)st->stack_b.size * (double)size_max / (double)display_max * (double)st->stack_b.size)));
			else if(i == 0 && !ft_strcmp(op, "pb"))
				printf("\033[32m%7d\033[00m\n", get_moy(st->stack_b, (int)((double)i / (double)st->stack_b.size * (double)size_max / (double)display_max * (double)st->stack_b.size), (int)((double)(i + 1) / (double)st->stack_b.size * (double)size_max / (double)display_max * (double)st->stack_b.size)));
			else
				printf("%7d\n", get_moy(st->stack_b, (int)((double)i / (double)st->stack_b.size * (double)size_max / (double)display_max * (double)st->stack_b.size), (int)((double)(i + 1) / (double)st->stack_b.size * (double)size_max / (double)display_max * (double)st->stack_b.size)));
		else
			printf("\n");
		i++;
	}
	sleep(1);
}