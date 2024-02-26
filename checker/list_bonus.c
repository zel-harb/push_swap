/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:40:31 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/26 07:22:45 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*ft_lstnew_bonus(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_bonus(t_list **lst, t_list *new)
{
	t_list	*p;

	if (lst == NULL || new == NULL)
		return ;
	p = *lst;
	if (*lst)
	{
		p = ft_lstlast_bonus(p);
		p->next = new;
	}
	else
		*lst = new;
}

t_list	*ft_lstlast_bonus(t_list *lst)
{
	t_list	*tmp;
	int		size;
	int		i;

	tmp = lst;
	i = 0;
	if (tmp == NULL)
		return (NULL);
	size = ft_lstsize_bonus(tmp);
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

void	ft_lstadd_front_bonus(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize_bonus(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (lst == NULL)
		return (0);
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
