/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:54:49 by user42            #+#    #+#             */
/*   Updated: 2021/01/21 15:19:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** Funcion to check end of line
** minishell> echo | ;
** --> bash: erreur de syntaxe près du symbole inattendu « ; »
** minishell> echo | --> on ne gère pas les multi-lignes
*/

int		check_pipe(char *str, t_quote *quote)
{
	int i;

	i = -1;
	init_quotes(quote, -1, -1);
	while (str[++i])
	{
		if (str[i] == '\'' && (get_backslash(str, i) == 0))
			quote->squote *= -1;
		if (str[i] == '"' && (get_backslash(str, i) == 0))
			quote->dquote *= -1;
		if (quote->squote == -1 && quote->dquote == -1)
		{
			if (str[i] == '|')
			{
				i++;
				while (str[i] == ' ')
					i++;
				if (str[i] == ';')
					return (-1);
				if (str[i] == '\0' || str[i] == '|')
					return (-5);
			}
		}
	}
	return (1);
}
