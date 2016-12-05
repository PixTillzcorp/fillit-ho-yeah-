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

typedef	struct		s_slot
{
	int				x;
	int				y;
	char			id;
}					t_slot;

typedef	struct		s_tetri
{
	t_slot			case1;
	t_slot			case2;
	t_slot			case3;
	t_slot			case4;
}					t_tetri;

enum 				e_tetriminos
{
	square = 1,
	t_up,
	t_right,
	t_down,
	t_left = 5,
	stick_high,
	stick_low,
	z_low,
	z_high,
	five_low = 10,
	five_high,
	l_down,
	l_right,
	l_up,
	l_left = 15,
	revl_down,
	revl_right,
	revl_up,
	revl_left
};

#endif