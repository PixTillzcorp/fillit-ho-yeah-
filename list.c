/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:29:15 by heinfalt          #+#    #+#             */
/*   Updated: 2016/12/06 17:29:16 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*set_x_y(t_list *lst, int hash, int x, int y)
{
	if (hash == 0)
	{
		lst->content->hash_base.x = x;
		lst->content->hash_base.y = y;
	}
	else if (hash == 1)
	{
		lst->content->hash_2.x = x;
		lst->content->hash_2.y = y;
	}
	else if (hash == 2)
	{
		lst->content->hash_3.x = x;
		lst->content->hash_3.y = y;
	}
	else if (hash == 3)
	{
		lst->content->hash_4.x = x;
		lst->content->hash_4.y = y;
	}
	return (lst);
}

int		cmp_x_y(t_list *lst1, t_list *lst2, t_list **save_lst2, int check)
{
	while (lst1->next)
	{
		check = 0;
		while (lst2->next)
		{
			if (lst1->content->hash_base.x == lst2->content->hash_base.x &&\
			lst1->content->hash_base.y == lst2->content->hash_base.y)
				check++;
			if (lst1->content->hash_2.x == lst2->content->hash_2.x &&\
			lst1->content->hash_2.y == lst2->content->hash_2.y)
				check++;
			if (lst1->content->hash_3.x == lst2->content->hash_3.x &&\
			lst1->content->hash_3.y == lst2->content->hash_3.y)
				check++;
			if (lst1->content->hash_4.x == lst2->content->hash_4.x &&\
			lst1->content->hash_4.y == lst2->content->hash_4.y)
				check++;
			if (check == 4)
				return (1);
			lst2 = lst2->next;
		}
		lst2 = *save_lst2;
		lst1 = lst1->next;
	}
	return (0);
}

t_list	**lst_from_split(char **splited_buf)
{
	t_list	**save;
	t_list	*nlst;
	int		len;

	len = nbr_tetri(splited_buf);
	nlst = (t_list **)ft_memalloc(sizeof(t_list *) * (len + 1));
	save = &nlst;
	while (nlst->next != NULL)
	{
		nlst = ft_lstappend(nlst, ft_lstnew(NULL, 0));
		nlst = nlst->next;
	}
	return (save);
}

t_list	**recup_coord(t_list **baseshape, char *file)
{
	t_dblbll	index;
	t_list		**save;
	char		**splited_buf;
	int			nbr_hash;

	index.i = 0;
	index.j = 0;
	save = baseshape;
	splited_buf = open_n_split(splited_buf, file);
	while (splited_buf[index.i])
	{
		nbr_hash = 0;
		while (splited_buf[index.i][index.j])
		{
			if (splited_buf[index.i][index.j] = '#')
				*baseshape = set_x_y(*baseshape, nbr_hash++, index.j, index.i);
			index.j++;
		}
		*baseshape = (**baseshape).next;
		index.j = 0;
		index.i++;
	}
	return (save);
}



