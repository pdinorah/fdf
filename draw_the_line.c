/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_the_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdinorah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:37:02 by pdinorah          #+#    #+#             */
/*   Updated: 2020/02/26 22:34:47 by pdinorah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

double percent(int start, int end, int current)
{
	double placement;
	double distance;
	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;
	if (current.color == end.color)
		return (current.color);
	if (delta.x_end > delta.y_end)
		percentage = percent(start.x_end, end.x_end, current.x_end);
	else
		percentage = percent(start.y_end, end.y_end, current.y_end);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	draw_the_line(t_param *param, int error2)
{
	param->deltax = abs(param->x2 - param->x1);
	param->deltay = abs(param->y2 - param->y1);
	param->signx = param->x1 < param->x2 ? 1 : -1;
	param->signy = param->y1 < param->y2 ? 1 : -1;
	param->error = param->deltax - param->deltay;
	if (param->x1 >= 0 && param->y1 >= 0 && param->x1 <
											IMG_WIDTH && param->y1 < IMG_HEIGHT)
		param->img_data[param->y1 * IMG_WIDTH + param->x1] = 0x5100FF;
	while (param->x1 != param->x2 || param->y1 != param->y2)
	{
		if (param->x1 >= 0 && param->y1 >= 0 && param->x1 <
												IMG_WIDTH && param->y1 < IMG_HEIGHT)
			param->img_data[param->y1 * IMG_WIDTH + param->x1] = 0x5100FF;
		error2 = param->error * 2;
		if (error2 > -(param->deltay))
		{
			param->error -= param->deltay;
			param->x1 += param->signx;
		}
		if (error2 < param->deltax)
		{
			param->error += param->deltax;
			param->y1 += param->signy;
		}
	}
}



void	draw_background(t_param *param)
{
	int i;

	i = -1;
	while (++i < IMG_HEIGHT * IMG_WIDTH)
		param->img_data[i] = 0xFFFFFF;
}
