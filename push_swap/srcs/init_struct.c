/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:51:14 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/03/31 22:51:14 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_struct(t_struct *st)
{
	st->stack_a.tab = NULL;
	st->stack_a.size = 0;
	st->stack_b.tab = NULL;
	st->stack_b.size = 0;
	st->chunk.tab = NULL;
	st->chunk.size = 0;
	st->instr = 0;
	st->nb_instr = 0;
	st->opt_v = 0;
	st->opt_c = 0;
}

int		free_struct(t_struct *st)
{
	write(1, "free_struct\n", 12);
	printf("tab[0] : %d tab[1] : %d\n", st->stack_a.tab[0], st->stack_a.tab[1]);
	printf("size : %d\n", sizeof(st->stack_a.tab));
	printf("size++ : %d\n", sizeof(st->stack_a.tab+1));
	if (st->stack_a.tab)
	{
		write(1, "a\n", 2);
		free(st->stack_a.tab);
		write(1, "b\n", 2);
		st->stack_a.tab = NULL;
	}
	write(1, "2\n", 2);
	if (st->stack_b.tab)
	{
		free(&(st->stack_b.tab));
		st->stack_b.tab = NULL;
	}
	write(1, "3\n", 2);
	if (st->chunk.tab)
	{
		free(&(st->chunk.tab));
		st->chunk.tab = NULL;
	}
	write(1, "4\n", 2);
	if (st->instr)
		free(st->instr);
	write(1, "5\n", 2);
	return (0);
}
