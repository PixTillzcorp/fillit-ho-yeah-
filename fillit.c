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
	char		**pieces_base;
	t_list		**baseshape;
	t_list		**lst_input;

	pieces = NULL;
	if (!chk_input_arg(&pieces, argv[1], argc) &&\
	!chk_input_arg(&pieces_base, "extern_file.txt", argc))
		exit(1);
	// creation des listes chainees a partir des splits
	// recuperation des coordonnes dans les listes
	// comparaison coordonnees fichier input avec coord fichier base
	// backtracking
	display_grid(pieces);
	return (0);
}
