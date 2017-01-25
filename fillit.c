/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:18:46 by heinfalt          #+#    #+#             */
/*   Updated: 2016/12/21 12:18:50 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char **input;
	char **base;
	int i;

	i = 0;
	check_arg_nbr(argc);
	input = ft_build(argv[1]);
	base = ft_build("extern_file.txt");
	check_shapes(ft_arraydup(input), ft_arraydup(base));
	input = put_id(input);
	while (input[i])
		printf("%s\n", input[i++]);
	do_map(input);
	exit(1);
}
