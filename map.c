/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:23:18 by mtagemou          #+#    #+#             */
/*   Updated: 2022/11/16 17:57:22 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	map(t_point plan, t_complexe_num *point, t_vars *data
			, double zoom_level)
{
	point->x = (((SCALE * plan.x) - (data->x_center + data->x_offset))
			* zoom_level) + data->zoom_xoffset;
	point->y = (((SCALE * plan.y) - (data->y_center + data->y_offset))
			* zoom_level) + data->zoom_yoffset;
	point->y *= -1;
}
