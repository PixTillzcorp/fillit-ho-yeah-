/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:39:55 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/29 11:39:56 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUF_SIZE 1024

typedef	struct			s_slot
{
	int					x;
	int					y;
	char				id;
}						t_slot;

typedef	struct			s_tetri
{
	t_slot				hash_base;
	t_slot				hash_2;
	t_slot				hash_3;
	t_slot				hash_4;
}						t_tetri;

int						chk_vld_tetri(char *buf, int end_chk, int index);
int						chk_vld_file(char ***pieces, char *file, int fd);

#endif
