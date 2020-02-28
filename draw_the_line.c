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
