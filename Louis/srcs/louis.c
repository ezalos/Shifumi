/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   louis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:51:52 by root              #+#    #+#             */
/*   Updated: 2019/05/20 19:44:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

char luigi(char answer_joep)
{
		static int mem;
		int r_v;

		r_v = ft_random(0, 0, mem + answer_joep, mem);
		mem += r_v;
		if (r_v % 100 > 95)
			return (0);
		r_v %= 3;
		if (!r_v)
			return ('F');
		else if (r_v == 1)
			return ('P');
		else
			return ('S');

}
