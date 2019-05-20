/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 00:35:56 by root              #+#    #+#             */
/*   Updated: 2019/05/20 14:27:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int				go_through(t_lemin *lem_in, int size, int depth, int dir)
{
		int				i;
		int				r_v;

		r_v = 0;
		if (!lem_in)
			return (0);
		if (dir)
		{
			if (!lem_in->from_start || lem_in->from_start > depth)
			{
				if (!lem_in->gone)
					lem_in->from_start = depth;
				else
				{
					lem_in->from_start = 10000000;
					return (0);
				}
				if (lem_in->place == 1)
					return (1);
				i = -1;
				while (++i < size)
					r_v += go_through(lem_in->connexions[i], size, depth + 1, dir);
			}
		}
		else
			if (!lem_in->from_end || lem_in->from_end > depth)
			{
				if (!lem_in->gone)
					lem_in->from_end = depth;
				else
				{
					lem_in->from_end = 10000000;
					return (0);
				}
				if (lem_in->place == -1)
					return (1);
				i = -1;
				while (++i < size)
					r_v += go_through(lem_in->connexions[i], size, depth + 1, dir);
			}
		return (r_v);
}

int				choose_room(t_lemin *here)
{
	int i;
	int min[2];
	int mon[2];
	int bol;

	i = -1;
	bol = 0;
	mon[0] = 0;
	min[0] = 0;
	min[1] = ((t_lemin*)here->connexions[0])->from_end;
	mon[1] = ((t_lemin*)here->connexions[0])->from_end + ((t_lemin*)here->connexions[0])->from_start;
	while (here->connexions[++i])
	{
		if (((t_lemin*)here->connexions[i])->from_end < min[1] && !((t_lemin*)here->connexions[i])->gone)
		{
			min[1] = ((t_lemin*)here->connexions[i])->from_end;
			min[0] = i;
			bol = 0;
		}
		else if (((t_lemin*)here->connexions[i])->from_end == min[1] && ((t_lemin*)here->connexions[i])->from_end + ((t_lemin*)here->connexions[i])->from_start < mon[1] && !((t_lemin*)here->connexions[i])->gone)
		{
			mon[1] = ((t_lemin*)here->connexions[i])->from_end + ((t_lemin*)here->connexions[i])->from_start;
			mon[0] = i;
			bol = 1;
			i = -1;
		}
	}
	if (bol)
		return (mon[0]);
	else
		return (min[0]);
}

int				choose_room_2(t_lemin *here)
{
	int i;
	int min[2];
	int mon[2];
	int bol;

	i = -1;
	bol = 2;
	mon[0] = 0;
	min[0] = 0;
	min[1] = ((t_lemin*)here->connexions[0])->from_start;
	mon[1] = ((t_lemin*)here->connexions[0])->from_end + ((t_lemin*)here->connexions[0])->from_start;
	while (here->connexions[++i])
	{
		if (((t_lemin*)here->connexions[i])->from_start < min[1] && !((t_lemin*)here->connexions[i])->gone)
		{
			min[1] = ((t_lemin*)here->connexions[i])->from_start;
			min[0] = i;
			bol = 0;
		}
		else if (((t_lemin*)here->connexions[i])->from_start == min[1] && ((t_lemin*)here->connexions[i])->from_end + ((t_lemin*)here->connexions[i])->from_start < mon[1] && !((t_lemin*)here->connexions[i])->gone)
		{
			mon[1] = ((t_lemin*)here->connexions[i])->from_end + ((t_lemin*)here->connexions[i])->from_start;
			mon[0] = i;
			bol = 1;
			i = -1;
		}
	}
	if (bol == 2)
		return (-1);
	else if (bol)
		return (mon[0]);
	else
		return (min[0]);
}

int				go_to_end(t_lemin *here)
{
	if (here->gone)
		return (0);
	else
		here->gone = 1;
	if (here->place == 1)
	{
		ft_printf("%~{155;255;155}");
		ft_printf("\n\n%s\n", here->name);
		return (0);
	}
	else if (here->place == -1)
		ft_printf("%~{255;155;155}");
	else
		ft_printf("%~{}");
	ft_printf("\n\n%s->%d\n", here->name, here->from_end);
	go_to_end(here->connexions[choose_room(here)]);
	return (0);
}

int				go_to_start(t_lemin *here)
{
	int		r_v;
	int		i;

	if (here->gone)
		return (0);
	else
		here->gone = 1;
	if (here->place == 1)
	{
		ft_printf("%~{155;255;155}");
	}
	else if (here->place == -1)
	{
		ft_printf("%~{255;155;155}");
		ft_printf("\n\n%s\n", here->name);
		return (1);
	}
	else
		ft_printf("%~{}");
	ft_printf("\n\n%s->%d\n", here->name, here->from_start);
	r_v = choose_room_2(here);
	i = -1;
	// while (r_v < 0)
	// {
	// 	if (go_to_start(here->connexions[r_v]))
	// 		return (1)
	// 	else if (r_v = choose_room_2(here, ++i) == NO_ANSWER)
	// 		return (0);
	// }
	go_to_start(here->connexions[r_v]);
	return (0);
}

void 		show_nbs(t_god *god)
{
	t_tab		*tmp;
	t_lemin	*here;

	tmp = god->lem_in;
	while (tmp)
	{
		here = tmp->content;
		ft_printf("%~{255;155;155}%s%~{}\t", here->name);
		ft_printf("start: %d\t", here->from_start);
		ft_printf("end: %d\n", here->from_end);
		tmp = tmp->dir[0];
	}
}

int				lets_calcul(t_god *god)
{
	ft_printf("SIZE: %d\n", god->size);
	go_through(god->start, god->size, 0, 1);
	god->start->from_start = 0;
	go_through(god->end, god->size, 0, 0);
	god->end->from_end = 0;
	// show_nbs(god);
	go_to_end(god->start);
	god->start->gone = 0;
	god->end->gone = 0;
	if (go_through(god->start, god->size, 0, 1))
		ft_printf("START to END exist\n");
	god->start->from_start = 0;
	if (go_through(god->end, god->size, 0, 0))
		ft_printf("END to START exist\n");
	god->end->from_end = 0;
	go_to_start(god->end);
	return (0);
}
