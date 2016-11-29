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

# include <sys/strat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <fctnl.h>
# include <unistd.h>

# define BUF_SIZE 1024

typedef	struct		s_slot
{
	int				x;
	int				y;
	char			id;
}					t_slot;

typedef	struct		s_tetri
{
	t_slot case1;
	t_slot case2;
	t_slot case3;
	t_slot case4;
}					t_tetri;

#endif