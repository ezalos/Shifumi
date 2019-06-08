/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:27:19 by root              #+#    #+#             */
/*   Updated: 2019/05/21 00:20:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

char			win(char a, char b)
{
	if (a == b)
		return (0);
	else if (a == 'P' && b == 'S')
		return (1);
	else if (a == 'F' && b == 'P')
		return (1);
	else if (a == 'S' && b == 'F')
		return (1);
	else
		return (2);
}

void print_dos(char victory_luigi, char victory_joep, int draw, char tmp)
{
	int shift;
	int lin;
	int col;

	lin = 5;
	col = 80;
	shift = -10;
	ft_rgb_bcolor(48 + shift, 10 + shift, 36 + shift);
	ft_place_cursor(lin++, col);
	ft_printf("%~{?}Louis : %*d", 4, (int)victory_luigi);
	if (tmp == 2 && victory_joep + victory_luigi > 98)
		ft_printf("X");
	else
		ft_printf(" ");
	ft_place_cursor(lin++, col);
	ft_printf("Joep  : %*d", 4, (int)victory_joep);
	if (tmp == 1 && victory_joep + victory_luigi > 98)
		ft_printf("X");
	else
		ft_printf(" ");
	ft_place_cursor(lin, col);
	ft_printf("Draw  : %*d%~{}", 4, (int)draw);
}

void print(char tmp)
{
	char *line;
	int fd;

	ft_place_cursor(0, 0);
	if (tmp == 2)
	{
		ft_printf("%~{255;96;0}");
		fd = open("./display/louis", O_RDONLY);
		while (get_next_line(fd, &line) > 0)
			ft_printf("%s\n", line);
		close(fd);
	}
	else if (tmp == 1)
	{
		ft_printf("%~{155;155;255}");
		fd = open("./display/joep", O_RDONLY);
		while (get_next_line(fd, &line) > 0)
			ft_printf("%s\n", line);
		close(fd);
	}
	else
	{
		ft_printf("%~{255;155;255}");
		fd = open("./display/draw", O_RDONLY);
		while (get_next_line(fd, &line) > 0)
			ft_printf("%s\n", line);
		close(fd);
	}
}

int		main(void)
{
	char			answer_joep = 0;
	char			answer_luigi = 0;
	char			victory_joep = 0;
	char			victory_luigi = 0;
	char			tmp;
	int				draws;

	while (victory_joep + victory_luigi < 99)
	{
			tmp = luigi(answer_joep);
			answer_joep = joep(answer_luigi);
			answer_luigi = tmp;
			tmp = win(answer_joep, answer_luigi);
			if (tmp == 1)
				victory_joep++;
			else if (tmp == 2)
				victory_luigi++;
			else
				draws++;
			print(tmp);
			print_dos(victory_luigi, victory_joep, draws, tmp);
	}
	ft_wait_pls(0);
	ft_wait_pls(0);
	ft_wait_pls(0);
	ft_wait_pls(0);
	ft_wait_pls(0);
	ft_wait_pls(0);
	return (0);
}
