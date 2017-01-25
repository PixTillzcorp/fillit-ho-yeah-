/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:59:29 by heinfalt          #+#    #+#             */
/*   Updated: 2017/01/09 12:59:30 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		do_map(char **input)
{
	char *map;

	map = init_map(input);
	printf("map =     %s\n", map);
	map = solve(input, map);
	printf("%s\n", map);
}

char	*init_map(char **input)
{
	char *map;
	int i;

	i = 0;
	printf("input 0 = %s\n", input[0]);
	map = (char *)ft_memalloc(sizeof(char) * (ft_strlen(input[1]) + 1));
	while (i < ft_strlen(input[1]))
		map[i++] = '.';
	map[i] = '\0';
	return (map);
}

char	*insert_shape(char *shape, char *map, int start)
{
	char *check_1;
	char *check_2;
	int i;
	
	i = 0;
	if (!shape || !map)
		return (NULL);
	check_1 = ft_strdup(shape);
	check_2 = ft_strdup(map);
	while (map[start + i] && shape[i])
	{
		printf("map insert = %s\n", map);
		if (ft_isalpha(shape[i]))
		{
			map[start + i] = shape[i];
			check_2[start + i] = '#';
		}
		else if (check_2[start + i] != '.' && check_2[start + i] != '#')
			check_2[start + i] = '.';
		i++;
	}
	printf("check_2 side increased = %s\n", side_inc(check_2));
	printf("check_1 removed identi = %s\n", remove_id(check_1));
	printf("check_1 side increased = %s\n", side_inc(check_1));
	printf("check_1 trunc_shape = %s\n", trunc_shape(side_inc(check_1)));
	if (ft_strstr(side_inc(check_2), trunc_shape(side_inc(remove_id(check_1)))))
		return (map);
	else
		return (NULL);
}

char	*remove_shape(char *map, int piece)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map[i])
	{
		if (map[i] == (char)(65 + piece))
			map[i] = '.';
		i++;
	}
	return (map);
}

char	*solve(char **input, char *map)
{
	int	*start;
	int piece;
	int i;

	i = 0;
	piece = 0;
	start = (int *)ft_memalloc(sizeof(int) * (get_nbr_shape(input) + 1));
	while (start[i])
		start[i++] = 0;
	while (piece != get_nbr_shape(input) + 1)
	{
		if (insert_shape(input[piece], map, start[piece]))
		{
			printf("condition 1\n");
			map = insert_shape(input[piece], map, start[piece]);
			piece++;
		}
		else
		{
			printf("else 1\n");
			map = remove_shape(map, piece);
			start[piece]++;
			if ((size_t)(start[piece] + ft_strlen(input[piece])) > ft_strlen(map))
			{
				start[piece] = 0;
				if (piece == 0)
				{
					map = side_inc(map);
					input = side_inc_array(input);
				}
				else
					piece--;
			}
		}
	}
	return (map);
}
