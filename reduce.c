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

int		empty_line(char *shape, int piece)
{
	int i;
	int empty;
	int line;
	int side;

	i = 0;
	empty = 0;
	side = get_side_shape(shape);
	while (shape[i] && shape[i] != '\n')
	{
		line = 0;
		while (line != side && shape[i] != '\n')
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

int		empty_clmn(char *shape)
{
	int i;
	int side;

	i = 0;
	end_piece = i;
	side = get_side_shape(shape);
	while (shape[i] && shape[i] != '\n' && i < (end_piece + side))
	{
		while (j <= side * 3 && shape[i] != '\n' && i < (end_piece + side))
		{
			if (shape[i + j] == '.')
				j += side;
			else
				i++;
		}
		if (j == side * 4)
			return ((i - end_piece) + 1);
	}
	return (0);
}
