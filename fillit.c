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

int				main(int argc, char **argv)
{
	char		**pieces;

	pieces = NULL;
	if (!chk_input_arg(&pieces, argv[1], argc))
		exit(1);
	// creation des listes chainees
	// recuperation des coordonnes dans les listes
	// comparaison coordonnees fichier input avec coord fichier base
	// backtracking
	display_grid(pieces);
	return (0);
}
