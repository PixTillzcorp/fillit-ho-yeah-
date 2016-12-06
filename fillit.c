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
#include "../libft/libft.h"

int				main(int argc, char **argv)
{
	int			fd;
	int			i;
	char		**pieces;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file.txt\n");
		return (0);
	}
	i = 0;
	pieces = NULL;
	fd = open(argv[1], O_RDONLY, S_IRUSR);
	if (fd == -1 || !chk_vld_file(&pieces, argv[1], fd))
	{
		ft_putstr_fd("open()/close() failed or the file is not correct.\n", fd);
		return (0);
	}
	while (pieces[i])
	{
		ft_putstr(pieces[i++]);
		ft_putchar('\n');
		if (i % 4 == 0)
			ft_putchar('\n');
	}
	return (0);
}

