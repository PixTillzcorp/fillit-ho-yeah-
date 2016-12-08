/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:04:57 by heinfalt          #+#    #+#             */
/*   Updated: 2016/12/06 13:04:58 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**open_n_split(char **splited_buf, char *file)
{
	char *buf;
	int fd;
	int ret;

	fd = open(file, O_RDONLY, S_IRUSR);
	buf = (char *)ft_memalloc(sizeof(char) * BUF_SIZE);
	ret = read(fd, buf, BUF_SIZE);
	splited_buf = ft_strsplit(buf, '\n');
	close(fd);
	buf[ret] = '\0';
	return (splited_buf);
}

static	int		chk_vld_tetri(char *buf, int end_chk, int index)
{
	int			nbr_hash;
	int			nbr_dots;

	nbr_hash = 0;
	nbr_dots = 0;
	while (index <= end_chk)
	{
		if (!buf[index])
			return (-1);
		if (buf[index] != '#' && buf[index] != '.' && buf[index] != '\n')
			return (0);
		nbr_hash += (buf[index] == '#') ? 1 : 0;
		nbr_dots += (buf[index] == '.') ? 1 : 0;
		index++;
	}
	return (((nbr_hash == 4) && (nbr_dots == 12)) ? 1 : 0);
}

int		chk_vld_file(char ***pieces, char *file, int fd)
{
	char		*buf;
	int			ret;
	int			i;
	int			index;

	i = 0;
	index = 0;
	fd = open(file, O_RDONLY, S_IRUSR);
	if (fd == -1)
		return (0);
	buf = (char *)ft_memalloc(sizeof(char) * BUF_SIZE);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	while (buf[i])
	{
		index = i;
		ret = 0;
		while (ret != 4 && buf[i])
			ret += ((buf[i++] == '\n') ? 1 : 0);
		if (!chk_vld_tetri(buf, i++, index))
			return (0);
	}
	*pieces = ft_strsplit(buf, '\n');
	return ((close(fd) == -1)? 0 : 1);
}












