/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:16:46 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/20 15:41:29 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static int	key_action(int key, t_winint *g)
{
	if (key == 53)
		exit(0);
	else if (key >= 123 && key <= 126)
		directions(key, g);
	else if (key >= 0 && key <= 3)
		colors(key, g);
	else if (key == 6 || key == 7)
		zoom(key, g);
	else if (key == 43 || key == 47)
		height_changer(key, g);
	//else if (key == 35)
	//	upview(g);
	return (0);
}

static int	on_destroy_win(void)
{
	exit(0);
	return (0);
}

void	graph_actions(t_winint g)
{
	mlx_hook(g.mlx_win, 2, 1L << 0, key_action, &g);
	mlx_hook(g.mlx_win, 17, 1L << 0, on_destroy_win, &g);
}
