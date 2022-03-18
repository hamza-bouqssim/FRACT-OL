/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:59:47 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/03/11 21:12:33 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	data;

	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "1"))
			data.julia = 1;
		else if (!ft_strcmp(argv[1], "2"))
			data.julia = 0;
		else if (!ft_strcmp(argv[1], "3"))
		{
			data.burning_ship = 1;
			data.julia = 1;
		}
		else
		{
			invalid();
			exit(1);
		}
		guide();
		calls (&data);
	}
	invalid();
}
