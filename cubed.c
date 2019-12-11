/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:00:04 by cclaude           #+#    #+#             */
/*   Updated: 2019/12/11 18:27:43 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pos(t_all *s)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < s->map.y)
	{
		while (++j < s->map.x)
		{
			c = s->map.tab[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				s->pos.y = (double)i + 0.5;
				s->pos.x = (double)j + 0.5;
				s->dir.x = (c == 'E' || c == 'W') ? 1 : 0;
				s->dir.x *= (c == 'W') ? -1 : 1;
				s->dir.y = (c == 'S' || c == 'N') ? 1 : 0;
				s->dir.y *= (c == 'N') ? -1 : 1;
				return ;
			}
		}
		j = -1;
	}
}

void	ft_init(t_all *s)
{
	ft_parse(s);
	s->mlx.ptr = mlx_init();
	s->win.ptr = mlx_new_window(s->mlx.ptr, s->win.x, s->win.y, "cub3d");
	ft_pos(s);
}

void	ft_cubed(t_all s)
{
	t_map	map;
	t_pos	pos;
	t_dir	dir;

	s.map = map;
	s.pos = pos;
	s.dir = dir;
	ft_init(&s);
	ft_screen(&s);
	mlx_hook(s.win.ptr, 2, 0, ft_key, &s);
	mlx_hook(s.win.ptr, 17, 0, close_window, &s);
	mlx_loop(s.mlx.ptr);
}

int		main(void)
{
	t_all	s;
	t_mlx	mlx;
	t_win	win;
	t_img	img;

	s.mlx = mlx;
	s.win = win;
	s.img = img;
	ft_cubed(s);
	return (0);
}
