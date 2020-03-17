/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdinorah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:37:19 by pdinorah          #+#    #+#             */
/*   Updated: 2020/03/05 20:37:20 by pdinorah         ###   ########.fr       */
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

int		point_counter(int fd){
	int reader;
	char buff[2];
	int counter;
	int checker;

	counter = 0;
	checker = 1;
	while ((reader = read(fd, buff, 1)) > 0) {
		if (buff[0] == '\n')
			break;
		if (buff[0] == ' ' && checker == 1) {
			counter++;
			checker = 0;
		} else if (buff[0] != ' ')
			checker = 1;
	}
	return (counter + 1);
}
