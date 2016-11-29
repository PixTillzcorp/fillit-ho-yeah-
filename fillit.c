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
	if (fd == -1 || !chk_vld_file(argv[1], fd))
	{
		ft_putstr_fd("open() failed and/or the file is not correct.")
		return (0);
	}

}

static	int		chk_vld_file(char *file, int fd)
{
	char *buf;
	int ret;
	int i;
	int index;

	if (fd == -1)
		return (0);
	i = 0;
	index = 0;
	buf = (char *)ft_memalloc(sizeof(char) * BUF_SIZE);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	while (buf[i])
	{
		index = i;
		while (buf[i] != '\n' && buf[i - 1] != '\n')
			i++;
		if (!chk_vld_tetri(buf, i, index))
			return (0);
		i++;
	}
	return (1);
}

static	int		chk_vld_tetri(char *buf, int end_chk, int index)
{
	int i;
	int nbr_hash;
	int nbr_dots;

	i = index;
	nbr_hash = 0;
	while (i++ <= end_chk)
	{
		if (buf[i] != '#' || buf[i] != '.' || buf[i] != '\n')
			return (0);
		if (buf[i] == '#')										//check si on a bien que des "." et "#"
			nbr_hash++;											//et le bon nombre.
		else if (buf[i] == '.')
			nbr_dots++;
	}
	if (i != 22)
		return (0);
	i = index;
	// checker si on a bien des tetriminos.
}
