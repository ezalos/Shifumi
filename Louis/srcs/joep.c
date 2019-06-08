/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:51:49 by root              #+#    #+#             */
/*   Updated: 2019/05/20 19:35:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	*malloco(int size)
{
	char	*out;
	int		i;

	out = (char*)malloc(size);
	i = 0;
	while (i < size)
	{
		out[i] = '\0';
		i++;
	}
}

int		ft_len(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int		randn(int seed)
{
	int	i = (int)clock();
	return((i % 3));
}

char	fighter(char move)
{

		static char	**reaction_win = NULL;
		static char	**reaction_loose = NULL;
		static char	**reaction_tie = NULL;
		static char	**win_loss_history = NULL;
		static char	***history = NULL;
		/*
		if (reaction_win == NULL)
		{
			*reaction_win = (char*)malloc(1800);
			*reaction_loose = (char*)malloc(1800);
			*reaction_tie = (char*)malloc(1800);
			*win_loss_history = (char*)malloc(1800);
			*history = (char**)malloc(2 * sizeof(char*));
			**history = (char*)malloc(1800);
			*(history[1]) = (char*)malloc(1800);
		}
*/
		if (move)
		{
		//	*history[1][ft_len(*history[1])] = move;
		}

		float	w_to_boss;
		float w_to_bitch;
		float w_to_same;

		float	l_to_boss;
		float l_to_bitch;
		float l_to_same;

		float	t_to_boss;
		float t_to_bitch;
		float t_to_same;

		int	rand = randn(1);
		if (rand == 0)
			return ('P');
		if (rand == 1)
			return ('F');
		else
			return ('S');

}


int joep(char move)
{
	return (fighter(move));
}
