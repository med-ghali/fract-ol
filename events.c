/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:22:12 by mtagemou          #+#    #+#             */
/*   Updated: 2022/11/14 10:22:15 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	set_zoom_offset(int x, int y, int operation, t_vars *vars)
{
	t_point			plan;
	t_complexe_num	a;
	t_complexe_num	b;

	plan.x = x;
	plan.y = y;
	map(plan, &a, vars, vars->zoom_level);
	if (operation == 0)
		vars->zoom_level *= 1.0 / 2.0;
	else
		vars->zoom_level *= 1.0 * 2.0;
	map(plan, &b, vars, vars->zoom_level);
	vars->zoom_xoffset += +(a.x - b.x);
	vars->zoom_yoffset += -(a.y - b.y);
}

int	mouse_event(int button, int x, int y, t_vars *vars)
{
	if (button == LEFT_CLICK)
		vars->update *= -1;
	else if (button == SCROOL_DOWN
		&& !(vars->fractal == julia && vars->update == 1))
	{
		set_zoom_offset(x, y, 0, vars);
		vars->max_iteration += 20;
		vars->fractal(vars);
	}
	else if (button == SCROOL_UP
		&& !(vars->fractal == julia && vars->update == 1))
	{
		set_zoom_offset(x, y, 1, vars);
		if (vars->max_iteration > 20)
			vars->max_iteration -= 20;
		vars->fractal(vars);
	}
	return (0);
}

int	extended_key_event(int keycode, t_vars *vars)
{
	if (keycode == G_KEY)
	{
		vars->color_cycle = (vars->color_cycle + 1) % 7;
		vars->fractal(vars);
	}
	else if (keycode == P_KEY)
	{
		vars->max_iteration += 20;
		vars->fractal(vars);
	}
	else if (keycode == O_KEY)
	{
		if (vars->max_iteration > 20)
			vars->max_iteration -= 20;
		vars->fractal(vars);
	}
	return (0);
}

int	key_event(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE_KEY)
		ft_exit(vars);
	else if (keycode == RIGHT_KEY)
	{
		vars->x_offset -= 0.2;
		vars->fractal(vars);
	}
	else if (keycode == UP_KEY)
	{
		vars->y_offset += 0.2;
		vars->fractal(vars);
	}
	else if (keycode == DOWN_KEY)
	{
		vars->y_offset -= 0.2;
		vars->fractal(vars);
	}
	else if (keycode == LEFT_KEY)
	{
		vars->x_offset += 0.2;
		vars->fractal(vars);
	}
	else
		return (extended_key_event(keycode, vars));
	return (0);
}

int	update_julia(int x, int y, t_vars *vars)
{
	t_point	plan;

	plan.x = x;
	plan.y = y;
	if (vars->update == 1)
	{
		vars->zoom_level = 1.0;
		vars->max_iteration = 60;
		vars->x_offset = 0.0;
		vars->y_offset = 0.0;
		vars->zoom_xoffset = 0.0;
		vars->zoom_yoffset = 0.0;
		map(plan, &(vars->complexe_num), vars, vars->zoom_level);
		julia(vars);
	}
	return (0);
}
