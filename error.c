/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:25:41 by heinfalt          #+#    #+#             */
/*   Updated: 2016/12/08 14:25:42 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		chk_input_arg(char ***pieces, char *file, int argc)
{
	int fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit \"source_file.txt\"\n");
		return (0);
	}
	if (!chk_vld_file(pieces, file, fd))
	{
		ft_putstr_fd("open()/close() failed or the file is not correct.\n", fd);
		return (0);
	}
	
	return (1);
}
