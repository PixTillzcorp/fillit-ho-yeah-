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
#include "../libft/libft.h"

t_list	*ft_lst_create(void)
{
	t_list	**nlst;
	(**nlst).next = ft_lstappend(ft_lstnew(nlst.content));
	return (*nlst);
}