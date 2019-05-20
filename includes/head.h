/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/20 12:34:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H


# define FAILURE				0
# define SUCCESS				1

# define ERROR					-1
# define VALID					0

# define PTR_ERROR			NULL

# define INIT_QANT			1
# define INIT_ROOM			2
# define INIT_LINK			3
# define INIT_SPEC			4

# define RIGHT					0
# define DOWN						1
# define LEFT						2
# define UP							3

# include "../../libft/includes/libft.h"

typedef struct		s_lemin
{
	char						*name;
	int							place;
	int							x_coord;
	int							y_coord;
	int							ants;
	void						**connexions;
	int							from_start;
	int							from_end;
	int							gone;
}									t_lemin;

typedef struct		s_god
{
	t_tab						*lem_in;
	void						***adjacent_matrix;
	t_lemin					*start;
	t_lemin					*end;
	int							size;
}									t_god;

/*
******************************************************************************
**																			**
**								----------									**
**								PROTOTYPES									**
**								----------									**
**																			**
******************************************************************************
*/

/*
**************
**   INIT	**
**************
*/
t_god		*init(int fd);


int		print_matrix(t_tab *lem_in);
int				lets_calcul(t_god *god);

#endif
