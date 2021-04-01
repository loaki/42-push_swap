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
}

int		free_struct(t_struct *st)
{
	write(1, "1\n", 2);
	if (st->stack_a.tab)
	{
		free(st->stack_a.tab);
		st->stack_a.tab = NULL;
	}
	write(1, "2\n", 2);
	if (st->stack_b.tab)
	{
		free(st->stack_b.tab);
		st->stack_b.tab = NULL;
	}
	write(1, "3\n", 2);
	if (st->chunk.tab)
	{
		free(st->chunk.tab);
		st->chunk.tab = NULL;
	}
	write(1, "4\n", 2);
	if (st->instr)
		free(st->instr);
	write(1, "5\n", 2);
	return (0);
}
