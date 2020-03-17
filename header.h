/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdinorah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:41:18 by pdinorah          #+#    #+#             */
/*   Updated: 2020/02/28 20:26:55 by pdinorah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define IMG_WIDTH 1920
# define IMG_HEIGHT 1080

# include <mlx.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>

typedef struct		s_point
{
float 				x_first;
float 				y_first;
float				z_first;
float 				x_end;
float 				y_end;
int 				color;
}					t_point;

typedef struct		s_param
{
	void			*win_ptr;
	void			*mlx_ptr;
	void			*img_ptr;
	int				fd;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				width;
	int				height;
	int				coeff;
	int				*img_data;
	t_point			**map;
	int				error;
	int				deltax;
	int				deltay;
	int				signx;
	int				signy;
	int				bpp;
	int				size_line;
	int				endian;
	int 			curr_color;
	int				i;
	int 			j;
	t_point 		current;
	t_point 		delta;
	t_point 		end;
}					t_param;

int					point_counter(int fd);
int					map_parse(t_param *param, int fd);
void				second_parse(t_param *param);
int					line_counter(int fd);
void				map_memory(char *arg, int fd, t_param *param);
int					test(t_param param);
void				get_values(t_param *param);
void				draw_the_line(t_param *param, int error2);
void				draw_background(t_param *param);
void				draw_picture(t_param *param, int i, int j);
int					hook_keydown(int keycode, t_param *param);
int					hook_scroll(int button, int x, int y, t_param *param);
void				zoom_down(t_param *param);
void				zoom_up(t_param *param);
void				rotate_x (t_param *param, double alpha);
void				rotate_y (t_param *param, double beta);
void				iso (t_param *param);
void				mem_delete(t_param *param);
int 				transform_10(char *str);
int					parse_color(char *line);
void				get_values(t_param *param);
double				percent(int start, int end, int current);
void 				first_move(t_param *param);

#endif
