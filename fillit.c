/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:26:01 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/29 11:26:02 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	int			i;
	char		**pieces;

	i = 0;
	pieces = NULL;
	if (!chk_input_arg(&pieces, argv[1], argc))
		exit(1);
	while (pieces[i])
	{
		ft_putstr(pieces[i++]);
		ft_putchar('\n');
		if (i % 4 == 0)
			ft_putchar('\n');
	}
	return (0);
}

