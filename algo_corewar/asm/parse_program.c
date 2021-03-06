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

#include "assembler.h"

#include <stdio.h>

void	parse_acb(t_parser *parser, char **tokens, int i)
{
	int		j;
	int		opcode;

	opcode = 0;
	j = 0;
	while (j < parser->op_tab[i].nargs)
	{
		if (tokens[j][0] == 'r')
			opcode += (1 << ((3 - j) * 2));
		else if (tokens[j][0] == DIRECT_CHAR)
			opcode += (2 << ((3 - j) * 2));
		else if (tokens[j][0] == LABEL_CHAR)
			opcode += (3 << ((3 - j) * 2));
		j++;
	}
	add_byte(parser, (char)opcode);
	parser->pc++;
}

void	parse_params(t_parser *parser, char **tokens, int i)
{
	int		num;
	int		r;
	int		j;
	int		startpc;

	startpc = parser->pc - 1;
	if (parser->op_tab[i - 1].acb)
		parse_acb(parser, tokens, i);
	j = 0;
	if (i == 1) // live for some reason is special...
	{
		add_bytes(num_to_4bytestr(ft_atoi(&tokens[j][1])), 4);
		return ;
	}
	while (j < parser->op_tab[i - 1].nargs)
	{
		if (tokens[j][0] == 'r')
			add_byte(parser, ft_atoi(&tokens[j][1]));
		else if (tokens[j][0] == DIRECT_CHAR) // direct
		{
			if (tokens[j][1] == LABEL_CHAR) // direct label value
			{
				num = get_label_index(parser->list, &tokens[j][2]);
				num = startpc + ((num < startpc) ? PROGRAM_SIZE - num : num);
				add_bytes(num_to_2bytestr(num), 2);
			}
			else // direct raw number = indirect
			{
				add_bytes(num_to_2bytestr(ft_atoi(&tokens[j][1])), 2);
			}
		}
		else if (tokens[j][0] == LABEL_CHAR) // indirect ???
		{
			add_bytes(num_to_2bytestr(ft_atoi(&tokens[j][1])), 2);
		}
		parser->pc += instruction_val(parser, tokens[j]);
		j++;
	}
}

void	parse_program(t_parser *parser)
{
	char	**tokens;
	char	*r;
	char	*l;
	int		i;
	//int		currentbyte;

	//currentbyte = 0;
	while ((l = get_asm_line(parser)))
	{
		// replace commas with spaces, then string split
		while ((r = ft_strchr(l, SEPARATOR_CHAR)))
			*r = ' ';
		tokens = ft_strsplit(l, ' ');
		if (ft_strchr(tokens[0], ':')) // TODO: don't skip label
			tokens++;
		i = 1;
		while (i < 17)
		{
			if (ft_strncmp(tokens[0], parser->op_tab[i].name,
				ft_strlen(parser->op_tab[i].name)) == 0)
				break ;
			i++;
		}
		add_byte(parser, (char)parser->op_tab[i].id);
		parser->pc++;
		tokens++;
		parse_params(parser, tokens, parser->op_tab[i].id);
	}

	int test = 0;
	while (test <= parser->pos)
	{
		write(parser->ofd, &parser->program[test++], 1);
	}

}

void	parse_name(t_parser *parser)
{
	char	*l;
	int		i;
	int		j;

	l = get_asm_line(parser);
	if (ft_strncmp(".name \"", l, 6) != 0)
		asm_parse_err(parser,
			"Champion .name invalid\nExpected .name \"championname\"\n");
	i = 7;
	j = 0;
	while (l[i] != '"' && l[i])
	{
		add_byte(parser, l[i++]);
		j++;
	}
	if (j == 0 || l[i] != '"')
		asm_parse_err(parser,
			"Champion .name invalid\nExpected .name \"championname\"\n");
	while (++j <= PROG_NAME_LENGTH - 4)
		add_byte(parser, 0);
}

void	parse_comment(t_parser *parser)
{
	char	*l;
	int		i;
	int		j;

	l = get_asm_line(parser);
	if (ft_strncmp(".comment", l, 8) != 0)
		asm_parse_err(parser, "Champion .comment not found");
	i = 8;
	while (l[i] == ' ')
		i++;
	j = 0;
	while (l[++i] != '"')
	{
		add_byte(parser, l[i]);
		j++;
	}
	while (++j <= COMMENT_LENGTH + 4)
		add_byte(parser, 0);
}

void	parse_champion(char *ifile)
{
	t_parser	*parser;
	char		*ofile;
	t_labels	*list;

	parser = (t_parser *)malloc(sizeof(t_parser));
	set_op_tab(parser);
	list = (t_labels*)malloc(sizeof(t_labels));
	ofile = (char *)malloc(ft_strlen(ifile) + 2);
	ft_strcpy(ofile, ifile);
	ft_strcpy(&ofile[ft_strlen(ifile) - 1], "cor");
	if ((parser->ifd = open(ifile, O_RDONLY)) < 0)
		asm_err("Unable to open input file\n");
	if ((parser->ofd = open(ofile, O_RDWR | O_CREAT, 0666)) < 0)
		asm_err("Unable to open output file\n");

	// get rid of name and comment, then get labels
	get_asm_line(parser);
	get_asm_line(parser);
	first_pass(parser, list);
	parser->list = list->next;
	close(parser->ifd);

	// reopen to do the parsing
	if ((parser->ifd = open(ifile, O_RDONLY)) < 0)
		asm_err("Unable to open input file\n");
	parser->line = 0;
	parser->pos = 0;
	parser->pc = 0;
	add_bytes(parser, "\x00\xea\x83\xf3", 4);
	parse_name(parser);
	add_bytes(parser, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff", 12);
	parse_comment(parser);
	parse_program(parser);
	free(ofile);
	free(parser);
	close(parser->ifd);
	close(parser->ofd);
}
