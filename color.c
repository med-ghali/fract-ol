/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:22:50 by mtagemou          #+#    #+#             */
/*   Updated: 2022/11/14 10:22:53 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	create_trgb(unsigned char t, unsigned char r,
				unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	get_color(double t, int color_cycle)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (color_cycle == 0)
		return (0x00FFFFFF * t);
	r = (1 - t) * t * t * t * 2295;
	g = (1 - t) * (1 - t) * t * t * 3825 ;
	b = (1 - t) * (1 - t) * (1 - t) * t * 2167.5;
	if (color_cycle == 1)
		return (create_trgb(0, r, g, b));
	if (color_cycle == 2)
		return (create_trgb(0, r, b, g));
	if (color_cycle == 3)
		return (create_trgb(0, b, g, r));
	if (color_cycle == 4)
		return (create_trgb(0, b, r, g));
	if (color_cycle == 5)
		return (create_trgb(0, g, b, r));
	if (color_cycle == 6)
		return (create_trgb(0, g, r, b));
	return (0);
}
