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

int			main(void)
{
	wchar_t a[10] = L"\x3b1";
	wchar_t b = a[0];

	ft_printf("%C gg\n", b);
	ft_printf("%S gg\n", a);
	ft_printf("[%-10.30s]g\n", "testtesttesttest");
	   printf("[%-10.30s]f\n", "testtesttesttest");
	ft_printf("[%-10.30s]g\n", "test");
	   printf("[%-10.30s]f\n", "test");
	ft_printf("[%-1.1s]g\n", "test");
	   printf("[%-1.1s]f\n", "test");
	ft_printf("[%-1.2s]g\n", "test");
	   printf("[%-1.2s]f\n", "test");
	ft_printf("[%-1.3s]g\n", "test");
	   printf("[%-1.3s]f\n", "test");
	//ft_printf("%S", L"我是一只猫。\n");
	//ft_printf("%S", L"我是一只猫。\n");
	//ft_printf("%S", L"我是一只猫。\n");
	//ft_printf(" %d HI! %D HI! %d HI! %d HI!\n", 50, 51, 52, 53);
	//   printf(" %d HI! %d HI! %d HI! %d HI!\n", 50, 51, 52, 53);
	//ft_printf("MINE>\t[%-+d]\n", 650);
	//   printf("ORIG>\t[%-+d]\n", 650);
	return (0);
}


