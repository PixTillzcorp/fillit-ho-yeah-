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
#include "../libft/libft.h"

t_list	*recup_vld_coord(t_list **baseshape, int fd)
{
	t_dblbll	index;
	char		**splited_buf;
	char		*buf;
	int			ret;

	index.i = 0;
	index.j = 0;
	fd = open("extern_file.txt", O_RDONLY, S_IRUSR);
	buf = (char *)ft_memalloc(sizeof(char) * BUF_SIZE);
	ret = read(fd, buf, BUF_SIZE);
	splited_buf = ft_strsplit(buf, '\n');
	close(fd);
	buf[ret] = '\0';
	while (splited_buf[index.i])
	{
		while (splited_buf[index.i][index.j])
		{
			if (splited_buf[index.i][index.j] == '#')
			{
				if ((*baseshape)->content.hash_base == NULL)
				{
					(*baseshape)->content.hash_base.x = index.j;
					(*baseshape)->content.hash_base.y = index.i;
				}
				else if ((*baseshape)->content.hash_2 == NULL)
				{
					(*baseshape)->content.hash_2.x = index.j;
					(*baseshape)->content.hash_2.y = index.i;
				}
				else if ((*baseshape)->content.hash_3 == NULL)
				{
					(*baseshape)->content.hash_3.x = index.j;
					(*baseshape)->content.hash_3.y = index.i;
				}
				else if ((*baseshape)->content.hash_4 == NULL)
				{
					(*baseshape)->content.hash_4.x = index.j;
					(*baseshape)->content.hash_4.y = index.i;
				}
				index.j++;
			}
		}
		index.j = 0;
		index.i++;
	}

} 

// void	chk_vld_coord(t_tetri piece, int fd)
// {
// 	t_tetri		check;
// 	char		**grid;
// 	char		*buf;
// 	int			ret;
// 	t_dblbbl	index;

// 	index.i = 0;
// 	index.j = 0;
// 	fd = open("extern_file.txt", O_RDONLY, S_IRUSR);
// 	buf = (char *)ft_memalloc(sizeof(char) * BUF_SIZE);
// 	ret = read(fd, buf, BUF_SIZE);
// 	close(fd);
// 	buf[ret] = '\0';
// 	grid = ft_strsplit(buf, '\n');
// 	while ()
// 	{
// 		while (check.hash_base.y < 5)
// 		{
// 			while (check.hash_base.x < 5)
// 			{
// 				if ()
// 			}
// 			check.hash_base.x = 0;
// 			check.hash_base.y++;
// 		}
// 	}
// }

int		chk_vld_tetri(char *buf, int end_chk, int index)
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
	buf = (char *)ft_memalloc(sizeof(char) * BUF_SIZE);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	while (buf[i])
	{
		index = i;
		ret = 0;
		while (ret != 4 && buf[i])
		{
			if (buf[i++] == '\n')
				ret++;
		}
		if (!chk_vld_tetri(buf, i++, index))
			return (0);
	}
	*pieces = ft_strsplit(buf, '\n');
	return ((close(fd) == -1)? 0 : 1);
}
