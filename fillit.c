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
#include "libft.h"

int				main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file.txt");
		return (0);
	}
	fd = open(argv[1], O_RDONLY, S_IRUSR);
	if (fd == -1 || !chk_vld_file)
	{
		ft_putstr_fd("open() failed or the file is not correct.")
		return (0);
	}
}

static	int		chk_vld_file(char *file)
{

}

static	int		chk_vld_tetri(char *file)
{

}
