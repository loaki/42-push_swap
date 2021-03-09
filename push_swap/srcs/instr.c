#include "push_swap.h"

static int	ft_instr_cmp(char *line)
{
    //replace strcmp !
	if (!strcmp(line, "sa"))
		return (0);
	else if (!strcmp(line, "sb"))
		return (1);
	else if (!strcmp(line, "ss"))
		return (2);
	else if (!strcmp(line, "pa"))
		return (3);
	else if (!strcmp(line, "pb"))
		return (4);
	else if (!strcmp(line, "ra"))
		return (5);
	else if (!strcmp(line, "rb"))
		return (6);
	else if (!strcmp(line, "rr"))
		return (7);
	else if (!strcmp(line, "rra"))
		return (8);
	else if (!strcmp(line, "rrb"))
		return (9);
	else if (!strcmp(line, "rrr"))
		return (10);
	return (11);
}

static int	check_if_valid_instr(t_struct *st, char buf[], int *index)
{
	int instr_nb;

	buf[*index] = '\0';
	if ((instr_nb = ft_instr_cmp(buf)) == 11)
		return (0);
	//apply_instr(st, instr_nb, 0);
	*index = 0;
	return (1);
}

int			check_instr(t_struct *st)
{
	char	buf[5];
	int		ret;
	int		index;

	index = 0;
	while ((ret = read(0, buf + index, 1)) > 0)
	{
		if (buf[index] != '\n')
		{
			if (index < 3)
				index++;
			else
				return (0);
		}
		else
		{
			if (!check_if_valid_instr(st, buf, &index))
				return (0);
		}
	}
	if (!ret && index > 0 && !check_if_valid_instr(st, buf, &index))
		return (0);
	return (ret == -1 ? 0 : 1);
}