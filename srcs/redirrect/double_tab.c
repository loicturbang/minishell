/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:56:04 by user42            #+#    #+#             */
/*   Updated: 2021/01/05 10:56:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**add_str_to_tab(char **tab, char *str)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char *) * (double_tab_size(tab) + 2));
	if (!ret)
		malloc_error();
	while (tab[i] && double_tab_size(tab) > 0)
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	ret[i] = ft_strdup(str);
	ret[++i] = NULL;
	return (ret);
}

void	print_in_out(t_list *lst)
{
	int i;

	i = -1;
	ft_printf("---------FILE PATH OUT-----------\n");
	while ((lst->out)[++i])
	{
		ft_printf("File path OUT: |%s| id: %d\n", (lst->out)[i], i);
		ft_printf("Type OUT: |%s| id: %d\n\n", (lst->out_types)[i], i);
	}
	i = -1;
	ft_printf("---------FILE PATH IN-----------\n");
	while ((lst->in)[++i])
	{
		ft_printf("File path OUT: |%s| id: %d\n", (lst->in)[i], i);
		ft_printf("Type OUT: |%s| id: %d\n\n", (lst->in_types)[i], i);
	}
}
