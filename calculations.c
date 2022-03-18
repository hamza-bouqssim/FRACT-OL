/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:25:07 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/03/11 13:57:31 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_map(double in, double in_end, double out_start, double out_end)
{
	return ((in) * (out_end - out_start) / (in_end) + out_start);
}

void	ft_mapped(t_fractol *data)
{
	data->a = ft_map(data->x, WIN_WIDTH, data->real_start - data->zoom,
			data->real_end + data->zoom);
	data->b = ft_map(data->y, WIN_HEIGHT, data->imaginary_start - data->zoom,
			data->imaginary_end + data->zoom);
	if (data->julia)
	{
		data->c_r = data->a;
		data->c_i = data->b;
	}
}

void	mandelbrot(t_fractol *data)
{
	while (data->iteration < data->max_iteration)
	{
		data->z_r = data->a * data->a - data->b * data->b;
		data->z_i = data->a * data->b * 2;
		if (data->burning_ship)
			data->z_i = fabs(data->a * data->b * 2);
		data->a = data->z_r + data->c_r;
		data->b = data->z_i + data->c_i;
		data->iteration++;
		if (data->a * data ->a + data->b * data->b > 4)
			break ;
	}
}

int	ft_mouse_val(int x, int y, t_fractol *data)
{
	if ((x > 0 && x <= WIN_WIDTH) && (y > 0 && y <= WIN_HEIGHT)
		&& !data->julia_bool)
	{
		data->c_r = ft_map(x, WIN_WIDTH, data->real_start - data->zoom,
				data->real_end + data->zoom);
		data->c_i = ft_map(y, WIN_HEIGHT, data->imaginary_start - data->zoom,
				data->imaginary_end + data->zoom);
		ft_draw(data);
	}
	return (0);
}

int	mouse_hook(int key, int x, int y, t_fractol *data)
{
	double	b_x;
	double	b_y;
	double	a_x;
	double	a_y;

	b_x = ft_map (x, WIN_WIDTH, data->real_start - data->zoom,
			data->real_end + data->zoom);
	b_y = ft_map(y, WIN_HEIGHT, data->imaginary_start - data->zoom,
			data->imaginary_end + data->zoom);
	if (key == 5)
		data->zoom /= 1.1;
	if (key == 4)
		data->zoom *= 1.1;
	if (key == 1)
		data->julia_bool = !data->julia_bool;
	a_x = ft_map (x, WIN_WIDTH, data->real_start - data->zoom,
			data->real_end + data->zoom);
	a_y = ft_map (y, WIN_HEIGHT, data->imaginary_start - data->zoom,
			data->imaginary_end + data->zoom);
	data->real_start += (b_x - a_x);
	data->real_end += (b_x - a_x);
	data->imaginary_start += (b_y - a_y);
	data->imaginary_end += (b_y - a_y);
	ft_draw(data);
	return (0);
}
