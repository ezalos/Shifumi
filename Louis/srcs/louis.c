/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   louis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:51:52 by root              #+#    #+#             */
/*   Updated: 2019/05/20 19:08:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

char luigi(char answer_joep)
{
		int r_v;

		r_v = ft_random(0, 0, answer_joep * 60000, 0);
		r_v %= 3;
		if (!r_v)
			return ('F');
		else if (r_v == 1)
			return ('P');
		else
			return ('S');

}
