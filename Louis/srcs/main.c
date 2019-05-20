/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:27:19 by root              #+#    #+#             */
/*   Updated: 2019/05/20 18:05:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int			win(char a, char b)
{
	if (a == b)
		return (0);
	else if ((a == 'P' && b == 'S') || (a == 'P' && b == 'S'))
		return (1);
	else if (a == 'F' && b == 'P')
		return (0);
	else if (a == 'F' && b == 'S')
		return (0);
		return (1);
}

int		main(void)
{
	char			answer_joep;
	char			answer_luigi;
	int				victory_joep;
	int				victory_luigi;
	int				fd;

	if (ac != 2)
		return (0);
		while (victory_joep + victory_luigi < 11)
		{
				answer_luigi = luig(answer_joep);
				answer_joep = joep(answer_luigi);
				if (answer_luigi == "P")
		}
	return (0);
}
