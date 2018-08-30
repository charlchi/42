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
	ft_printf("%5%\n");                             // "    %"
	ft_printf("%-5%\n");                            // "%    "
	ft_printf("%10d\n", 42);                        // "        2a"
	ft_printf("%lx\n", 4294967296);                 // "100000000"
	ft_printf("%llX\n", 4294967296);                // "100000000"
	ft_printf("%jx\n", 4294967296);                 // "100000000"
	ft_printf("%jx\n", -4294967296);                // "ffffffff00000000"
	ft_printf("%jx\n", -4294967297);                // "fffffffeffffffff"
	ft_printf("%llx\n", 9223372036854775807);       // "7fffffffffffffff"
	ft_printf("%#llx\n", 9223372036854775807);      // "0x7fffffffffffffff"
	ft_printf("%#x\n", 0);                          // "0"
	ft_printf("%#8x\n", 42);                        // "    0x2a"
	ft_printf("%#08x\n", 42);                       // "0x00002a"
	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);    // "@moulitest:  "
	ft_printf("@moulitest: %.x %.0x\n", 0, 0);      // "@moulitest:  "
	ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);    // "@moulitest:            "
	ft_printf("@moulitest: %s\n", NULL);            // "@moulitest: (null)"
	ft_printf("%.2c\n", NULL);                      // "^@"
	ft_printf("%s %s\n", NULL, "string");             // "(null) string"
	ft_printf("@moulitest: %c\n", 0);               // "@moulitest: ^@"
	ft_printf("%2c\n", 0);                          // " ^@"
	ft_printf("null %c and text\n", 0);             // "null ^@ and text"
	ft_printf("% c\n", 0);                          // "^@"
	ft_printf("%5o\n", 41);                         // "   51"
	ft_printf("%#6o\n", 2500);                      // " 04704"
	ft_printf("%-5.10o\n", 2500);                   // "0000004704"
	ft_printf("%-10.5o\n", 2500);                   // "04704     "
	ft_printf("@moulitest: %.o %.0o\n", 0, 0);      // "@moulitest:  "
	ft_printf("@moulitest: %5.o %5.0o\n", 0, 0);    // "@moulitest:            "
	ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);    // "@moulitest: 0 0"
	ft_printf("@moulitest: %.10o\n", 42);           // "@moulitest: 0000000052"
	ft_printf("% d\n", -42);                        // "-42"
	ft_printf("% +d\n", 42);                        // "+42"
	ft_printf("% +d\n", -42);                       // "-42"
	ft_printf("%+ d\n", 42);                        // "+42"
	ft_printf("%+ d\n", -42);                       // "-42"
	ft_printf("%  +d\n", 42);                       // "+42"
	ft_printf("%  +d\n", -42);                      // "-42"
	ft_printf("%+  d\n", 42);                       // "+42"
	ft_printf("%+  d\n", -42);                      // "-42"
	ft_printf("% ++d\n", 42);                       // "+42"
	ft_printf("% ++d\n", -42);                      // "-42"
	ft_printf("%++ d\n", 42);                       // "+42"
	ft_printf("%5d\n", 42);                         // "   42"
	ft_printf("%5d\n", -42);                        // "  -42"
	ft_printf("%05d\n", -42);                       // "-0042"
	ft_printf("%hd\n", 32767);                      // "32767"
	ft_printf("%hd\n", 32768);                      // "-32768"
	ft_printf("%hhd\n", 128);                       // "-128"
	ft_printf("%hhd\n", -129);                      // "127"
	ft_printf("%lld\n", 9223372036854775807);       // "9223372036854775807"
	ft_printf("%jd\n", 9223372036854775807);        // "9223372036854775807"
	ft_printf("%zd\n", 4294967295);                 // "4294967295"
	ft_printf("%zd\n", 4294967296);                 // "4294967296"
	ft_printf("%4.15d\n", 42);                      // "000000000000042"
	ft_printf("%.10d\n", 4242);                     // "0000004242"
	ft_printf("%10.5d\n", 4242);                    // "     04242"
	ft_printf("%-10.5d\n", 4242);                   // "04242     "
	ft_printf("%03.2d\n", 0);                       // " 00"
	ft_printf("%03.2d\n", 1);                       // " 01"
	ft_printf("%03.2d\n", -1);                      // "-01"
	ft_printf("@moulitest: %.10d\n", -42);          // "@moulitest: -0000000042"
	ft_printf("@moulitest: %.d %.0d\n", 0, 0);      // "@moulitest:  "
	ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);    // "@moulitest:            "
	ft_printf("%u\n", 0);                           // "0"
	ft_printf("%u\n", 1);                           // "1"
	ft_printf("%u\n", -1);                          // "4294967295"
	ft_printf("%u\n", 4294967295);                  // "4294967295"
	ft_printf("%u\n", 4294967296);                  // "0"
	ft_printf("%5u\n", 4294967295);                 // "4294967295"
	ft_printf("%15u\n", 4294967295);                // "     4294967295"
	ft_printf("%-15u\n", 4294967295);               // "4294967295     "
	ft_printf("%015u\n", 4294967295);               // "000004294967295"
	ft_printf("% u\n", 4294967295);                 // "4294967295"
	ft_printf("%+u\n", 4294967295);                 // "4294967295"
	ft_printf("%lu\n", 4294967295);                 // "4294967295"
	ft_printf("%lu\n", 4294967296);                 // "4294967296"
	ft_printf("%llu\n", 4999999999);                // "4999999999"
	ft_printf("%ju\n", 4999999999);                 // "4999999999"
 	ft_printf("%ju\n", 4294967296);                 // "4294967296"
 	ft_printf("%U\n", 4294967295);                  // "4294967295"
 	ft_printf("%hU\n", 4294967296);                 // "4294967296"
 	ft_printf("%U\n", 4294967296);                  // "4294967296"
 	ft_printf("@moulitest: %.5u\n", 42);            // "@moulitest: 00042"

	return (0);
}


