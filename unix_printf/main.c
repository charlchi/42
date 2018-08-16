/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/20 13:37:36 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int			main(void)
{
	wchar_t a[10] = L"\x3b1\x3b2\x3b1\x3b2\x3b1\x3b2\x3b1\x3b2";
	wchar_t b = a[0];

	setlocale(LC_ALL, "Chinese-simplified");
	ft_printf("[%-10.5C] g\n", b);
	ft_printf("[%-10.5S] g\n", a);
	ft_printf("[%20.10s]\n", "testtesttesttest");
	   printf("[%20.10s]\n\n", "testtesttesttest");
	ft_printf("[%1.20s]\n", "testtesttest");
	   printf("[%1.20s]\n\n", "testtesttest");
	ft_printf("[%1.20s]\n", "testtesttest");
	   printf("[%1.20s]\n\n", "testtesttest");
	ft_printf("[%1.20s]\n", "testtest");
	   printf("[%1.20s]\n\n", "testtest");
	ft_printf("[%1.20s]\n", "testtest");
	   printf("[%1.20s]\n\n", "testtest");
	ft_printf("[%.1s]\n", "test");
	   printf("[%.1s]\n\n", "test");
	ft_printf("[%20.10s]\n", "test");
	   printf("[%20.10s]\n\n", "test");
	ft_printf("[%1.0s]\n", "test");
	   printf("[%1.0s]\n\n", "test");
	ft_printf("[%1.0s]\n", "test");
	   printf("[%1.0s]\n\n", "test");
	ft_printf("%S", L"我是一只猫。\n");
	   printf("%S", L"我是一只猫。\n");
	ft_printf("[%0#x][%#X][%#o][%#O]\n", 15234, 1455, 11252, 53);
	   printf("[%0#x][%#X][%#o][%#O]\n", 15234, 1455, 11252, 53);
	ft_printf("[%0#x][%#X][%#o][%#O]\n", -15234, -1455, -11252, -53);
	   printf("[%0#x][%#X][%#o][%#O]\n", -15234, -1455, -11252, -53);
	ft_printf("[%-+d]\n", 123456);
	   printf("[%-+d]\n\n", 123456);
	ft_printf("[%-#21.17X]\n", 123456);
	   printf("[%-#21.17X]\n\n", 123456);
	ft_printf("[%-#21.17o]\n", 123456);
	   printf("[%-#21.17o]\n\n", 123456);
	ft_printf("[%-+21.17d]\n", 123456);
	   printf("[%-+21.17d]\n\n", 123456);
	ft_printf("[%-+11.17d]\n", 123456);
	   printf("[%-+11.17d]\n\n", 123456);
	ft_printf("[%-+11.17d]\n", 123456);
	   printf("[%-+11.17d]\n\n", 123456);
	ft_printf("[%-+21.17d]\n", 123456);
	   printf("[%-+21.17d]\n\n", 123456);
	ft_printf("[%-+21.17d]\n", 123456);
	   printf("[%-+21.17d]\n\n", 123456);
	ft_printf("[%-+d]\n", 123456);
	   printf("[%-+d]\n\n", 123456);
	ft_printf("[%-#21.3X]\n", 123456);
	   printf("[%-#21.3X]\n\n", 123456);
	ft_printf("[%-#21.3o]\n", 123456);
	   printf("[%-#21.3o]\n\n", 123456);
	ft_printf("[%-21.3d]\n", 123456);
	   printf("[%-21.3d]\n\n", 123456);
	ft_printf("[%-+11.3d]\n", 123456);
	   printf("[%-+11.3d]\n\n", 123456);
	ft_printf("[%-11.3d]\n", 123456);
	   printf("[%-11.3d]\n\n", 123456);
	ft_printf("[%-+21.3d]\n", 123456);
	   printf("[%-+21.3d]\n\n", 123456);
	ft_printf("[%-+21.3d]\n", 123456);
	   printf("[%-+21.3d]\n\n", 123456);
	
	printf("[%-x]   |-\n", 123456);
	printf("[%-#x] |-#\n", 123456);
	printf("[%-+d] |-+\n", 123456);
	printf("[% -d] | -\n", 123456);
	printf("[%-d]  |-\n", 123456);
	printf("[%+-d] |+-\n", 123456);
	printf("[% d] | \n", 123456);
	printf("[%+0d] |+0\n", 123456);
	printf("[% d] | \n", 123456);
	printf("[%0+d] |0+\n", 123456);
	printf("[% d] | \n", 123456);
	printf("[%#x] |#\n", 123456);
	printf("[% 0d] | 0\n", 123456);
	printf("[%0d]  |0\n\n", 123456);

	printf("[%-21.10x] |-21.10\n", 123456);
	printf("[%-#21.10x] |-#21.10\n", 123456);
	printf("[%-+21.10d] |-+21.10\n", 123456);
	printf("[% -21d] | -21\n", 123456);
	printf("[%-21d] |-21\n", 123456);
	printf("[%+-21.10d] |+-21.10\n", 123456);
	printf("[% 21.10d] | 21.10\n", 123456);
	printf("[%+021.10d] |+021.10\n", 123456);
	printf("[% 21.10d] | 21.10\n", 123456);
	printf("[%0+21.10d] |0+21.10\n", 123456);
	printf("[% 21.10d] | 21.10\n", 123456);
	printf("[%#21.10x] |#21.10\n\n", 123456);

	printf("[%-9.2x] |-9.2\n", 123456);
	printf("[%-#9.2x] |-#9.2\n", 123456);
	printf("[%-+9.2d] |-+9.2\n", 123456);
	printf("[% -9d] | -9\n", 123456);
	printf("[%-9d] |-9\n", 123456);
	printf("[%+-9.2d] |+-9.2\n", 123456);
	printf("[% 9.2d] | 9.2\n", 123456);
	printf("[%+09.2d] |+09.2\n", 123456);
	printf("[% 9.2d] | 9.2\n", 123456);
	printf("[%0+9.2d] |0+9.2\n", 123456);
	printf("[% 9.2d] | 9.2\n", 123456);
	printf("[%#9.2x] |#9.2\n\n", 123456);
	printf("[% 09d] | 09\n", 123456);
	printf("[%09d] |09\n\n", 123456);

	return (0);
}


