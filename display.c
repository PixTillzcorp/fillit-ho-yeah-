/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:24:34 by heinfalt          #+#    #+#             */
/*   Updated: 2016/12/08 15:24:36 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	display_grid(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		ft_putstr(grid[i++]);
		ft_putchar('\n');
	}
}

int		nbr_tetri(char **splited_buf)
{
	int nbr;

	nbr = 0;
	while (splited_buf[nbr])
		nbr++;
	return ((nbr - 1) / 4);
}
