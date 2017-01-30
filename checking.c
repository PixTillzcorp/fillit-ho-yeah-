/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:52:50 by heinfalt          #+#    #+#             */
/*   Updated: 2016/12/21 12:52:51 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_hash_dot(char *shape)
{
	int i;
	int nbr_hash;
	int nbr_dots;

	i = 0;
	nbr_dots = 0;
	nbr_hash = 0;
	while (shape[i])
	{
		if (shape[i] != '#' && shape[i] != '.' && shape[i] != '\n')
			return (0);
		nbr_hash += (shape[i] == '#' ? 1 : 0);
		nbr_dots += (shape[i] == '.' ? 1 : 0);
	}
	if (nbr_dots % 12 != 0 && nbr_hash % 4 != 0)
			return (0);
	return (1);
}

int		check_clmn_line(char *src)
{
	int i;
	int check_line;
	int check_clmn;

	i = 0;
	check_clmn = 0;
	while (src[i])
	{
		check_line = 0;
		while (check_line != 4)
		{
			if (src[i] == '#' || src[i] == '.')
				check_clmn++;
			else if (src[i] == '\n' && check_clmn == 4)
			{
				check_clmn = 0;
				check_line++;
			}
			else
				return (0);
			i++;
		}
		if (src[i] == '\n')
			i++;
	}
	return (1);
}

int		check_shapes(char **input, char **base_shapes)
{
	char **cpy;
	int check;
	int i;
	int j;

 	j = 0;
	check = 0;
 	cpy = side_inc_array(ft_arraydup(input));
 	while (check != 2)
 	{
 		i = 0;
		while (input[i])
		{
			if (!base_shapes[j])
				ft_error();
			else if (ft_strstr(base_shapes[j++], trunc_shape(input[i])))
			{
				i++;
				j = 0;
			}
		}
		input = cpy;
		base_shapes = side_inc_array(base_shapes);
		check++;
	}
	return (1);
}

int		check_insert(char *src, char *shape, char *map, int start)
{
	char *check;
	int i;

	i = 0;
	src++;
	src--;
	check = init_map(ft_strlen(map));
	while (shape[i] && map[start + i])
	{
		if (shape[i] == '#')
		{
			if (map[start + i] != '.')
				return (0);
			else if (map[start + i] == '.')
				check[start + i] = shape[i];
		}
		if ((size_t)(start + ft_strlen(shape)) > ft_strlen(map))
			return (0);
		i++;
	}
	if (ft_strstr(side_inc(src), trunc_shape(side_inc(check))))
	{
		free(check);
		return (1);
	}
	return (0);
}

void	check_arg_nbr(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./a.out source_file.txt\n");
		exit(1);
	}
}
