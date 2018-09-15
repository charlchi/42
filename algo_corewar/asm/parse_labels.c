/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:13:40 by mgerber           #+#    #+#             */
/*   Updated: 2018/09/12 12:33:53 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

#include <stdio.h>

int			is_label(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	return (str[i - 1] == ':' ? 1 : 0);
}

t_labels	*new_label(char *str, int i)
{
	t_labels	*label;

	label = (t_labels*)malloc(sizeof(t_labels));
	label->name = ft_strdup(str);
	label->index = i;
	label->next = NULL;
	return (label);
}

void		add_label(char *str, int i, t_labels *list)
{
	t_labels	*label;
	t_labels	*head;

	label = new_label(str, i);
	head = list;
	if (list) // this is not supposed to be true if there have been no labels thus far, however I have not been able to get it to do as such
	{
		while (head->next)
			head = head->next;
		head->next = label;
	}
	else
		list = label;
}

int			instruction_val(t_parser *parser, char *str)
{
	int i;

	i = -1;
	while (++i < 17)
		if (ft_strnequ(str, parser->op_tab[i].name, ft_strlen(str)))
			return (parser->op_tab[i].acb ? 2 : 1);
	if (str[0] == 'r')
		return (1);
	if (str[0] == '%')
		return (DIR_SIZE);
	return (IND_SIZE);
}

int			create_labels(t_parser *parser, char *asml, int i, t_labels *list)
{
	char	*r;
	char	**instructions;
	int		j;

	j = 0;
	while ((r = ft_strchr(asml, SEPARATOR_CHAR)))
		*r = ' ';
	instructions = ft_strsplit(asml, ' ');
	while (instructions[j])
	{
		if (is_label(instructions[j]))
			add_label(instructions[j], i, list);
		else
			i += instruction_val(parser, instructions[j]);
		j++;
	}
	free_split(instructions);
	return (i);
}

void		first_pass(t_parser *parser, t_labels *list)
{
	int		i;
	char	*asml;

	i = 0;
	while ((asml = get_asm_line(parser)))
		i = create_labels(parser, asml, i, list);
	//printf("%s\n", list->next->name);		//this skips the first node because the first node remains empty (see comment in add_label) THIS NEEDS TO BE FIXED
	//printf("%d\n", i);
}