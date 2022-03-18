/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:18:54 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/03/10 16:44:03 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_moves(int key, t_fractol *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (key == UP || key == W)
	{
		data->imaginary_end += 0.1 * data->zoom;
		data->imaginary_start += 0.1 * data->zoom;
	}
	if (key == RIGHT || key == D)
	{
		data->real_end -= 0.1 * data->zoom;
		data->real_start -= 0.1 * data->zoom;
	}
	if (key == DOWN || key == S)
	{
		data->imaginary_end -= 0.1 * data->zoom;
		data->imaginary_start -= 0.1 * data->zoom;
	}
	if (key == LEFT || key == A)
	{
		data->real_end += 0.1 * data->zoom;
		data->real_start += 0.1 * data->zoom;
	}
	ft_draw(data);
}

int	key_hook(int keycode, void *param)
{
	t_fractol	*data;

	data = param;
	if (keycode == UP || keycode == RIGHT || keycode == DOWN || keycode == LEFT
		|| keycode == W || keycode == D || keycode == S || keycode == A
		|| keycode == PLUS || keycode == MINES)
		ft_moves(keycode, data);
	if (keycode == ESC || keycode == Q)
		exit(0);
	if (keycode == PLUS && data->max_iteration)
		data->max_iteration += 20;
	if (keycode == MINES && data->max_iteration >= 100)
		data->max_iteration -= 20;
	if (keycode == C)
		ft_get_color(data);
	ft_draw(data);
	return (0);
}

int	ft_close(void *param)
{
	t_fractol	*data;

	data = param;
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x \
			* (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
