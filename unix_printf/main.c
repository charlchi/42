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
	wchar_t a[10] = L"(\x3b1)ello!";
	wchar_t b = a[1];

	ft_printf("%C gg\n", b);
	printf("%C ff\n", b);
	fflush(0);
	ft_printf("%S gg\n", a);
	printf("%S ff\n", a);
	fflush(0);
	ft_printf("[%-10.20s]g\n", "testtesttesttest");
	printf("[%-10.20s]f\n", "testttesttesttest");
	ft_printf("[%-10.20s]g\n", "test");
	printf("[%-10.20s]f\n", "test");
	ft_printf(" %d HI! %D HI! %d HI! %d HI!\n", 50, 51, 52, 53);
	printf(" %d HI! %d HI! %d HI! %d HI!\n", 50, 51, 52, 53);
	ft_printf("MINE>\t[%-+d]\n", 650);
	printf("ORIG>\t[%-+d]\n", 650);
	return (0);
}
