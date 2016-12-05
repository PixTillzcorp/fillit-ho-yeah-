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

static	int		chk_vld_tetri(char *buf, int end_chk, int index)
{
	int			nbr_hash;
	int			nbr_dots;

	nbr_hash = 0;
	nbr_dots = 0;
	while (index <= end_chk)
	{
		if (!buf[index])
			return (2);
		if (buf[index] != '#' && buf[index] != '.' && buf[index] != '\n')
			return (0);
		if (buf[index] == '#')							//check si on a bien que des "." et "#"
			nbr_hash++;									//et le bon nombre.
		else if (buf[index] == '.')
			nbr_dots++;
		index++;
	}
	if (nbr_hash == 4 && nbr_dots == 12)
		return (1);
	else
		return (0);
}

static	int		chk_vld_file(char ***pieces, char *file, int fd)
{
	char		*buf;
	int			ret;
	int			i;
	int			index;

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
		ret = 0;
		while (ret != 4 && buf[i])
		{
			if (buf[i] == '\n')
				ret++;
			i++;
		}
		if (!chk_vld_tetri(buf, i, index))
			return (0);
		i++;
	}
	*pieces = ft_strsplit(buf, '\n');
	return (1);
}

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
		ft_putstr_fd("open() failed and/or the file is not correct.\n", fd);
		return (0);
	}
	fd = close(fd);
	if (fd == -1)
	{
		ft_putstr_fd("close() failed\n", fd);
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


























