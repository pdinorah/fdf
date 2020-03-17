/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdinorah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:23:31 by pdinorah          #+#    #+#             */
/*   Updated: 2020/02/26 21:12:24 by pdinorah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_x(t_param *param, double alpha)
{
	float	previous_y;
	int		i;
	int		j;

	i = -1;
	while (++i < param->height)
	{
		j = -1;
		while (++j < param->width)
		{
			previous_y = param->map[i][j].y_first;
			param->map[i][j].y_first = previous_y * cos(alpha) +
				param->map[i][j].z_first * sin(alpha);
			param->map[i][j].z_first = -previous_y * sin(alpha) +
				param->map[i][j].z_first * cos(alpha);
		}
	}
}

void	rotate_y(t_param *param, double beta)
{
	float	previous_x;
	int		i;
	int		j;

	i = -1;
	while (++i < param->height)
	{
		j = -1;
		while (++j < param->width)
		{
			previous_x = param->map[i][j].x_first;
			param->map[i][j].x_first = previous_x * cos(beta) +
				param->map[i][j].z_first * sin(beta);
			param->map[i][j].z_first = -previous_x * sin(beta) +
				param->map[i][j].z_first * cos(beta);
		}
	}
}

void	iso(t_param *param)
{
	int		previous_x;
	int		previous_y;
	int		i;
	int		j;

	i = -1;
	while (++i < param->height)
	{
		j = -1;
		while (++j < param->width)
		{
			previous_x = param->map[i][j].x_first;
			previous_y = param->map[i][j].y_first;
			param->map[i][j].x_end = (previous_x - previous_y) *
				cos(0.523599) + 540;
			param->map[i][j].y_end = (previous_x + previous_y) *
				sin(0.523599) + 980;
		}
	}
}
