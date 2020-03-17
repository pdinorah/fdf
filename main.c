/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdinorah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:07:53 by pdinorah          #+#    #+#             */
/*   Updated: 2020/02/28 20:28:39 by pdinorah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	t_param	param;

	if (argc == 2)
	{
		param.fd = open(argv[1], O_RDONLY);
		map_memory(argv[1], param.fd = open(argv[1], O_RDONLY), &param);
		second_parse(&param);
		if ((map_parse(&param, param.fd = open(argv[1], O_RDONLY))))
			return (0);
		param.mlx_ptr = mlx_init();
		param.img_ptr = mlx_new_image(param.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
		param.win_ptr = mlx_new_window(param.mlx_ptr, 1920, 1080, "mlx 42");
		param.img_data = (int *)mlx_get_data_addr(param.img_ptr,
			&(param.bpp), &(param.size_line), &(param.endian));
		draw_background(&param);
		first_move(&param);
		draw_picture(&param, -1, 0);
		mlx_put_image_to_window(param.mlx_ptr,
			param.win_ptr, param.img_ptr, 0, 0);
		mlx_hook(param.win_ptr, 2, 2, &hook_keydown, &param);
		mlx_hook(param.win_ptr, 4, 2, &hook_scroll, &param);
		mlx_loop(param.mlx_ptr);
		mem_delete(&param);
	}
	return (0);
}

int		hook_keydown(int keycode, t_param *param)
{
	if (keycode == 126 || keycode == 125 || keycode == 123 ||
			keycode == 124 || keycode == 53)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		if (keycode == 125)
			rotate_y(param, -0.1);
		if (keycode == 126)
			rotate_y(param, 0.1);
		if (keycode == 123)
			rotate_x(param, 0.1);
		if (keycode == 124)
			rotate_x(param, -0.1);
		if (keycode == 53)
		{
			(void)param;
			exit(0);
		}
		iso(param);
		draw_background(param);
		draw_picture(param, -1, 0);
		mlx_put_image_to_window(param->mlx_ptr,
			param->win_ptr, param->img_ptr, 0, 0);
	}
	return (0);
}

int		hook_scroll(int button, int x, int y, t_param *param)
{
	(void)x;
	(void)y;
	if (button == 4 || button == 5)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		if (button == 4)
			zoom_up(param);
		if (button == 5)
			zoom_down(param);
		iso(param);
		draw_background(param);
		draw_picture(param, -1, 0);
		mlx_put_image_to_window(param->mlx_ptr,
			param->win_ptr, param->img_ptr, 0, 0);
	}
	return (0);
}

void	mem_delete(t_param *param)
{
	free(param->win_ptr);
	free(param->mlx_ptr);
	free(param->img_ptr);
	free(param->img_data);
	free(&param);
}

void 	first_move(t_param *param)
{
	int i;
	int j;

	i = -1;
	while (++i < param->height)
	{
		j = -1;
		while (++j < param->width)
		{
			//param->map[i][j].x_first += 540;
			//param->map[i][j].y_first += 980;
			param->map[i][j].x_end += 540;
			param->map[i][j].y_end += 980;
		}
	}
}