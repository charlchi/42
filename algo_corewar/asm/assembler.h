/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:39:15 by mgerber           #+#    #+#             */
/*   Updated: 2018/09/13 10:46:29 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include "../libft/libft.h"
# include "op.h"

typedef struct		s_labels
{
	char			*name;
	int				index;
	struct s_labels	*next;
}					t_labels;

void		set_op_tab(t_parser *parser);
int			is_label(char *str);
t_labels	*new_label(char *str, int i);
void		add_label(char *str, int i, t_labels *list);
int			instruction_val(t_parser *parser, char *str);
int			create_labels(t_parser *parser, char *asml, int i, t_labels *list);
int			get_label_index(t_labels *list, char *label);
void		first_pass(t_parser *parser, t_labels *list);
char		*strip_asm(char *str);
char		*get_asm_line(t_parser *parser);
void		add_bytes(t_parser *parser, char *s, int n);
void		add_byte(t_parser *parser, int c);
void		asm_err(char *s);
void		asm_parse_err(t_parser *parser, char *s);
void		parse_acb(t_parser *parser, char **tokens, int i);
void		parse_params(t_parser *parser, char **tokens, int i);
void		parse_program(t_parser *parser);
void		parse_name(t_parser *parser);
void		parse_comment(t_parser *parser);
void		parse_champion(char *ifile);
void		free_split(char **array);

#endif