/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:12:24 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/03/11 22:03:50 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <string.h>
# define WIN_HEIGHT 600
# define WIN_WIDTH 600
// KEYS
//--------------------------------------------
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define ESC 53
# define PLUS 69
# define MINES 78
# define C 8
//SOME_COLORS :
//--------------------------------------------
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
//--------------------------------------------
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;
//--------------------------------------------
typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	double	a;
	double	b;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	int		iteration;
	int		color;
	int		color_code;
	int		max_iteration;
	double	real_start;
	double	real_end;
	double	re_origin;
	double	im_origin;
	double	zoom;
	double	imaginary_start;
	double	imaginary_end;
	int		julia;
	int		julia_bool;
	int		burning_ship;
	t_image	img;
}	t_fractol;
// FUNCTIONS :
//--------------------------------------------------------
void	ft_draw(t_fractol *data);
double	ft_map(double in, double in_end, double out_start, double out_end);
void	ft_mapped(t_fractol *data);
void	mandelbrot(t_fractol *data);
int		ft_close(void *param);
int		key_hook(int keycode, void *param);
int		ft_mouse_val(int x, int y, t_fractol *data);
void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
int		ft_strcmp(char *s1, char *s2);
void	calls(t_fractol *data);
int		mouse_hook(int key, int x, int y, t_fractol *data);
void	ft_get_color(t_fractol *data);
void	guide(void);
void	invalid(void);
void	events(t_fractol *data);
#endif
