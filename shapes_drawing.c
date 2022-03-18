/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:11:47 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/03/11 20:57:34 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw(t_fractol *data)
{
	int	color;

	mlx_clear_window (data->mlx, data->win);
	data->x = 0;
	while (data->x < WIN_WIDTH)
	{
		data->y = 0;
		while (data->y < WIN_HEIGHT)
		{
			ft_mapped (data);
			data->iteration = 0;
			mandelbrot(data);
			color = 0;
			if (data->iteration < data->max_iteration)
				color = data->iteration * data->color;
			my_mlx_pixel_put(data, data->x, data->y, color);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	calls(t_fractol *data)
{
	data->real_start = 0;
	data->real_end = 0;
	data->imaginary_start = 0;
	data->imaginary_end = 0;
	data->max_iteration = 100;
	data->julia_bool = 0;
	data->c_r = 0.285;
	data->c_i = 0;
	data->zoom = 2;
	data->color_code = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	data->img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	ft_draw(data);
	mlx_hook (data->win, 2, 0, key_hook, data);
	mlx_hook (data->win, 17, 0, ft_close, data);
	if (!data->julia)
		mlx_hook (data->win, 6, 0, ft_mouse_val, data);
	mlx_mouse_hook (data->win, mouse_hook, data);
	mlx_loop (data->mlx);
}
