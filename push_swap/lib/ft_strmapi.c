/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:12:25 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/09 17:41:15 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnull(void)
{
	char *s;

	s = malloc(1);
	s[0] = 0;
	return (s);
}

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s1;
	int		i;

	i = 0;
	s1 = 0;
	if (s == 0 || f == 0)
		return (ft_strnull());
	while (s[i])
		i++;
	if (!(s1 = malloc(i + 1)))
		return (0);
	i = 0;
	while (s[i])
	{
		s1[i] = f(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
