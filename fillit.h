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
# include "../libft/libft.h"

# define BUF_SIZE 1024

// typedef	struct		s_list
// {
// 	void			*content;
// 	size_t			content_size;
// 	struct s_list	*next;
// }					t_list;

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

static	int				chk_vld_tetri(char *buf, int end_chk, int index);
int						chk_vld_file(char ***pieces, char *file, int fd);
char					**open_n_split(char **splited_buf, char *file);
int						chk_input_arg(char ***pieces, char *file, int argc);
t_list					**recup_coord(t_list **baseshape, char *file);
t_list					**recup_vld_coord(t_list **baseshape);
int						cmp_x_y(t_list *lst1, t_list *lst2, t_list **save_lst2, int check);
t_list					*set_x_y(t_list *lst, int hash, int x, int y);

#endif
