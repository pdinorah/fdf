/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdinorah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:34:29 by pdinorah          #+#    #+#             */
/*   Updated: 2020/02/28 20:24:39 by pdinorah         ###   ########.fr       */
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
			param->x1 = param->map[i][j].y_end;
			param->x2 = param->map[i][j + 1].y_end;
			param->y1 = param->map[i][j].x_end;
			param->y2 = param->map[i][j + 1].x_end;
			//param->current.color = param->map[i][j].color;
			draw_the_line(param, 0);
		}
	}
	i = -1;
	while (++i < param->height - 1)
	{
		j = -1;
		while (++j < param->width)
		{
			param->x1 = param->map[i][j].y_end;
			param->x2 = param->map[i + 1][j].y_end;
			param->y1 = param->map[i][j].x_end;
			param->y2 = param->map[i + 1][j].x_end;
			//param->current.color = param->map[i][j].color;
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
			param->map[i][j].x_first *= 1.1;
			param->map[i][j].y_first *= 1.1;
			param->map[i][j].z_first *= 1.1;
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
			param->map[i][j].x_first /= 1.1;
			param->map[i][j].y_first /= 1.1;
			param->map[i][j].z_first /= 1.1;
		}
	}
}
