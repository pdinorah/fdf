/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdinorah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:34:29 by pdinorah          #+#    #+#             */
/*   Updated: 2020/02/26 22:23:36 by pdinorah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_picture(t_param *param, int i, int j)
{
	while (++i < param->height)
	{
		j = -1;
		while (++j < param->width - 1)
		{
			param->x1 = param->map[i][j][3];
			param->x2 = param->map[i][j + 1][3];
			param->y1 = param->map[i][j][4];
			param->y2 = param->map[i][j + 1][4];
			draw_the_line(param, 0);
		}
	}
	i = -1;
	while (++i < param->height - 1)
	{
		j = -1;
		while (++j < param->width)
		{
			param->x1 = param->map[i][j][3];
			param->x2 = param->map[i + 1][j][3];
			param->y1 = param->map[i][j][4];
			param->y2 = param->map[i + 1][j][4];
			draw_the_line(param, 0);
		}
	}
}

void	zoom_up(t_param *param)
{
	int		i;
	int		j;

	i = -1;
	while (++i < param->height)
	{
		j = -1;
		while (++j < param->width)
		{
			param->map[i][j][0] *= 1.1;
			param->map[i][j][1] *= 1.1;
		}
	}
}

void	zoom_down(t_param *param)
{
	int		i;
	int		j;

	i = -1;
	while (++i < param->height)
	{
		j = -1;
		while (++j < param->width)
		{
			param->map[i][j][0] /= 1.1;
			param->map[i][j][1] /= 1.1;
		}
	}
}
