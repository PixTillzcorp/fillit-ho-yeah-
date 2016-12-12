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
	baseshape = lst_from_split(pieces_base);
	lst_input = lst_from_split(pieces);
	// recuperation des coordonnes dans les listes
	// comparaison coordonnees fichier input avec coord fichier base
	// backtracking
	display_grid(pieces);
	return (0);
}
