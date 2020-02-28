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

int		line_counter(int fd)
{
	int		reader;
	char	buff[2];
	int		counter;
	int		check;

	counter = 0;
	check = 0;
	while ((reader = read(fd, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
		{
			counter++;
			check = 1;
		}
		else
			check = 0;
	}
	if (check == 0)
		counter++;
	return (counter);
}

int		point_counter(int fd)
{
	int		reader;
	char	buff[2];
	int		counter;
	int		checker;

	counter = 0;
	checker = 1;
	while ((reader = read(fd, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
			break ;
		if (buff[0] == ' ' && checker == 1)
		{
			counter++;
			checker = 0;
		}
		else if (buff[0] != ' ')
			checker = 1;
	}
	return (counter + 1);
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
			param->map[i][j][0] = (i - param->height / 2) * distance;
			param->map[i][j][1] = (-1) * (j - param->width / 2) * distance;
			param->map[i][j][3] = (i - param->width / 2) * distance;
			param->map[i][j][4] = (j - param->height / 2) * distance;
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
			param->map[param->x1][param->x2][2] =
				ft_atoi(array[param->y1]) * 10;
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
	int		j;
	int		i;

	i = 0;
	param->height = line_counter(fd);
	param->map = (float***)malloc((param->height) * sizeof(float**));
	fd = open(arg, O_RDONLY);
	param->width = point_counter(fd);
	while (i < param->height)
	{
		fd = open(arg, O_RDONLY);
		param->map[i] = (float**)malloc((param->width) * sizeof(float*));
		i++;
	}
	i = 0;
	while (i < param->height)
	{
		j = 0;
		while (j < param->width)
		{
			param->map[i][j] = (float*)malloc(5 * sizeof(float));
			j++;
		}
		i++;
	}
}
