/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:46:03 by mtagemou          #+#    #+#             */
/*   Updated: 2022/11/16 17:52:24 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "keys.h"

# define MAX_WIDTH 800
# define MAX_HEIGHT 800
# define SCALE 0.005
// we define scale (4/MAX_WIDTH) to avoid to recalcul it every time .
# define WHITE	0x00FFFFFF
# define BLACK	0x00000000

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// c = x + yi
typedef struct s_complexe_num
{
	double	x;
	double	y;
}	t_complexe_num;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_vars {
	void					*mlx;
	void					*win;
	struct s_data			*image;
	int						exit_status;
	double					zoom_level;
	int						max_iteration;
	struct s_complexe_num	complexe_num ;
	int						update;
	double					x_offset;
	double					y_offset;
	double					zoom_xoffset;
	double					zoom_yoffset;
	double					x_center;
	double					y_center;
	int						color_cycle;
	void					(*fractal)(struct s_vars *data);
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	map(t_point plan, t_complexe_num *point, t_vars *data,
			double zoom_level);
void	mandelbrot(t_vars *data);
void	julia(t_vars *data);
int		get_color(double n, int color_cycle);
int		key_event(int keycode, t_vars *vars);
int		mouse_event(int button, int x, int y, t_vars *vars);
int		ft_strcmp(char *s1, char *s2);
void	wrong_param(t_vars *vars);
int		ft_exit(t_vars *vars);
int		update_julia(int x, int y, t_vars *vars);
void	ft_putstrnl(char *s);
void	tricorn(t_vars *data);

#endif
