/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdinorah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:00:59 by pdinorah          #+#    #+#             */
/*   Updated: 2020/02/27 15:38:35 by pdinorah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int 	transform_10(char *str)
{
	int		i;
	int		result;
	int 	coeff;

	i = 6;
	coeff = 1;
	result = 0;
	while (str[--i])
	{
		result += coeff * (str[i] + 48);
		coeff *= 16;
	}
	return (result);
}

int		parse_color(char *line)
{
	int		x;
	int		y;
	int 	l;
	char	*color;

	l = -1;
	color = (char *)malloc(sizeof(char) * 6);
	x = 0;
	while (line[x] && line[x] != ',')
		x++;
	if (line[++x] != '0' || !(line[x]))
		return (0);
	if (line[++x] != 'x')
		return (0);
	y = x + 7;
	while (line[++x] && x < y)
	{
		color[++l] = line[x];
	}
	if (x < y)
		return (0);
	return (transform_10(color));
}

void	second_parse(t_param *param)
{
	int		i;
	int		j;
	int		distance;

	distance = (IMG_HEIGHT / param->height / 5);
	i = -1;
	while (++i < param->height)
	{
		j = -1;
		while (++j < param->width)
		{
			param->map[i][j].x_first = (i - param->height / 2) * distance;
			param->map[i][j].y_first = (-1) * (j - param->width / 2) * distance;
			param->map[i][j].x_end = (i - param->width / 2) * distance;
			param->map[i][j].y_end = (j - param->height / 2) * distance;
		}
	}
}

int		map_parse(t_param *param, int fd)
{
	char	*str;
	char	**array;

	param->x1 = 0;
	while (get_next_line(fd, &str) > 0)
	{
		array = ft_strsplit(str, ' ');
		param->x2 = 0;
		param->y1 = -1;
		while (array[++(param->y1)] != NULL)
		{
			if (param->x2 > param->width - 1)
				return (1);
			param->map[param->x1][param->x2].z_first = ft_atoi(array[param->y1]) * 10;
			param->map[param->x1][param->x2].color = parse_color(array[param->y1]);
			param->x2++;
		}
		param->x1++;
		free(str);
		param->y1 = -1;
		while (array[++(param->y1)] != NULL)
			free(array[param->y1]);
		free(array);
	}
	return (0);
}

void	map_memory(char *arg, int fd, t_param *param)
{
	int		i;

	i = 0;
	param->height = line_counter(fd);
	param->map = (t_point **)malloc((param->height) * sizeof(t_point *));
	fd = open(arg, O_RDONLY);
	param->width = point_counter(fd);
	while (i < param->height)
	{
		fd = open(arg, O_RDONLY);
		param->map[i] = (t_point *)malloc((param->width) * sizeof(t_point));
		i++;
	}
}
