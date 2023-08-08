/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:23:12 by mtagemou          #+#    #+#             */
/*   Updated: 2022/11/16 17:52:46 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	exit_on_failre(t_vars *vars)
{
	vars->exit_status = EXIT_FAILURE;
	ft_exit(vars);
}

void	init_vars(t_vars *vars, t_data *img)
{	
	img->img = NULL;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit_on_failre(vars);
	vars->win = mlx_new_window(vars->mlx, MAX_WIDTH, MAX_HEIGHT, "fractal");
	img->img = mlx_new_image(vars->mlx, MAX_WIDTH, MAX_HEIGHT);
	if (!img->img)
		exit_on_failre(vars);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	vars->zoom_level = 1.0;
	vars->max_iteration = 60;
	vars->image = img;
	vars->update = 1;
	vars->color_cycle = 1;
	vars->x_center = 2;
	vars->y_center = 2;
	vars->x_offset = 0;
	vars->y_offset = 0;
	vars->zoom_xoffset = 0;
	vars->zoom_yoffset = 0;
	vars->exit_status = EXIT_SUCCESS;
}

void	parse_params(int ac, char *av[], t_vars *vars)
{
	if (ac == 2)
	{
		if (!ft_strcmp("julia", av[1]))
		{
			vars->fractal = &julia;
			vars->complexe_num.x = 0;
			vars->complexe_num.y = 0;
			mlx_hook(vars->win, MOTION_NOTIFY, 0, update_julia, vars);
			return ;
		}
		if (!ft_strcmp("mandelbrot", av[1]))
		{
			vars->fractal = &mandelbrot;
			return ;
		}
		if (!ft_strcmp("tricorn", av[1]))
		{
			vars->fractal = &tricorn;
			return ;
		}
	}
	wrong_param(vars);
}

int	main(int ac, char *av[])
{
	t_vars	vars;
	t_data	img;

	init_vars(&vars, &img);
	parse_params(ac, av, &vars);
	vars.fractal(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, ft_exit, &vars);
	mlx_key_hook(vars.win, key_event, &vars);
	mlx_mouse_hook(vars.win, mouse_event, &vars);
	mlx_loop(vars.mlx);
}
