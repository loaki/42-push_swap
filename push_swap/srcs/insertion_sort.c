/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:51:55 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/03/31 22:51:55 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_chunk(t_struct *st, int *cp_stack)
{
	int i;

	i = -1;
	//write(1, "1\n", 2);
	while (++i < st->chunk.size)
	{
		st->chunk.tab[i] =
		cp_stack[(int)(i * st->stack_a.size / st->chunk.size)];
	}
	//write(1, "2\n", 2);
	st->chunk.tab[st->chunk.size] = cp_stack[st->stack_a.size - 1];
	st->chunk.size++;
	//write(1, "3\n", 2);
	//free(cp_stack); cant free idk why
	//write(1, "4\n", 2);
	//cp_stack = NULL;
}

int		get_median(t_struct *st)
{
	int *cp_stack;
	int i;
	int tmp;

	//write(1, "m1\n", 3);
	i = -1;
	if (!(cp_stack = (int *)malloc(sizeof(int) * (st->stack_a.size))))
		return (0);
	while (++i < st->stack_a.size)
		cp_stack[i] = st->stack_a.tab[i];
	i = 0;
	//write(1, "m2\n", 3);
	while (i < st->stack_a.size - 1)
	{
		if (cp_stack[i] > cp_stack[i + 1])
		{
			tmp = cp_stack[i];
			cp_stack[i] = cp_stack[i + 1];
			cp_stack[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	//write(1, "m3\n", 3);
	fill_chunk(st, cp_stack);
	free(cp_stack);
	//write(1, "m4\n", 3);
	return (1);
}

int		get_high(t_stack stack)
{
	int i;
	int high;

	i = 0;
	high = stack.tab[0];
	while (i < stack.size)
	{
		if (high < stack.tab[i])
			high = stack.tab[i];
		i++;
	}
	return (high);
}

int		get_low(t_stack stack)
{
	int i;
	int low;

	i = 0;
	low = stack.tab[0];
	while (i < stack.size)
	{
		if (low > stack.tab[i])
			low = stack.tab[i];
		i++;
	}
	return (low);
}

int		get_index(t_stack stack, int nb)
{
	int i;

	i = 0;
	while (i < stack.size)
	{
		if (nb == stack.tab[i])
			return (i);
		i++;
	}
	return (0);
}

void	insert_index(t_struct *st)
{
	int nb_move;

	nb_move = 0;
	while (st->stack_b.size > 1 && nb_move < st->stack_b.size - 1 &&
		   get_high(st->stack_b) > st->stack_a.tab[0] && get_low(st->stack_b) < st->stack_a.tab[0])
	{
		if ((st->stack_b.tab[st->stack_b.size - 1 - nb_move] != get_high(st->stack_b) &&
			 st->stack_b.tab[st->stack_b.size - 1 - nb_move] > st->stack_a.tab[0] &&
			 st->stack_b.tab[st->stack_b.size - 2 - nb_move] < st->stack_a.tab[0]) ||
			(st->stack_b.tab[st->stack_b.size - 1 - nb_move] != get_high(st->stack_b) &&
			 st->stack_b.tab[st->stack_b.size - 1 - nb_move] < st->stack_a.tab[0] &&
			 st->stack_b.tab[st->stack_b.size - 2 - nb_move] > st->stack_a.tab[0]))
		{
			nb_move++;
			while (nb_move--)
				exec_instr(st, "rrb", 1);
			break;
		}
		if ((st->stack_b.tab[nb_move] != get_low(st->stack_b) &&
			 st->stack_b.tab[nb_move] > st->stack_a.tab[0] &&
			 st->stack_b.tab[nb_move + 1] < st->stack_a.tab[0]) ||
			(st->stack_b.tab[nb_move] != get_low(st->stack_b) &&
			 st->stack_b.tab[nb_move] < st->stack_a.tab[0] &&
			 st->stack_b.tab[nb_move + 1] > st->stack_a.tab[0]))
		{
			nb_move++;
			while (nb_move--)
				exec_instr(st, "rb", 1);
			break;
		}
		nb_move++;
	}
}

void	insert_to_b(t_struct *st, int nb_move, char *instr)
{
	//write(1, "b1\n", 3);
	//print_stack(st);
	while (nb_move--)
		exec_instr(st, instr, 1);
	//write(1, "b2\n", 3);
	if (st->stack_b.size > 1 && (get_high(st->stack_b) < st->stack_a.tab[0] || get_low(st->stack_b) > st->stack_a.tab[0]))
		while (get_index(st->stack_b, get_high(st->stack_b)) != 0)
		{
			if (get_index(st->stack_b, get_high(st->stack_b)) <= st->stack_b.size / 2)
				exec_instr(st, "rb", 1);
			if (get_index(st->stack_b, get_high(st->stack_b)) > st->stack_b.size / 2)
				exec_instr(st, "rrb", 1);
		}
	//write(1, "b3\n", 3);
	insert_index(st);
	//print_stack(st);
	//printf("/\\ insert %d\n", st->stack_a.tab[0]);
	exec_instr(st, "pb", 1);
	//write(1, "b4\n", 3);
}

int		insertion_sort(t_struct *st)
{
	int i;
	int nb_move;

	//write(1, "i1\n", 3);
	i = 0;
	st->chunk.size = (int)(0.01 * (double)st->stack_a.size + 6);
	//printf("%d\n", st->chunk.size);
	if (!(st->chunk.tab = (int *)malloc(sizeof(int) * (st->chunk.size + 1))) || !get_median(st))
		return (0);
	//write(1, "i2\n", 3);
	while (++i < st->chunk.size)
	{
		//print_stack(st);
		//printf("chunk : %d | %d\n", st->chunk.tab[i - 1], st->chunk.tab[i]);
		nb_move = 0;
		while (st->stack_a.size > 1 && nb_move < st->stack_a.size)
		{
			if (st->stack_a.tab[nb_move] >= st->chunk.tab[i - 1] && st->stack_a.tab[nb_move] < st->chunk.tab[i])
			{
				insert_to_b(st, nb_move, "ra");
				nb_move = 0;
			}
			else if (nb_move > 0 && st->stack_a.tab[st->stack_a.size - nb_move] >= st->chunk.tab[i - 1] && st->stack_a.tab[st->stack_a.size - nb_move] < st->chunk.tab[i])
			{
				insert_to_b(st, nb_move, "rra");
				nb_move = 0;
			}
			else
				nb_move++;
		}
	}
	//write(1, "i3\n", 3);
	while (get_index(st->stack_b, get_high(st->stack_b)) != 0)
	{
		if (get_index(st->stack_b, get_high(st->stack_b)) <= st->stack_b.size / 2)
			exec_instr(st, "rb", 1);
		if (get_index(st->stack_b, get_high(st->stack_b)) > st->stack_b.size / 2)
			exec_instr(st, "rrb", 1);
	}
	while (st->stack_b.size != 0)
		exec_instr(st, "pa", 1);
	//write(1, "i4\n", 3);
	//print_stack(st);
	return (1);
}
