/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_redirrect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:55:52 by user42            #+#    #+#             */
/*   Updated: 2021/01/19 11:57:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		redirrect_error(char *elem)
{
	int i;

	i = ft_strlen(elem) - 1;
	while (elem[i] && (elem[i] == ' ' || elem[i] == '<' || elem[i] == '>'))
	{
		if ((elem[i] == '>' || elem[i] == '<') && get_backslash(elem, i) == 0)
		{
			error_output_token(-7, NULL, elem[i]);
			return (-1);
		}
		i--;
	}
	return (0);
}

int		check_redirrect(char *str, int i)
{
	if (str[i] == ' ')
		i++;
	if (str[i] == '\0')
	{
		error_output_token(-4, NULL, '\0');
		return (-1);
	}
	else if (str[i] == '>' || str[i] == '<')
	{
		if (str[i] == '>' && str[i + 1] == '>')
			error_output_token(-7, ">>", str[i]);
		else if (str[i] == '<' && str[i + 1] == '>')
			error_output_token(-7, "<>", str[i]);
		else
			error_output_token(-7, NULL, str[i]);
		return (-1);
	}
	return (0);
}
