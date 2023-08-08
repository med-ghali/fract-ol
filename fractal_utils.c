/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:22:22 by mtagemou          #+#    #+#             */
/*   Updated: 2022/11/14 10:22:24 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		s1++;
		s2++;
	}	
	return (*s1 - *s2);
}

void	ft_putstrnl(char *s)
{
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
}

void	wrong_param(t_vars *vars)
{
	ft_putstrnl("list of available parameters :");
	ft_putstrnl("1 - mandelbrot");
	ft_putstrnl("2 - julia");
	ft_putstrnl("3 - tricorn");
	vars->exit_status = EXIT_FAILURE;
	ft_exit(vars);
}

int	ft_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, (vars->image)->img);
	exit(vars->exit_status);
}
