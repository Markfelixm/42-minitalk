/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:16:18 by marmulle          #+#    #+#             */
/*   Updated: 2022/11/10 16:13:12 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*hold;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		hold = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = hold;
	}
	*lst = NULL;
}
