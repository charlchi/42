/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:58:46 by cmoller           #+#    #+#             */
/*   Updated: 2018/09/11 12:00:12 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

char	*strip_asm(char **str)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	i = 0;
	j = 0;
	k = 0;
	while ((new = ft_strchr(*str, '\t')))
		*new = ' ';
	while ((*str)[i] == ' ' && (*str)[i] != '\0')
		i++;
	while ((*str)[j] != '#' && (*str)[j] != '\0')
		j++;
	j--;
	if ((*str)[j] == ' ')
		while ((*str)[j] == ' ')
			j--;
	new = (char*)malloc(sizeof(char) * (j - i + 1));
	while (i <= j)
		new[k++] = (*str)[i++];
	new[k] = '\0';
	return (new);
}

void	parse_name(int ifd, int ofd)
{
	char	*asml;
	char	*iline;
	int		i;
	int		j;

	get_next_line(ifd, &iline);
	asml = strip_asm(&iline);
	while (ft_strlen(asml) == 0)
	{
		get_next_line(ifd, &iline);
		asml = strip_asm(&iline);
	}
	if (ft_strlen(iline) < 9 && ft_strncmp(".name", iline, 5) != 0)
		exit (0);
	i = 5;
	while (asml[i] == ' ')
		i++;
	i++;
	j = 0;
	while (asml[i] != '"')
	{
		write(ofd, &asml[i], 1);
		i++;
		j++;
	}
	while (++j <= PROG_NAME_LENGTH)
		write(ofd, "\0", 1);
}

void	parse_comment(int ifd, int ofd)
{
	char	*asml;
	char	*iline;
	int		i;
	int		j;

	get_next_line(ifd, &iline);
	asml = strip_asm(&iline);
	while (ft_strlen(asml) == 0)
	{
		get_next_line(ifd, &iline);
		asml = strip_asm(&iline);
	}
	if (ft_strlen(iline) < 9 && ft_strncmp(".comment", iline, 8) != 0)
		exit (0);
	i = 8;
	while (asml[i] == ' ')
		i++;
	i++;
	j = 0;
	while (asml[i] != '"')
	{
		write(ofd, &asml[i], 1);
		i++;
		j++;
	}
	while (++j <= COMMENT_LENGTH)
		write(ofd, "\0", 1);
}

void	parse_assembly(char *ifile)
{
	char	*ofile;
	int		ifd;
	int		ofd;

	ofile = (char *)malloc(ft_strlen(ifile) + 2);
	ft_strcpy(ofile, ifile);
	// swap out .s for .cor
	ofile[ft_strlen(ifile) - 1] = 'c';
	ofile[ft_strlen(ifile) - 0] = 'o';
	ofile[ft_strlen(ifile) + 1] = 'r';
	ofile[ft_strlen(ifile) + 2] = '\0';
	ifd = open(ifile, O_RDONLY);
	ofd = open(ofile, O_RDWR | O_CREAT, 0666);
	parse_name(ifd, ofd);
	parse_comment(ifd, ofd);
	close(ifd);
	close(ofd);
	//parse_player(ifd, ofd);
}


 
/* "return (0)" are probably either extra features or errors */
int		main(int argc, char **argv)
{
	int		a;
	int		i;

	a = 1;
	while (a < argc)
	{
		if ((i = ft_strlen(argv[a])) < 3
			|| argv[a][i - 1] != 's' || argv[a][i - 2] != '.' )
			return (0);
		parse_assembly(argv[a]);
		a++;
	}
	return (0);
}
