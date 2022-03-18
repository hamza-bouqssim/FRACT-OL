/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:54:46 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/03/11 22:10:06 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	invalid(void)
{
	write(1, "~~~~~~~ FRACT'OL ~~~~~ \n", 26);
	write(1, "                        \n", 26);
	write(1, RED"     Mandelbrot = 1  \n", 30);
	write(1, RED"     Julia = 2       \n", 30);
	write(1, RED"     Burning Ship = 3\n", 30);
	write(1, "                        \n", 26);
	write(1, "~~~~~~~~~~~~~~~~~~~~~~~ \n", 26);
}

void	guide(void)
{
	write(1, GREEN"~~~~~~~~~~|CONTROLS|~~~~~~~~~~\n", 42);
	write(1, "                                        \n", 42);
	write(1, "    ↑  ||  W     : Move Up              \n", 44);
	write(1, "    →  ||  D     : Move Right           \n", 44);
	write(1, "    ↓  ||  S     : Move Down            \n", 44);
	write(1, "    ←  ||  A     : Move Left            \n", 44);
	write(1, "    +            : Increase Iteration   \n", 42);
	write(1, "    -            : Decrease Iteration   \n", 42);
	write(1, "    Scroll UP    : Zoom_In              \n", 42);
	write(1, "    Scroll Down  : Zoom_Out             \n", 42);
	write(1, "    Left Click   : Stop Julia Set       \n", 42);
	write(1, "    C            : Change Color         \n", 42);
	write(1, "    ESC || Q     : QUIT                 \n", 42);
	write(1, "                                        \n", 42);
	write(1, GREEN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 44);
}
