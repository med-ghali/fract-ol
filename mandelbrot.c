/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:22:41 by mtagemou          #+#    #+#             */
/*   Updated: 2022/11/14 10:22:44 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	calc_stability(t_complexe_num *point, int max_iteration, int color_cycle)
{
	int		i;
	double	reel;
	double	img;
	double	imaginary_holder;

	i = 0;
	reel = point->x;
	img = point->y;
	while ((reel * reel + img * img) < 4.0 && i < max_iteration)
	{
		imaginary_holder = img;
		img = (2.0 * reel * img) + point->y;
		reel = (reel * reel) - (imaginary_holder * imaginary_holder) + point->x;
		i++;
	}
	if (i == max_iteration)
		return (BLACK);
	return (get_color((double)i / (double)max_iteration, color_cycle));
}

void	mandelbrot(t_vars *data)
{
	t_complexe_num	point;
	t_point			plan;
	int				color;

	plan.x = -1;
	plan.y = -1;
	while (++plan.x < MAX_WIDTH)
	{
		while (++plan.y < MAX_HEIGHT)
		{
			map(plan, &point, data, data->zoom_level);
			color = calc_stability(&point, data->max_iteration,
					data->color_cycle);
			my_mlx_pixel_put(data->image, plan.x, plan.y, color);
		}
		plan.y = -1;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
}
