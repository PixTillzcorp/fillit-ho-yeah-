/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:24:38 by heinfalt          #+#    #+#             */
/*   Updated: 2017/02/02 16:24:39 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**reduce(char **input)
{
	int		i;
	int		*tab_line;
	int		*tab_clmn;
	int		nbr_shape;

	i = 0;
	nbr_shape = get_nbr_shape(input);
	tab_clmn = (int *)ft_memalloc(sizeof(int) * nbr_shape);
	tab_line = (int *)ft_memalloc(sizeof(int) * nbr_shape);
	while (input[i])
	{
		tab_clmn[i] = empty_clmn(input[i]);
		tab_line[i] = empty_line(input[i]);
		if (!tab_clmn[i] || !tab_line[i])
			return (input);
		i++;
	}
	if (nbr_shape > 2)
		return (input);
	return (side_red(input, tab_line, tab_clmn));
}

char		**side_red(char **input, int *line, int *clmn)
{
	int		tab[3];
	int		side;
	char	**cpy;

	tab[0] = 0;
	cpy = (char **)ft_memalloc(sizeof(char *) * get_nbr_shape(input) + 1);
	while (input[tab[0]])
	{
		tab[1] = 0;
		tab[2] = 0;
		side = get_side_shape(input[tab[0]]);
		cpy[tab[0]] = (char *)ft_memalloc(sizeof(char) * (side - 1)\
		* (side - 1) + 1);
		while (input[tab[0]][tab[1]])
		{
			if (tab[1] % side == clmn[tab[0]] - 1 || (tab[1] >= (side *\
			(line[tab[0]] - 1)) && tab[1] <= (side * line[tab[0]]) - 1))
				tab[1]++;
			else
				cpy[tab[0]][tab[2]++] = input[tab[0]][tab[1]++];
		}
		cpy[tab[0]++][tab[2]] = '\0';
	}
	return (cpy);
}

int			empty_line(char *shape)
{
	int		i;
	int		empty;
	int		line;
	int		side;

	i = 0;
	empty = 0;
	side = get_side_shape(shape);
	while (shape[i])
	{
		line = 0;
		while (line < side && i < (side * side) + 1)
		{
			if (shape[i + line] == '.')
				line++;
			else
			{
				i += side;
				empty++;
			}
		}
		if (line == side)
			return (empty + 1);
	}
	return (0);
}

int			empty_clmn(char *shape)
{
	int		tab[2];
	int		side;
	int		empty;

	tab[0] = 0;
	tab[1] = 0;
	empty = 0;
	side = get_side_shape(shape);
	while (shape[tab[0] + tab[1]] && tab[0] < side)
	{
		if (shape[tab[0] + tab[1]] == '.')
		{
			tab[1] += side;
			empty++;
			if (empty == side)
				return (tab[0] + 1);
		}
		else
		{
			tab[0]++;
			tab[1] = 0;
			empty = 0;
		}
	}
	return (0);
}
