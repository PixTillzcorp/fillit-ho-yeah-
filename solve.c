/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:35:25 by heinfalt          #+#    #+#             */
/*   Updated: 2017/02/20 14:35:27 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*solve(char **input, char **dup, char *map, int *start)
{
	int		piece;

	piece = 0;
	while (piece != get_nbr_shape(input))
	{
		if (check_insert(input[piece], dup[piece], map, start[piece]))
		{
			map = insert_shape(dup[piece], map, start[piece], piece);
			piece++;
		}
		else
		{
			start[piece]++;
			if ((size_t)(start[piece] + ft_strlen(dup[piece])) > ft_strlen(map))
			{
				start[piece] = 0;
				if (piece == 0)
					upper(&input, &dup, &map);
				else
					fall_back(&map, &start, &piece);
			}
		}
	}
	return (map);
}

void		upper(char ***input, char ***dup, char **map)
{
	*map = side_inc(*map);
	*input = side_inc_array(*input);
	*dup = trunc_array(ft_arraydup(*input));
}

void		fall_back(char **map, int **start, int *piece)
{
	*piece -= 1;
	(*start)[*piece]++;
	*map = remove_shape(*map, *piece);
}

char		*clear_map(size_t size)
{
	char	*map;
	size_t	i;

	i = 0;
	map = (char *)ft_memalloc(sizeof(char) * (size + 1));
	while (i < size)
		map[i++] = '.';
	map[i] = '\0';
	return (map);
}
