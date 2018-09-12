/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:13:40 by mgerber           #+#    #+#             */
/*   Updated: 2018/09/12 12:33:53 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"
#include <stdio.h>

void	parse_program(t_parser *parser)
{
	(void)parser;
	
}

void	parse_name(t_parser *parser)
{
	char	*asml;
	char	*iline;
	int		i;
	int		j;

	get_next_line(parser->ifd, &iline);
	asml = strip_asm(&iline);
	while (ft_strlen(asml) == 0)
	{
		get_next_line(parser->ifd, &iline);
		asml = strip_asm(&iline);
	}
	if (ft_strlen(iline) < 9 && ft_strncmp(".name", iline, 5) != 0)
		exit(0);
	i = 5;
	while (asml[i] == ' ')
		i++;
	j = 0;
	write(parser->ofd, "\x00\xea\x83\xf3", 4);
	while (asml[++i] != '"')
	{
		write(parser->ofd, &asml[i], 1);
		j++;
	}
	while (++j <= PROG_NAME_LENGTH - 4)
		write(parser->ofd, "\0", 1);
	write(parser->ofd, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff", 12);
}

void	parse_comment(t_parser *parser)
{
	char	*asml;
	char	*iline;
	int		i;
	int		j;

	get_next_line(parser->ifd, &iline);
	asml = strip_asm(&iline);
	while (ft_strlen(asml) == 0)
	{
		free(iline);
		get_next_line(parser->ifd, &iline);
		asml = strip_asm(&iline);
	}
	if (ft_strlen(iline) < 9 && ft_strncmp(".comment", iline, 8) != 0)
		exit(0);
	i = 8;
	while (asml[i] == ' ')
		i++;
	j = 0;
	while (asml[++i] != '"')
	{
		write(parser->ofd, &asml[i], 1);
		j++;
	}
	while (++j <= COMMENT_LENGTH + 4)
		write(parser->ofd, "\0", 1);
	free(iline);
}

void	parse_assembly(char *ifile)
{
	t_parser	*parser;
	char		*ofile;

	parser = malloc (sizeof(t_parser));
	ofile = (char *)malloc(ft_strlen(ifile) + 2);
	ft_strcpy(ofile, ifile);
	ofile[ft_strlen(ifile) - 1] = 'c';
	ofile[ft_strlen(ifile) - 0] = 'o';
	ofile[ft_strlen(ifile) + 1] = 'r';
	ofile[ft_strlen(ifile) + 2] = '\0';
	parser->ifd = open(ifile, O_RDONLY);
	parser->ofd = open(ofile, O_RDWR | O_CREAT, 0666);
	parse_name(parser);
	parse_comment(parser);
	parse_program(parser);
	free(ofile);
	close(parser->ifd);
	close(parser->ofd);
}
 
/* "return (0)" is probably either extra features or errors */
int		main(int argc, char **argv)
{
	int		a;
	int		i;

	a = 1;
	while (a < argc)
	{
		if ((i = ft_strlen(argv[a])) < 3
			|| argv[a][i - 1] != 's' || argv[a][i - 2] != '.')
			return (0);
		parse_assembly(argv[a]);
		a++;
	}
	return (0);
}